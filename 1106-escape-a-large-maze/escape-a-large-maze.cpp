class Solution {
public:
    map<pair<int,int>, bool> wall;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    bool bfs(vector<int> src, vector<int> target){
        map<pair<int, int>, bool> seen;
        seen[{src[0], src[1]}] = true;

        queue<pair<int, int> > q;
        q.push({src[0], src[1]});

        while(!q.empty()){
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int new_x = curr_x + dx[i];
                int new_y = curr_y + dy[i];

                if(new_x == target[0] && new_y == target[1]) return true;
                
                if(new_x < 0 || new_y < 0 || new_x >= 1e6 || new_y >= 1e6 || wall[{new_x, new_y}] || seen[{new_x, new_y}]) continue;
                seen[{new_x, new_y}] = true;
                q.push({new_x, new_y});
                if(seen.size() == 20000) return true;
            }
        }
        return false;
    }



    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for(auto it: blocked) wall[{it[0], it[1]}] = true;
        return bfs(source, target) && bfs(target, source);

    }
};