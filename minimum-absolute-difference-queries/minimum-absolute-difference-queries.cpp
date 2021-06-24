class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<vector<int> > ind(n+1,vector<int>(101,0));
        ind[1][nums[0]]++;
        for(int i=2;i<=n;i++){
            ind[i][nums[i-1]]++;
            for(int j=1;j<101;j++){
                ind[i][j]+=ind[i-1][j];
            }
        }
        vector<int> ans;
        for(auto q: queries){
            int l=q[0], r=q[1];
            l+=1, r+=1;
            vector<int> v;
            for(int i=1;i<=100;i++){
                int x=ind[r][i]-ind[l-1][i];
                if(x) v.push_back(i);
            }
            int mn=INT_MAX;
            if(v.size()==1){ ans.push_back(-1); continue;}
            for(int i=0;i<v.size()-1;i++){
                mn=min(mn, abs(v[i]-v[i+1]));
            }
            ans.push_back(mn);
        }
        return ans;
    }
};