class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontal, vector<int>& vertical) {
        int mod=1e9+7;
        sort(horizontal.begin(), horizontal.end());
        sort(vertical.begin(), vertical.end());
        long long int mv=horizontal[0]; int mh=vertical[0];
        
        for(int i=1;i<horizontal.size()+1;i++){
            if(i!=horizontal.size()){
                mv=max(horizontal[i]-horizontal[i-1], (int)mv);
            }
            else{
                mv=max(h-horizontal[i-1], (int)mv);
            }
            cout<<"mv "<<mv<<"\n";
        }
        for(int i=1;i<vertical.size()+1;i++){
            if(i!=vertical.size()){
                mh=max(vertical[i]-vertical[i-1],(int)mh);
            }
            else{
                mh=max(w-vertical[i-1], (int)mh);
            }
            cout<<mh<<"\n";
        }
        // cout<<mh<<" "<<mv<<'\n';
        int ans = ((mv%mod)*(mh%mod))%mod;
        return ans;
    }
};