#define f(a,b,i) for(int i=a;i<b;i++)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> v= arr;
        sort(v.begin(),v.end());
        map<int, int > mp;
        map<int, int > m;
        f(0,n,i){
            mp[v[i]]=i+1;
        }
        int pre[n+2];
        pre[0]=0;
        f(1,n+1,i) pre[i]=pre[i-1]+i;
        int i=0,j=0;
        int sum=0;
        int count=0;
        
        while(j<n){
            sum+=mp[arr[j]] + m[arr[j]];
            m[arr[j]]++;
            // cout<<j<<" "<<sum<<" "<<pre[j+1]<<"\n";
            if(sum == (pre[j+1]-pre[i])) {cout<<i<<" "<<j<<" "<<sum<<"\n"; count++, sum=0, j++; i=j; continue; }
            j++;
        }
        return count;
    }
};