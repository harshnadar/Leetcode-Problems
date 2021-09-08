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
    
    int createSortedArray(vector<int>& instructions) {
        int n=instructions.size();
        int ans = 0;
        int mod = 1e9+7;
        for(auto it: instructions){
            ans = (ans+min(query(0,0,n,0,it-1), query(0,0,n,it+1,1e5)))%mod;
            update(0,0,n,it,1);
        }
        return ans;
    }
};