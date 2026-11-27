class Solution {
public:
bool valid(int i, int j, int n , int m){
    if(i < 0 || j < 0 || i >= n || j >= m){
        return false;
    }
    return true;
}
void dfs(vector<vector<int>>&mat, int node,  vector<bool>&vis){
    vis[node] = true;
    for(int i = 0; i<mat.size(); i++){
        if(mat[node][i] == 1 && vis[i] == false){
            dfs(mat,i,vis);
        }
    }
    return;
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n,false);
        int provinces = 0;
        for(int i = 0; i<n; i++){
            if(vis[i] == false){
                dfs(isConnected, i, vis);
                provinces++;
            }
        }
        return provinces;


        
    }
};