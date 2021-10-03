class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int rep) {
        int n=s.size();
        vector<int> cnt(n,0);
        cnt[n-1]=(s[n-1]==letter);
        for(int i=n-2;i>=0;i--){
            cnt[i]=cnt[i+1]+(s[i]==letter);
        }
        
        vector<deque<int> > ind(26);
        
        for(int i=0;i<n;i++){
            ind[s[i]-'a'].push_back(i);
        }
        
        int x = rep;
        int lastInd = -1;
        string ans="";
        
        for(int i=0;i<k;i++){
            for(int ch=0;ch<26;ch++){
                auto& dq = ind[ch];
                while(dq.size() && dq.front()<=lastInd){
                    dq.pop_front();
                }
                
                if(!dq.size()) continue;
                auto index = dq.front();
                
                if(ans.size()+n-index>=k && cnt[index]>=x && (x-(ch+'a'==letter)+i+1<=k)){
                    ans+=ch+'a';
                    if(ch+'a'==letter) x--;
                    lastInd = index;
                    dq.pop_front();
                    break;
                }
            }
        }
        
        return ans;
    }
};