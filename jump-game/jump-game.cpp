class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1) return true;
        if(n>1 && nums[0]==0) return false;
        int jump=1;
        int steps=nums[0], max_jump=nums[0];
        for(int i=1;i<n;i++){
            if(i==n-1) return true;
            max_jump=max(max_jump, i+nums[i]);
            steps--;
            while(steps==0){
                if(max_jump<=1) return false;
                steps=max_jump-i;
                jump++;
                if(jump>n+2) return false;
            }
        }
        return false;
    }
};