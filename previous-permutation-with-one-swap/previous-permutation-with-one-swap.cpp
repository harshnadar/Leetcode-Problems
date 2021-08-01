class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int len = A.size();
        if (len < 2) return A;
        // check if already increasing O(N), find the left
        int left = len - 2;
        while ( left >= 0 && A[left+1] >= A[left]){
            left--;
        }
        if (left < 0) return A;
        
        // find the right
        int right = A.size() - 1;
        while (A[right] >= A[left])
            right--;
        // if there are multiple same value, take the leftmost one
        // example: input [3, 1, 1, 3]
        while (A[right] == A[right-1])
            right--;
        swap(A[left], A[right]);
        return A;
    }
};