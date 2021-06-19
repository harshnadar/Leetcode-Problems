class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
		return (int)bs(1,maxSum,index,maxSum,n);
	}
	long bs(long l,long r,int index,int maxSum,int n){
		if(l>r)return -1;
		long mid = (r-l)/2 + l;
		bool curr = isPossible(index,mid,n,maxSum);
		bool next = isPossible(index,mid+1,n,maxSum);
		if(curr && !next)return mid;
		if(curr && next)return bs(mid+1,r,index,maxSum,n);
		return bs(l,mid-1,index,maxSum,n);
	}
	bool isPossible(int index,long mid,int n,int maxSum){
		long minLeftSum = calcMinSum(index,mid);
		long minRightSum =calcMinSum(n-index-1,mid);
		long totalSum = minLeftSum+minRightSum+mid;
		if(totalSum<=maxSum)return true;
		return false;
	}
	long calcMinSum(int index,long mid){
		if(index>=mid-1)return (mid*(mid-1))/2 + (index - (mid-1));
		return (mid*(mid-1))/2 - (mid-index)*(mid-index-1)/2;
	}
};