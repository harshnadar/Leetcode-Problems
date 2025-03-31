class Solution {
public:
    map<int, vector<int>> mp;
    bool num_diff(string& a, string& b){
        int count = 0;
        int n = a.size(); int m = b.size();
        if(n!=m) return false;
        for(int i = 0;i<n;i++){
            if(a[i]!=b[i]) count++;
            if(count>1) return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();

        int end_word_idx = -1;
        int beg_word_idx = n-1;
        for(int i = 0;i<n-1;i++){
            if(endWord == wordList[i]) end_word_idx = i;
            for(int j=i+1;j<n;j++){
                if(num_diff(wordList[i], wordList[j])){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
                
            }
        }
        if(end_word_idx == -1){
            return 0;
        }

        queue<vector<int>> q;
        q.push({end_word_idx, 1});
        vector<bool> vis(n+1,0);
        while(!q.empty()){
            vector<int> curr_node = q.front();
            q.pop();


            for(auto child: mp[curr_node[0]]){
                if(vis[child]) continue;

                if(child == n-1) return curr_node[1]+1;

                q.push({child, curr_node[1]+1});
                vis[child] = true;
            }
        }

        return 0;
    }
};