class MyCalendarThree {
    map<int, int> mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int s, int e) {
        mp[s]++;
        mp[e]--;
        int count = 0;
        int ans = 0;
        for(auto it: mp){
            count+=it.second;
            if(it.first >= s || it.first < e){
                ans = max(ans, count);
            }
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */