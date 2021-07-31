class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        priority_queue<pair<int, char > > pq;
        map<char, int >mp;
        for(char ch: s){
            mp[ch]++;
        }
        for(auto it: mp){
            pq.push({it.second, it.first});
        }
        string ans;
        // while(!pq.empty()){
        //     cout<<pq.top().first<<" "<<pq.top().second<<"\n";
        //     pq.pop();
        // }
        while(!pq.empty()){
            pair<int, char> t1, t2;
            // cout<<pq.size()<<"\n";
            t1 = pq.top();
            // cout<<t1.first<<' '<<t1.second<<"\n";
            pq.pop();
            ans+=t1.second;
            
            // cout<<ans<<" ";
            if(!pq.empty()){
                t2=pq.top();
                pq.pop();
                ans+=t2.second;
                // cout<<ans<<"\n";
                if(t2.first>1) pq.push({t2.first-1, t2.second});
            }
            
            if(t1.first >1) pq.push({t1.first-1, t1.second});
        }
        for(int i=1;i<n;i++){
            if(ans[i]==ans[i-1]) return "";
        }
        return ans;
    }
};