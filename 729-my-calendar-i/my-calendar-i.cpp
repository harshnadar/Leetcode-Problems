class MyCalendar {
    map<int, int> mp;;
public:
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        mp[s]++;
        mp[e]--;
        int count = 0;
        for(auto it: mp){
            count+=it.second;
            if(count>1) {
                mp[s]--;
                mp[e]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */