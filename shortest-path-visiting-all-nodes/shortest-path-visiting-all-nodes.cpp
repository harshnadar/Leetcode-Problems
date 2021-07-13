class Solution {
public:
    struct harsh{
        int mask;
        int curr;
        int cost;
        
        harsh(int mask, int curr, int cost){
            this->mask=mask;
            this->curr=curr;
            this->cost=cost;
        }
    };
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<harsh> q;
        set<pair<int, int> > s;
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            q.push({mask,i,1});
            s.insert({mask,i});
        }
        while(!q.empty()){
            harsh cur = q.front();
            q.pop();
            if(cur.mask == (1<<n)-1) return cur.cost-1;
            else{
                for(auto it: graph[cur.curr]){
                    int bitMask = cur.mask;
                    bitMask = bitMask|(1<<it);
                    harsh t(bitMask,it,0);
                    if(s.find({bitMask,it})==s.end()){
                        q.push({bitMask,it,cur.cost+1});
                        s.insert({bitMask,it});
                    }
                }
            }
        }
        return -1;
    }
};