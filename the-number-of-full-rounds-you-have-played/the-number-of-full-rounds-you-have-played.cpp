class Solution {
public:
    int numberOfRounds(string startTime, string endTime) {
        int s1,s2,e1,e2;
        if(startTime==endTime) return 0;
        s1=stoi(startTime.substr(0,2));
        s2=stoi(startTime.substr(3,2));
        e1=stoi(endTime.substr(0,2));
        e2=stoi(endTime.substr(3,2));
        int start= 60*s1 + s2;
        int end= 60*e1 + e2;
        if(start>end) end+=24*60;
        start=(start+14)/15;
        end=end/15;
        return (((end-start)>=0)?(end-start):0);
        
        
    }
};