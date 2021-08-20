class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int n=input.size();
        for(int i=0;i<n;i++){
            char ch=input[i];
            if(ch=='+' || ch=='-' || ch=='*'){
                vector<int> res1 = diffWaysToCompute(input.substr(0,i));
                vector<int> res2 = diffWaysToCompute(input.substr(i+1));
                for(auto it: res1){
                    for(auto itr: res2){
                        if(ch=='+') res.push_back(it+itr);
                        else if(ch=='-') res.push_back(it-itr);
                        else res.push_back(it*itr);
                    }
                }
            }
        }
        if(res.empty()){
            res.push_back(atoi(input.c_str()));
        }
        return res;
    }
};