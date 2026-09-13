class Solution {
public:
struct cmp{
    bool operator()(pair<int,int>&a , pair<int,int>&b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(int i = 0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = (x*x + y*y);

            pair<int,int>curr = {dist,i};
            if(pq.size()<k){
                pq.push(curr);
            }
            else if(curr.first < pq.top().first){
                pq.pop();
                pq.push(curr);
            }
        }
        vector<vector<int>>res;
        while(!pq.empty()){
            int index = pq.top().second;
            res.push_back(points[index]);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};