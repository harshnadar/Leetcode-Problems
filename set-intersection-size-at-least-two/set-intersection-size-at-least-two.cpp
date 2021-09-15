bool cmp(vector<int>& a, vector<int>& b){
    if(a[1]==b[1]) return a[0]>b[0];
    return a[1]<b[1];
}
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        
        int left=intervals[0][1]-1;
        int right = intervals[0][1];
        int res=2;
        for(int i=1;i<n;i++){
            vector<int> cur = intervals[i];
            if(left<cur[0] && cur[0]<=right){
                res++;
                left=right;
                right=cur[1];
            }
            else if(cur[0]>right){
                res+=2;
                left=cur[1]-1;
                right=cur[1];
            }
        }
        return res;
    }
};