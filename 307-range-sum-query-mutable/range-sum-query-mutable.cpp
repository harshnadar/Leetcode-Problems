class SegTree{
public:
    int n;
    vector<int> tree;

    SegTree(const vector<int>& nums){
        this->n = nums.size();
        tree.resize(4*n+1, 0);
        buildTree(nums, 0, n-1, 0);
    }

    void buildTree(const vector<int>& nums, int start, int end, int idx){
        if(start == end){
            tree[idx] = nums[start];
            return;
        }
        int mid = (start+end)/2;
        buildTree(nums, start, mid, 2*idx+1);
        buildTree(nums, mid+1, end, 2*idx+2);
        tree[idx] = tree[2*idx+1] + tree[2*idx+2];
    }

    void update(int start, int end, int idx, int pos, int val){
        if(start == end){
            tree[idx] = val;
            return;
        }
        int mid = (start+end)/2;
        if(pos<=mid){
            update(start, mid, 2*idx+1, pos, val);
        }
        else{
            update(mid+1, end, 2*idx+2, pos, val);
        }
        tree[idx] = tree[2*idx+1] + tree[2*idx+2];
    }

    int query(int start, int end, int idx, int ql, int qr){
        if(qr<start || ql>end){
            return 0;
        }
        if(ql<=start && end<=qr){
            return tree[idx];
        }
        int mid = (start+end)/2;
        return query(start, mid, 2*idx+1, ql, qr) + query(mid+1, end, 2*idx+2, ql, qr);
    }

};

class NumArray {
public:
    SegTree* seg_tree;

    NumArray(vector<int>& nums) {
        seg_tree = new SegTree(nums);
    }
    
    void update(int index, int val) {
        seg_tree->update(0, seg_tree->n-1, 0, index, val);
    }
    
    int sumRange(int left, int right) {
        return seg_tree->query(0, seg_tree->n-1, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */