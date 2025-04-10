class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> end_time(n+1);
        long long curr_time = 0;

        for(int i=0;i<n;i++){
            curr_time+=skill[i]*mana[0];
            end_time[i] = curr_time;
        }

        for(int i=1;i<m;i++){
            vector<long long> curr_end_time(n+1,0);
            curr_time = end_time[0];
            for(int j=0;j<n;j++){
                curr_end_time[j] = max(end_time[j+1], curr_time+skill[j]*mana[i]);
                curr_time = curr_end_time[j];
            }
            for(int j = n-2;j>=0;j--){
                curr_end_time[j] = curr_end_time[j+1] - skill[j+1]*mana[i];
            }
            end_time = curr_end_time;
        }

        return end_time[n-1];
        
    }
};