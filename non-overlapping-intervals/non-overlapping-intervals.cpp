bool cmp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
}

class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        int n= in.size();
        sort(in.begin(), in.end(),cmp);
        int count=0,j=0;
        for(int i=1;i<n;i++){
            if(in[j][1]>in[i][0]){
                count++;
            }
            else j=i;
        }
        return count;
    }
};