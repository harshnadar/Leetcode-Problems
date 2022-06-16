class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        long long int count = 0;
        unordered_set<string> st[26];
        for(auto it: ideas){
            st[it[0]-'a'].insert(it.substr(1));
        }
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                long long int c1= 0, c2 =0;
                for(auto it: st[i]){
                    if(!st[j].count(it)){
                        c1++;
                    }
                }
                for(auto it: st[j]){
                    if(!st[i].count(it)){
                        c2++;
                    }
                }
                count += c1*c2;
            }
        }
        return count*2;
    }
};