// 1288. Remove Covered Intervals

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int include = 1, start = intervals[0][0], end = intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0]==start){
                end = max(end, intervals[i][1]);
            }else{
                if(intervals[i][0]>=end){
                    end = intervals[i][1];
                    start = intervals[i][0];
                    include++;
                }else{
                    if(intervals[i][1] <= end)
                        continue;
                    end = intervals[i][1];
                    start = intervals[i][0];
                    include++;
                }   
            }
            
        }

        return include;
    }
};