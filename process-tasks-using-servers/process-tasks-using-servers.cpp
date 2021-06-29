class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>> available, busy;
        int n=servers.size();
        int m=tasks.size();
        for (int i = 0; i < n; i++) {
            // All servers are currently available at time 0
            available.push({ 0, servers[i], i });
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            while(available.empty() || !busy.empty() && busy.top()[0]==i ){
                array<long, 3> s= busy.top();
                busy.pop();
                available.push({((s[0]==i)?0:s[0]) , s[1], s[2] });
            }
            array<long, 3> s;
            s=available.top();
            available.pop();
            busy.push({(s[0]==0?i+tasks[i]:s[0]+tasks[i]), s[1], s[2]});
            ans.push_back(s[2]);
        }
        return ans;
    }
};