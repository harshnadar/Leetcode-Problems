class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jump=1;
        if(n==0 || n==1) return 0;
        if(n>1 && nums[0]==0) return -1;
        int steps=nums[0], max_jump=nums[0];
        for(int i=1;i<n;i++){
            if(i==n-1) return jump;
            max_jump=max(max_jump, i+nums[i]);
            steps--;
            while(steps==0){
                if(max_jump<=1) return -1;
                steps=max_jump-i;
                jump++;
            }
        }
        return -1;
    }
};