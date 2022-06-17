class Solution {
public:
    int func(vector<int>& a, long long target, int mid){
        return a[mid]>=target;
    }
    
    int solve(vector<int>& a, long long target){
        int n = a.size();
        int lo = 0, hi = n;
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(func(a,target,mid)) hi=mid;
            else lo=mid+1;
        }
        
        return lo;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        
        sort(potions.begin(), potions.end());
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            long long target = (success+spells[i]-1)/spells[i];
            ans.push_back(m-solve(potions, target));
        }
        return ans;
    }
};