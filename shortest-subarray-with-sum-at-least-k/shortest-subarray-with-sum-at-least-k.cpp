#define MAXN 100002
class Solution {
public:
    int a[MAXN],seg[4*MAXN];
    void build(int l,int r,int i)
    {
        if(l==r)
        {
            seg[i]=a[l];
            return ;
        }
        int mid=(l+r)/2;
        build(l,mid,2*i+1);
        build(mid+1,r,2*i+2);
        seg[i]=max(seg[2*i+1],seg[2*i+2]);
    }
    int query(int st,int en,int l,int r,int i,int x)
    {
        if(st>r||en<l||st>en) return -1;
        if(seg[i]<x) return -1;
        if(l==r)
        {
            if(seg[i]<x) return -1;
            return l;
        }
        int mid=(l+r)/2;
        int lf=query(st,en,l,mid,2*i+1,x);
        if(lf!=-1)
            return lf;
        int rt=query(st,en,mid+1,r,2*i+2,x);
        return rt;
    }
    int shortestSubarray(vector<int>& A, int k) {
        int i,n=A.size(),s=0,ans=1e7,j;
        a[0]=A[0];
        for(i=1;i<n;i++) a[i]=(a[i-1]+A[i]);
        build(0,n-1,0);
        for(i=0;i<n;i++)
        {
            int x=query(i,n-1,0,n-1,0,s+k);
            if(x!=-1)
            ans=min(ans,x-i+1);
            s+=A[i];
        }
        if(ans==1e7) ans=-1;
        return ans;
    }
};