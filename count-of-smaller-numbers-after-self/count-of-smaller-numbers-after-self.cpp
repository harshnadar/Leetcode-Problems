class Solution {
public:
    long long int tree[400002], a[100002];
    
    long long int query(int node, int start, int end, int l, int r){
        if(start>r || end<l) return 0;
        if(l<=start && end<=r) return tree[node];
        int mid = start+(end-start)/2;
        int p1 = query(2*node+1,start, mid, l,r);
        int p2 = query(2*node+2, mid+1, end, l,r);
        
        return tree[node]=(p1+p2);
    }
    
    void update(int node, int start, int end, int idx, int val){
        if(start==end){
            a[idx]+=val;
            tree[node]+=val;
            return;
        }
        int mid=start+(end-start)/2;
        if(start<=idx && idx<=mid) update(2*node+1,start, mid, idx, val);
        else update(2*node+2, mid+1, end, idx,val);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            ans.push_back(query(0,0,1e5,0,nums[i]+1e4));
            update(0,0,1e5,nums[i]+1e4+1,1);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};