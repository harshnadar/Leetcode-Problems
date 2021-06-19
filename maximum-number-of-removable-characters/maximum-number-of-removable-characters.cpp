class Solution {
public:
    bool check(string s, string p){
        int j=0;
        int n=s.size(), m=p.size();
        for(int i=0;i<n && j<m;i++){
            if(p[j]==s[i]) j++;
        }
        return (j==m);
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l=0, h=removable.size(), ans=0;
        while(h>=l){
            int mid = l +(h-l)/2;
            string temp=s;
            for(int i=0;i<mid;i++){
                temp[removable[i]]='A';
            }
            if(check(temp,p)) ans=mid, l=mid+1;
            else h=mid-1;
        }
        return ans;
    }
};