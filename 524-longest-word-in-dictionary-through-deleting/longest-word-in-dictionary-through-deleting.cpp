class Solution {
public:
    static bool cmp(string& a, string& b){
        return (a.size() == b.size())?(a<b):(a.size()>b.size());
    }

    bool solve(string& a, string& b){
        int n = a.size(), m = b.size(); //n>m
        int j = 0;
        for(int i = 0;i<n;i++){
            if(a[i] == b[j]){
                j++;
            }
            if(j==m) break;
        }
        return j==m;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        int n = s.size();
        int m = dictionary.size();
        sort(dictionary.begin(), dictionary.end(), cmp);
        for(auto it: dictionary){
            if(s.size() < it.size()) continue;
            if(solve(s, it)) return it;
        }
        return "";
    }
};