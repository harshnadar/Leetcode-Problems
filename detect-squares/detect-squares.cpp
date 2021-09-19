class DetectSquares {
public:
    int mp[1002][1002];
    DetectSquares() {
        memset(mp,0,sizeof mp);
    }
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x=point[0];
        int y=point[1];
        int ans=0;
        for(int i=0;i<1001;i++){
            if(i!=y && mp[x][i]>0){
                int dist=abs(y-i);
                if(x+dist<1001) {ans+=mp[x][i]*mp[x+dist][y]*mp[x+dist][i];}
                if(x-dist>=0) {ans+=mp[x][i]*mp[x-dist][y]*mp[x-dist][i]; }
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */