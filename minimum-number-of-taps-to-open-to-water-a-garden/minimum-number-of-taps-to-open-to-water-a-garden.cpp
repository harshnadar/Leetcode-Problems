class Solution {
public:
    int minTaps(int n, vector<int>& range) {
        int mx=0,mn=0,open=0;
        // int n=ranges.size();
        while(mx<n){
            for(int i=0;i<n+1;i++){
                if(mn>=i-range[i] && mx<i+range[i]){
                    mx=range[i]+i;
                }
            }
            if(mn==mx) return -1;
            mn=mx;
            open++;
        }
        return open;
    }
};