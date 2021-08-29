class Solution {
public:
    struct node{
        node* left;
        node* right;
    };
    
    node* root = new node();
    
    void in(int n){
        node* temp= root;
        
        for(int i=31;i>=0;i--){
            int bit = (n>>i)&1;
            
            if(bit ==0){
                if(temp->left ==NULL){
                    temp->left = new node();
                }
                temp=temp->left;
            }
            else{
                if(temp->right==NULL){
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }
    
    int maxXor(int n){
        if(root->left==NULL && root->right==NULL) return -1;
        int cur_ans =0;
        node* temp = root;
        
        for(int i=31;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit==0){
                if(temp->right!=NULL){
                    temp=temp->right;
                    cur_ans+=(1<<i);
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->left!=NULL){
                    temp=temp->left;
                    cur_ans+=(1<<i);
                }
                else temp=temp->right;
            }
        }
        return cur_ans;
        
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<vector<int> > q(m,vector<int>(3));
        for(int i=0;i<m;i++){
            q[i][0]=queries[i][1];
            q[i][1]=queries[i][0];
            q[i][2]=i;
        }
        sort(q.begin(), q.end());
        sort(nums.begin(), nums.end());
        int j=0;
        vector<int> ans(m);
        
        for(auto it: q){
            int x=it[1];
            int threshold = it[0];
            while(j<n && nums[j]<=threshold){
                in(nums[j]);
                j++;
            }
            ans[it[2]] = maxXor(x);
        }
        return ans;
    }
};