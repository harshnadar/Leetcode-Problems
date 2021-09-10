#define MAXN 100001
class Solution {
public:
    int seg[4*MAXN];
    void update(int ind,int l,int r,int i,int x)
    {
        if(ind>r||ind<l||l>r) return ;
        if(l==r)
        {
            if(l==ind)
                seg[i]=x;
            return ;
        }
        int mid=(l+r)/2;
        update(ind,l,mid,2*i+1,x);
        update(ind,mid+1,r,2*i+2,x);
        seg[i]=min(seg[2*i+1],seg[2*i+2]);
    }
    int query(int st,int en,int l,int r,int i,int x)
    {
        //cout<<l<<" "<<r<<"\n";
        if(st>en||l>en||r<st||seg[i]>x)
            return -1;
        if(l==r) 
            return l;
        int mid=(l+r)/2;
        int lf=query(st,en,l,mid,2*i+1,x);
        if(lf!=-1)
            return lf;
        int rf=query(st,en,mid+1,r,2*i+2,x);
        return rf;
    }
    int que(int st,int en,int l,int r,int i,int x)
    {
        if(st>en||l>en||r<st||seg[i]>x)
            return -1;
        if(l==r) 
            return l;
        int mid=(l+r)/2;
        int rf=que(st,en,mid+1,r,2*i+1,x);
        if(rf!=-1)
            return rf;
        int lf=que(st,en,l,mid,2*i+2,x);
        return lf;
    }
    vector<int> busiestServers(int k, vector<int>& arr, vector<int>& lo) {
        int i,j,n=arr.size();
        j=-1;
        vector<int> b(n,0),ans;
        map<int,int> m;
        for(i=0;i<n;i++)
        {
            int x=query(i%k,k-1,0,k-1,0,arr[i]);
            if(x!=-1)
            {
                //cout<<1<<" "<<x<<" "<<i<<"\n";
                m[x]++;
                b[x]=arr[i]+lo[i];
                update(x,0,k-1,0,b[x]);
                continue;
            }
            int y=query(0,i%k-1,0,k-1,0,arr[i]);
            if(y!=-1)
            {
                //cout<<2<<" "<<y<<" "<<i<<"\n";
                m[y]++;
                b[y]=arr[i]+lo[i];
                update(y,0,k-1,0,b[y]);
            }
        }
        int maxi=0;
        for(auto e:m)
            maxi=max(maxi,e.second);
        // for(auto e:m)
        // cout<<e.first<<" "<<e.second<<"\n";
        for(auto e:m)
        {
            if(e.second==maxi)
                ans.push_back(e.first);
        }
        return ans;
    }
};