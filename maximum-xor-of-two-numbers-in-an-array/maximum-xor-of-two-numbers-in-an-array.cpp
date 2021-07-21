class Solution {
public:
    class node{
    public:
        node* left;
        node* right;
    };
    
    class trie{
        
    public:
        node* root;
        trie(){
            root = new node();
        }
        
        void insert(int n){
            node* temp=root;
            for(int i=31;i>=0;i--){
                int bit= (n>>i)&1;
                if(bit==0){
                    if(temp->left==NULL){
                        temp->left=new node();
                    }
                    temp=temp->left;
                }
                else{
                    if(temp->right == NULL){
                        temp->right=new node();
                    }
                    temp=temp->right;
                }
            }
        }
        
        int max_xor(int val){
            int cur=0;
            node* temp=root;
            for(int i=31;i>=0;i--){
                int bit=(val>>i)&1;
                if(bit==1){
                    if(temp->left!=NULL){
                        cur+=(1<<i);
                        temp=temp->left;
                    }
                    else{
                        temp=temp->right;
                    }
                }
                else{
                    if(temp->right!=NULL){
                        cur+=(1<<i);
                        temp=temp->right;
                    }
                    else{
                        temp=temp->left;
                    }
                }
            }
            return cur;
        }
    };
    
    
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        trie t;
        int ans=-7;
        for(int i=0;i<n;i++){
            t.insert(nums[i]);
            int cur=t.max_xor(nums[i]);
            // cout<<cur<<"\n";
            ans=max(cur,ans);
        }
        return ans;
    }
};