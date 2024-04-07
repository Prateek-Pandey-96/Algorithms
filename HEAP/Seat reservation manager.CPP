// 1845. Seat Reservation Manager

class SeatManager {
public:
    /*
    A minHeap should do
    */
    priority_queue<int, vector<int>, greater<int>> available;
    
    SeatManager(int n) {
        while(!available.empty())
            available.pop();
        for(int i=1; i<=n; i++)
            available.push(i);
    }
    
    int reserve() {
        int seat = available.top();
        available.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        available.push(seatNumber);
    }
};
