class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n=a.size();
        int count=1;
        int l=0;
        int y=0;
        for(int i=0;i<n-1;i++){
            if(a[i+1]>a[i]){ count++; l=1, y=i; break;}
            if(a[i]>a[i+1]){
                count++; l=0, y=i; break;
            }
        }
        for(int i=y+1;i<n-1;i++){
            if(a[i+1]>a[i] && l==0){
                count++; l=1;
            }
            if(a[i+1]<a[i] && l==1){
                count++;
                l=0;
            }
        }
        return count;
    }
};