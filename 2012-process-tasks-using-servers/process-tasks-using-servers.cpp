class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > available;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > busy;

        for(int i=0 ;i<servers.size(); i++){
            available.push({servers[i],i});
        }

        vector<int>ans;
        long long time = 0;

        for(int i = 0; i<tasks.size();i++){
            if(time < i){
                time = i;
            }
            while(!busy.empty()&&busy.top().first<=time){
                int idx = busy.top().second;
                busy.pop();
                available.push({servers[idx],idx});
            }
            if(available.empty()){
                time = busy.top().first;
                while(!busy.empty()&&busy.top().first<=time){
                    int idx = busy.top().second;
                    busy.pop();
                    available.push({servers[idx],idx});
                }
            }
            int weight = available.top().first;
            int idx = available.top().second;
            available.pop();
            ans.push_back(idx);
            long long finishTime = time + tasks[i];
            busy.push({finishTime,idx});
        }
        return ans;
        
        
    }
};