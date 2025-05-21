class MyCalendar {
    set<pair<int, int> > booked;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto next = booked.lower_bound({startTime, endTime});
        if(next!=booked.end() && next->first < endTime){
            return false;
        }
        if(next!=booked.begin() && startTime < (--next)->second) return false;
        booked.insert({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */