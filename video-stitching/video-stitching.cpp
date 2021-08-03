class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n =clips.size();
        sort(clips.begin(), clips.end());
        int mn=0, mx=0; int num=0;
        // if(clips[n-1][1]<time) return -1;
        while(mx<time){
            for(int i=0;i<n;i++){
                if(clips[i][1]>mx && clips[i][0]<=mn){
                    mx=clips[i][1];
                }
            }
            if(mn==mx) return -1;
            num++;
            cout<<mn<<' '<<mx<<"\n";
            mn=mx;
        }
        return num;
    }
};