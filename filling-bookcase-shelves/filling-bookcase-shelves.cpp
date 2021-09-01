class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf) {
        int n=books.size();
        int dp[n+1];
        memset(dp,0,sizeof dp);
        
        for(int i=1;i<n+1;i++){
            int ht=books[i-1][1];
            int width = books[i-1][0];
            
            dp[i]=dp[i-1]+ht;
            
            for(int j=i-1;j>0 && books[j-1][0]+width<=shelf;j--){
                ht = max(books[j-1][1], ht);
                width+=books[j-1][0];
                dp[i]=min(dp[i], dp[j-1]+ht);
            }
        }
        return dp[n];
    }
};