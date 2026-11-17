class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });
        priority_queue<int>pq;
        int count = 0;
        int TotalTime = 0;
        for(int i = 0; i<courses.size(); i++){
            TotalTime += courses[i][0];
            pq.push(courses[i][0]);
            if(TotalTime > courses[i][1]){
                TotalTime -= pq.top();
                pq.pop();
                
            }
        }
        return pq.size();

    }
};