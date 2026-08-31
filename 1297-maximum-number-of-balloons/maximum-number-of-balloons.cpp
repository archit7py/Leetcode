class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string abc = "balloon";
        unordered_map<char,int>a;
        unordered_map<char,int>b;
        int count = INT_MAX;
        for(int i = 0;i<abc.size();i++){
            a[abc[i]]++;
        }
         for(int i = 0;i<text.size();i++){
            b[text[i]]++;
        }
        for(int i = 0;i<abc.size();i++){

            count = min(count,b[abc[i]]/a[abc[i]]);

            
        }
        return count;
        
    }
};