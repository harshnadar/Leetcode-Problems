class Solution {
public:
    int n, m;
    int dp[2002][2002][2];

    int solve(vector<int>& arr, vector<int>& v, int i, int j, int x, int c){
        if(i>=n) return 0;
        j = upper_bound(v.begin()+j, v.end(), x) - v.begin();
        if(dp[i][j][c]!=-1) return dp[i][j][c];
        
        if(j==m && arr[i]<=x) return 1e6;
        int take = 1e6, not_take = 1e6;
        if(j!=m) take = 1+solve(arr, v, i+1, j+1, v[j], 1);
        if(arr[i]>x) not_take = solve(arr, v, i+1, j, arr[i], 0);
        

        return dp[i][j][c] = min(take, not_take);
    }

    int makeArrayIncreasing(vector<int>& arr, vector<int>& arr2) {
        n = arr.size(), m = arr2.size();
        // set<int> s; vector<int> v;
        // for(auto it: arr2) s.insert(it);
        // for(auto it: s) v.push_back(it);
        // m=v.size();
        sort(arr2.begin(), arr2.end());
        memset(dp,-1,sizeof dp);
        int a = solve(arr, arr2, 0,0,-1,0);
        if(a>=1e6) return -1;
        return a;
    }
};

// class Solution {
// public:
//     int solve(int i,int j,int &a,int &b,int p,vector<vector<int>> &dp,vector<int> &v1,vector<int> &v2){
//         if(i==a){
//             return 0;
//         }
//         j = upper_bound(v2.begin()+j,v2.end(),p)-v2.begin();
//         if(dp[i][j] != -1)return dp[i][j];
//         if(j==b && v1[i]<=p)return 2001;
//         int take = 2001,nottake = 2001;
//         if(j!=b)
//         take = solve(i+1,j+1,a,b,v2[j],dp,v1,v2)+1;
//         if(v1[i]>p)
//         nottake = solve(i+1,j,a,b,v1[i],dp,v1,v2);
//         return dp[i][j] = min(take,nottake);
//     }
//     int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
//         int n = arr1.size(),m=arr2.size();
//         vector<vector<int>> dp(2001,vector<int>(2001,-1));
//         sort(arr2.begin(),arr2.end());
//         int a= solve(0,0,n,m,-1,dp,arr1,arr2);
//         if(a>n)return -1;
//         return a;
//     }
// };