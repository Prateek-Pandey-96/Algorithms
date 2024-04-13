// 352. Data Stream as Disjoint Intervals

class SummaryRanges {
public:
    int arr[10001];
    int mx;
    SummaryRanges() {
        memset(arr, 0, sizeof arr);
        mx = -1;
    }
    
    void addNum(int value) {
        arr[value] = 1;
        mx = max(mx, value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        int start = -1, end = -1, i = 0;
        
        while(i<=mx){
            if(arr[i]==1){
                start = i, end = i;
                while(arr[i])
                    i++;
                end = i-1;
            }else{
                if(!(start == -1 and end == -1) and !(result.size() and result.back()[0]==start and result.back()[1]==end))
                    result.push_back({start, end});
                i++;
            }
        }
        if(!(start == -1 and end == -1) and !(result.size() and result.back()[0]==start and result.back()[1]==end))
            result.push_back({start, end});
        return result;
    }
};
