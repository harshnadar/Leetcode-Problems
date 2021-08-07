class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        queue<string> q;
        if(find(wordList.begin(), wordList.end(), endWord) ==wordList.end()) return 0;
        for(auto it: wordList){
            s.insert(it);
        }
        q.push(beginWord);
        s.erase(beginWord);
        int d=0;
        while(!q.empty()){
            d++;
            int n=q.size();
            while(n--){
                string cur=q.front();
                q.pop();
                for(int i=0;i<cur.size();i++){
                    string tmp=cur;
                    for(char j='a';j<='z';j++){
                        tmp[i]=j;
                        if(tmp==cur) continue;
                        else if(tmp==endWord) return d+1;
                        else if(s.find(tmp)!=s.end()){
                            q.push(tmp);
                            s.erase(tmp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};