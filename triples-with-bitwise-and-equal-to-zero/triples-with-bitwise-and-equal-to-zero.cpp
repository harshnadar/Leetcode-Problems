#define f(a,b,i) for(int i=a;i<b;i++)
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        f(0,n,i){
            f(0,n,j){
                mp[nums[i]&nums[j]]++;
            }
        }
        int ans=0;
        f(0,n,i){
            for(auto it:mp){
                if((nums[i]&it.first)==0) ans+=it.second;
            }
        }
        return ans;
    }
};