class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>>res;
       intervals.push_back(newInterval);
       sort(intervals.begin(),intervals.end());
       int start = intervals[0][0];
       int end = intervals[0][1];
       
        for(int i = 1;i<intervals.size();i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            if(end >= start2){
                start = start;
                end = max(end,end2);
                continue;
            }
            res.push_back({start,end});
            start = start2;
            end = end2;
        }
        res.push_back({start,end});
            return res;
        


    }
};