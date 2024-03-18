// 57. Insert Interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int start = newInterval[0], end = newInterval[1];
        vector<vector<int>> result;

        int idx = 0;
        // all the intervals which end before new interval start
        while(idx < n and intervals[idx][1] < start)
            result.push_back(intervals[idx++]);

        // when interscetion occurs
        
        while(idx < n and intervals[idx][0] <= end){
            start = min(start, intervals[idx][0]);
            end = max(end, intervals[idx][1]);
            idx++;
        }
        result.push_back({start, end});

        // remaining intervals
        while(idx < n)
            result.push_back(intervals[idx++]);

        return result;
    }
};