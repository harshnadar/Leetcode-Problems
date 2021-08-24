class Solution {
public:
    
    vector<int> dp;
    string target;
    
    int solve(vector<string>& stickers, int mask){
        if(dp[mask]!=-1) return dp[mask];
        dp[mask]=INT_MAX-1;
        for(auto str: stickers){
            int newMask = mask;
            for(char& ch: str){
                for(int i=0;i<target.size();i++){
                    if(target[i]!=ch || (newMask&(1<<i)) ==0) continue;
                    newMask^=(1<<i);
                    break;
                }
            }
            if(newMask == 0) return dp[mask]=1;
            solve(stickers, newMask);
            if(dp[newMask]+1 < dp[mask]) dp[mask] = 1+dp[newMask];
        }
        return dp[mask];
    }
    
    int minStickers(vector<string>& stickers, string target) {
        int n= target.size();
        int mask = (1<<n);
        dp.resize(mask+1, -1);
        this->target = target;
        int p=solve(stickers, mask-1);
        return ((p>=INT_MAX-10)?-1:p);
    }
};