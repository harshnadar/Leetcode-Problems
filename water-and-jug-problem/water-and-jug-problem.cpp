class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int target) {
        if(__gcd(jug1, jug2)==1){
            return (target>=0 && target<=jug1+jug2);
        }
        else{
            if(__gcd(jug1, jug2)==__gcd(__gcd(jug1,target), jug2) && target>=0 && target<=jug1+jug2) return true;
        }
        return false;
    }
};