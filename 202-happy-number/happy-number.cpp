//Loop hoga to number repeat hoga , nhi hoga to number repeat nhi hoga 
class Solution {
public:
     int fun(int n){
            int sum = 0;
            while(n>0){
                int d = n%10;
                n = n / 10;
                sum +=   d*d;
            }
            return sum;
        }
    bool isHappy(int n) {
        unordered_set<int>st;

        while(n!=1){
            if(st.find(n) != st.end()){
                 //Item mil gya (Loop h)
                return false;


            }
            st.insert(n);
            n = fun(n);
        }
        return true;
    }
};