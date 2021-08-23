bool cmp(vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);
        int count=1; int j=0;
        // for(auto it: pairs){
        //     cout<<it[0]<<' '<<it[1]<<"\n";
        // }
        for(int i=1;i<n;i++){
            if(pairs[j][1]<pairs[i][0]){
                count++; j=i;
            }
        }
        return count;
    }
};