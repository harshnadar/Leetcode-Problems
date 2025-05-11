class Solution {
public:

    vector<int> next_smaller_left(vector<int>& v){
        int n = v.size();
        vector<int> res(n,-1);
        stack<pair<int, int> > s;
        s.push({v[0], 0});

        for(int i=1;i<n;i++){
            if(!s.empty() && v[i] <= s.top().first){
                while(!s.empty() && v[i] <= s.top().first){
                    s.pop();
                }
            }
            if(s.empty()) res[i] = -1;
            else if(v[i] > s.top().first){
                res[i] = s.top().second;
            }
            
            s.push({v[i], i});
        }
        // for(auto it: res) cout<<it<<" ";
        return res;
    }

    vector<int> next_smaller_right(vector<int>& v){
        int n = v.size();
        vector<int> res(n,-1);
        stack<pair<int, int> > s;
        s.push({v[n-1], n-1});

        for(int i=n-2;i>=0;i--){
            if(!s.empty() && v[i] <= s.top().first){
                while(!s.empty() && v[i] <= s.top().first){
                    s.pop();
                }
            }
            if(s.empty()) res[i] = -1;
            else if(v[i] > s.top().first){
                res[i] = s.top().second;
            }
            
            s.push({v[i], i});
        }
        // for(auto it: res) cout<<it<<" ";
        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        // vector<vector<int>> v;
        vector<int> v;
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int> > res(n, vector<int> (m, 0));
        for(int i=0;i<n;i++){
            vector<int> temp(m,0);
            for(int j = 0;j<m;j++){
                if(i == 0){
                    if(matrix[i][j] == '1') temp[j] = 1;
                }
                else{
                    if(matrix[i][j] == '1'){
                        temp[j] = 1 + v[j];
                    }
                }
            }
            v = temp;
            // v.push_back(temp);
            vector<int> nsl = next_smaller_left(temp);
            vector<int> nsr = next_smaller_right(temp);
            for(int j = 0;j<m;j++){
                if(nsl[j]==-1 && nsr[j]==-1){
                    ans = max(ans, m*temp[j]);
                    // res[i][j] = m*temp[j];
                }
                else if(nsl[j]==-1){
                    ans = max(ans, nsr[j]*temp[j]);
                    // res[i][j] = nsr[j]*temp[j];
                }
                else if(nsr[j]==-1){
                    ans = max(ans, (m-nsl[j]-1)*temp[j]);
                    // res[i][j] = (m-nsl[j]-1)*temp[j];
                }
                else{
                    ans = max(ans, (nsr[j] - nsl[j] - 1)*temp[j]);
                    // res[i][j] = (nsr[j] - nsl[j] - 1)*temp[j];
                }
                // cout<<res[i][j]<<" ";
            }
            // cout<<endl;
            
        }
        return ans;
    }
};