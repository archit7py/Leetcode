class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>a;
        unordered_map<char,int>b;
        int n = ransomNote.size();
        int m = magazine.size();
        int i;
        int j;
        for(i = 0;i<n;i++){
            a[ransomNote[i]]++;
        }
        for(j = 0;j<m;j++){
            b[magazine[j]]++;
        }
        for(int i = 0;i<n;i++){
            if(a[ransomNote[i]]>b[ransomNote[i]]){
                return false;
            }
        }
        return true;
        
        
    }
};