class Solution {
public:
    string ans;
    int n;
    static bool cmp(string& a, string& b){
        return (a+b)>(b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto it: nums) v.push_back(to_string(it));
        sort(v.begin(), v.end(), cmp);

        if(v[0] == "0") return "0";

        for(auto it: v) ans+=it;
        return ans;
    }
};