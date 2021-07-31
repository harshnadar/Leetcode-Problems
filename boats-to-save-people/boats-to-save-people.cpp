class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int light=0;
        int heavy=people.size()-1;
        int boats=people.size(); // assuming initially everyone needs a separate boat
        while(light<heavy)
        {
            if(people[light]+people[heavy]<=limit) /* since it's a minimization problem,we always pick the lightest one and the heaviest one and see if they can fit in the same boat,if yes,we can reduce the number of boats needed by 1 */
            {
                boats--;
                light++;
                heavy--;
            }
            else // let the heavier one take the boat,with the hope that we can find some other boat with place for the lighter one
            {
                
                heavy--;
            }
        }
        return boats;
    }
};