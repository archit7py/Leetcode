class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>projects;
        priority_queue<int>pq;
        int n = profits.size();
        int idx = 0;
        int i;
        for(int i = 0;i<n;i++){
            projects.push_back({capital[i],profits[i]});
        }
        sort(projects.begin(),projects.end());
        while(k--){
            while(idx < n){
                if(projects[idx].first > w){
                    break;
                }
                pq.push(projects[idx].second);
                idx++;
                
            }
            if(pq.empty()){
                return w;
            }
            else{
                w += pq.top();
                pq.pop();
            }
        }
        return w;
       


    }
};