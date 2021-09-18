class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int lo=1;
        int hi=1e9;
        int ans=0;
        while(lo<hi){
            int mid= (lo+hi)/2;
            int day=1;
            int wt=0;
            int sum=0;
            for(int j=0;j<n;j++){
                if(weights[j]>mid) {day=1e6; break;}
                sum+=weights[j];
                if(sum>mid){
                    sum = weights[j];
                    // j--;
                    day++;
                }
            }
            if(day>days){
                lo = mid+1;
                // ans=mid;
            }
            else{
                hi = mid;
            }
        }
        return lo;
    }
};