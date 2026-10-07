class Solution {
public:
bool valid(vector<vector<int>>&a, int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m){
        return false;
    }
    return true;
}

void dfs(vector<vector<int>>&a, vector<bool>&vis, int node){
    vis[node] = true;
    for(int i = 0; i<a.size(); i++){
        if(a[node][i] == 1 && vis[i] == 0){
            dfs(a,vis,i);
        }
    }
    return;
    
    
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n,false);
        int provinces  = 0;

        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                dfs(isConnected,vis,i);
                provinces++;
            }
        }
        return provinces;

        
    }
};