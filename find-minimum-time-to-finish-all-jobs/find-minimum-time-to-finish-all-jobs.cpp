class Solution {
public:
    int res;
    vector<int> jobs;
    int k;
    vector<int>workers;
    
    void dfs(int cur){
        if(cur == jobs.size()){
            int x = *max_element(workers.begin(), workers.end());
            res = min(res,x);
            return;
        }
        set<int> seen;
        for(int i=0;i<k;i++){
            if(seen.find(workers[i])!=seen.end()) continue;
            if(workers[i]+jobs[cur]>= res) continue;
            seen.insert(workers[i]);
            workers[i]+=jobs[cur];
            dfs(cur+1);
            workers[i]-=jobs[cur];
        }
       
    }
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        res=INT_MAX;
        this->jobs = jobs;
        this->k = k;
        workers.resize(k,0);
        dfs(0);
        return res;
    }
};