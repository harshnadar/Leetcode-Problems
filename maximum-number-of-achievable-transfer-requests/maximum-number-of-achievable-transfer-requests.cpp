class Solution {
public:
    int mx=0;
    vector<vector<int> > req;
    int m;
    
    void solve(int ind, vector<int>& count, int num){
        if(ind==m){
            for(auto it: count){
                if(it!=0) return;
            }
            mx = max(mx, num);
            return;
        }
        
        count[req[ind][0]]++;
        count[req[ind][1]]--;
        
        solve(ind+1, count, num+1);
        
        count[req[ind][1]]++;
        count[req[ind][0]]--;
        
        solve(ind+1, count, num);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        this->m = requests.size();
        this->req = requests;
        vector<int> count(n,0);
        
        solve(0,count,0);
        
        return mx;
    }
};