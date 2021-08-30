class Solution {
public:
    string checkMax(string s1, string s2){
        if(s1.size()>s2.size()) return s1;
        if(s2.size()>s1.size()) return s2;
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]) continue;
            if(s1[i]>s2[i]) return s1;
            else return s2;
        }
        return "";
    }
    string largestNumber(vector<int>& cost, int target) {
        // int n=cost.size();
        vector<string> dp(target+1,"0");
        dp[target]="";
        
        for(int j=target;j>=0;j--){
            for(int i=0;i<=8;i++){
                if(j+cost[i]<=target && dp[j+cost[i]]!="0"){
                    dp[j]=checkMax(dp[j],dp[j+cost[i]]+to_string(i+1));
                }
            }
        }
        for(int i=1;i<target+1;i++) cout<<dp[i]<<endl;
        if(dp[0]=="0") return "0";
        return dp[0];
    }
};