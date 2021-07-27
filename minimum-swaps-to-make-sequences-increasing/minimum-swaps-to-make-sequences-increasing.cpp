class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> swap(n+1,1), not_swap(n+1,0);
        for(int i=1;i<n;i++){
            not_swap[i]=swap[i]=n;
            if(A[i]>A[i-1] && B[i]>B[i-1]){
                swap[i]=swap[i-1]+1;
                not_swap[i]=not_swap[i-1];
            }
            if(A[i]>B[i-1] && A[i-1]<B[i]){
                swap[i]=min(swap[i], not_swap[i-1]+1);
                not_swap[i]=min(swap[i-1], not_swap[i]);
            }
        }
        return min(swap[n-1], not_swap[n-1]);
    }
};