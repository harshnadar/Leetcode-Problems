class Solution {
public:
    vector<int> nearestSmallToLeft(vector<int>& v){
        vector<int> ans;
        stack<int> s;
        int n=v.size();
        for(int i=0;i<n;i++){
            if(s.size()==0) ans.push_back(-1);
            
            else if(s.size()>0 && v[s.top()]<v[i]){
                ans.push_back(s.top());
            }
            
            else if(s.size()>0 && v[s.top()]>=v[i]){
                while(s.size() && v[s.top()]>=v[i]){
                    s.pop();
                }
                if(s.size()==0) ans.push_back(-1);
                else ans.push_back(s.top());
            }
            s.push(i);
        }
        return ans;
    }
    
    vector<int> nearestSmallToRight(vector<int>& v){
        vector<int> ans;
        stack<int> s;
        int n=v.size();
        for(int i=n-1;i>=0;i--){
            if(s.size()==0) ans.push_back(n);
            
            else if(s.size()>0 &&  v[s.top()]<v[i]){
                ans.push_back(s.top());
            }
            
            else if(s.size()>0 && v[s.top()]>=v[i]){
                while(s.size() && v[s.top()]>=v[i]){
                    s.pop();
                }
                if(s.size()==0) ans.push_back(n);
                else ans.push_back(s.top());
            }
            s.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int> r = nearestSmallToRight(h);
        vector<int> l = nearestSmallToLeft(h);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, (r[i]-l[i]-1)*h[i]);
            // cout<<l[i]<<' '<<r[i]<<endl;
        }
        return ans;
    }
};