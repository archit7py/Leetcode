class Solution {
public:
struct cmp{
    bool operator()(pair<char,int>&a , pair<char,int>&b){
        if(a.second == b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
        
    }
};
    string reorganizeString(string s) {
        string res = "";
        int seat = 0;
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp>pq;
        unordered_map<char,int>mp;
        for(int i= 0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto i : mp){
            char word = i.first;
            int freq = i.second;
            pair<char,int>p = {word,freq};
            pq.push(p);
        }

        while(!pq.empty()){
            pair<char,int>p1 = pq.top();
            pq.pop();

            if(seat == 0 || res[seat-1] != p1.first){
                res.push_back(p1.first);
                seat++;
                p1.second--;
                if(p1.second > 0){
                    pq.push(p1);

                }
                

            }
            else{
                if(pq.empty()){
                    return "";
                }
                else{
                    pair<char,int>p2 = pq.top();
                    pq.pop();

                    res.push_back(p2.first);
                    seat++;
                    p2.second--;
                    if(p2.second > 0){
                        pq.push(p2);
                    }
                }
                pq.push(p1);
            }
        }
        return res;
        
        
    }
};