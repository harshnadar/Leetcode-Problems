class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size();
        int total=words.size() * words[0].size();
        int size= words.size();
        unordered_map<string, int> mp;
        vector<int> v;
        
        for(int i=0;i<size;i++){
            mp[words[i]]++;
        }
        for(int i=0;i<n-total+1;i++){
            unordered_map<string, int> tmp;
            int count=0;
            for(int j=i;j<total+i;j+=words[0].size()){
                string t=s.substr(j,words[0].size());
                int var=tmp[t]++;
                var+=1;
                int mvar=mp[t];
                if(mvar!=0 && var<=mvar){
                    count++;
                }
                else{
                    count=0; break;
                }
            }
            if(count==size) v.push_back(i);
        }
        return v;
    }
};