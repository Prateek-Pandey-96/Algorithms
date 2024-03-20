// 56. Merge Intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        int start = intervals[0][0], end = intervals[0][1];
        
        for(int i=1; i<n; i++){
            if(intervals[i][0]>end){
                result.push_back({start, end});
                start = intervals[i][0];
                end = max(end, intervals[i][1]);
            }else{
                end = max(end, intervals[i][1]);
            }
        }
        result.push_back({start, end});
        return result;
    }
};