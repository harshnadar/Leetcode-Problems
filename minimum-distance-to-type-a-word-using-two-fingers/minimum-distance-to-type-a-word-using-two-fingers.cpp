class Solution {
public:
    int dp[27][27][301];
    
    int calc(int from, int to){
        return (from==26 )? 0 : (abs(from/6 - to/6) + abs(from%6 - to%6));
    }
    
    int solve(string& word, int pos, int left, int right){
        if(pos>=word.size()) return 0;
        
        if(dp[left][right][pos]!=-1) return dp[left][right][pos];
        
        auto to = word[pos]-'A';
        dp[left][right][pos] = min(calc(left, to) + solve(word, pos+1, to, right), calc(right, to) + solve(word,pos+1,left, to));
        
        return dp[left][right][pos];
    }
    
    int minimumDistance(string word) {
        int n=word.size();
        if(n==2) return 0;
        memset(dp,-1,sizeof dp);
        
        return solve(word, 0, 26, 26);       
    }
};