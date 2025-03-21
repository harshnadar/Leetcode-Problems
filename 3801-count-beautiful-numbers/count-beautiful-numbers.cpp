class Solution {
public:
    map<string, int> mp;

    int solve(int i, int t, int sum, int product, string& s){
        if(i == s.size()){
            return ((sum>0) && (product%sum==0));
        }

        string key = to_string(i) + "_" + to_string(t) + "_" + to_string(sum) + "_" + to_string(product);
        if(mp.find(key) != mp.end()) return mp[key];

        int ans = 0;
        int limit = (t==1)?(s[i]-'0'):9;

        for(int j=0;j<=limit;j++){
            int updated_product = j*product;
            if(j+sum == 0) updated_product = 1;
            ans += solve(i+1, (t && (limit==j)), sum+j, updated_product, s); 
        }
        return mp[key] = ans;
    }
    int beautifulNumbers(int l, int r) {
        string left = to_string(l-1);
        string right = to_string(r);
        int right_ans = solve(0,1,0,1,right);
        mp.clear();
        int left_ans = solve(0,1,0,1,left);

        return right_ans - left_ans;
    }
};