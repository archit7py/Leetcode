class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;
        for(int i = 0; i<matrix.size(); i++){
            pq.push({matrix[i][0],i,0});
        }
        int ans = 0;
        while(k>0){
            auto curr = pq.top();
            pq.pop();
            int value = get<0>(curr);
            int row = get<1>(curr);
            int col = get<2>(curr);

            ans = value;
            if(col + 1 < matrix.size()){
                pq.push({matrix[row][col+1],row,col+1});
            }
            k--;
        }
        return ans;
        

        
    }
};