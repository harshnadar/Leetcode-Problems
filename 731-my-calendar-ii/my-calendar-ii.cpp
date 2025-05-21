class MyCalendarTwo {
    map<int, int> mp;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int s, int e) {
        mp[s]++;
        mp[e]--;
        int count = 0;
        for(auto it: mp){
            count+=it.second;
            if(count>2){
                mp[s]--;
                mp[e]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */