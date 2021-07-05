class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int i;
        stack<int> s;
        
        for(i=0;i<nums.size();i++)
        {
            if(s.size()==0)
                s.push(nums[i]);
            
            else if(s.size()>0)
            {
                if(nums[i]>=s.top() && s.size()<k)
                    s.push(nums[i]);
                
                else if(nums[i]<s.top())
                {
                    while(s.size()>0 && nums[i]<s.top() && ((s.size()-1)+(nums.size()-i))>=k)
                        s.pop();
                    s.push(nums[i]);
                }
                
            }
        }
        
        vector<int> ans;
        
        while(s.size()>0)
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};