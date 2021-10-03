class Solution {
public:
    int getXORSum(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            xor1^=nums1[i];
        }
        
        int xor2 = 0;
        int m=nums2.size();
        
        for(int i=0;i<m;i++){
            xor2^=nums2[i];
        }
        
        return xor1&xor2;
        
    }
};