// 2013. Detect Squares

class DetectSquares {
public:
    map<pair<int, int>, int> freq;
    DetectSquares() {
        freq.clear();
    }
    
    void add(vector<int> point) {
        freq[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1], cnt = 0;
        for(auto [point, f]: freq){
            int newx = point.first, newy = point.second;
            if(newx == x and newy == y)
                continue;
            if(abs(newx-x)==abs(newy-y) and freq.contains({x, newy}) and freq.contains({newx, y})){
                cnt += f*freq[{x, newy}]*freq[{newx, y}];
            }
        }
        return cnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */