class Solution {
public:
    struct mycompare{
        bool operator()(vector<int> a, vector<int> b){
            return a[0]+a[1]>b[0]+b[1];
        }
    };
    vector<int> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k=200) {
        priority_queue<vector<int>, vector<vector<int> >, mycompare> pq;
        vector<vector<int> > res;
        
        int n=nums1.size(), m=nums2.size();
        
        if(n==0 || m==0 || k==0) return vector<int>();
        
        for(int i=0; i<n && i<k; i++) pq.push({nums1[i], nums2[0],0});
        
        while(k-- && !pq.empty()){
            vector<int> cur = pq.top();
            
            pq.pop();
            res.push_back({cur[0], cur[1]});
            
            if(cur[2]==m-1) continue;
            
            pq.push({cur[0], nums2[cur[2]+1], cur[2]+1});
        }
        vector<int> ans;
        for(auto it: res){
            ans.push_back(it[0]+it[1]);
        }
        return ans;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> res = mat[0];
        int n=mat.size();
        for(int i=1;i<n;i++){
            vector<int> nums = mat[i];
            res = kSmallestPairs(res,nums);
        }
        return res[k-1];
    }
};