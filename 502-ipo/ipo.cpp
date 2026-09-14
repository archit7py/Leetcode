class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>pq;
        int n = profits.size();
        vector<pair<int,int>>projects;
        int idx = 0;
        int i;
        for(i=0;i<n;i++){
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
                w = w + pq.top();
                pq.pop();

            }

        }
        return w;
        
    }
};