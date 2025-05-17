class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int count = n-1;
        vector<int> ans;
        ans.push_back(1);
        bool flag = true;
        while(k>1){
            int add = flag?1:-1;
            ans.push_back(ans[ans.size() - 1] + add*count);
            count--;
            flag ^= true;
            k--;
        }
        while(ans.size()!=n){
            int add = flag?1:-1;
            ans.push_back(ans[ans.size()-1] + add);
        }
        return ans;
    }
};