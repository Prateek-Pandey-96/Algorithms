// 901. Online Stock Span

class StockSpanner {
public:
    stack<pair<int, int>> s;
    StockSpanner() {
        while(!s.empty())
            s.pop();
    }
    
    int next(int price) {
        int days = 1;
        while(!s.empty() and s.top().second<=price)
        {
            days += s.top().first;
            s.pop();
        }

        s.push({days, price});
        return days;

    }
};
