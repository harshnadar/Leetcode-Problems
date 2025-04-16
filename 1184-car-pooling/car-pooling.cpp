class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int> freq(10002, 0);
        for(int i=0;i<n;i++){
            freq[trips[i][1]]+=trips[i][0];
            freq[trips[i][2]] -= trips[i][0];
        }

        int count = 0;
        for(int i=0;i<freq.size();i++){
            count+=freq[i];
            if(count>capacity) return false;
        }
        return true;
    }
};