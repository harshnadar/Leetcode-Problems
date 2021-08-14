class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() <= 3) {
            return false;
        }
        int i = 2;
        // keep spiraling outward
        while (i < x.size() && x[i] > x[i - 2]) {
            i++;
        }
        if (i >= x.size()) {
            return false;
        }
        // transition from spiraling outward to spiraling inward
        if ((i >= 4 && x[i] >= x[i - 2] - x[i - 4]) ||
                (i == 3 && x[i] == x[i - 2])) {
            x[i - 1] -= x[i - 3];
        }
        i++;
        // keep spiraling inward
        while (i < x.size()) {
            if (x[i] >= x[i - 2]) {
                return true;
            }
            i++;
        }
        return false;
    }
};