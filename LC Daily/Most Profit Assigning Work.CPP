// 826. Most Profit Assigning Work
class Solution {
public:
    int get_idx(vector<pair<int, int>>& jobs, int limit){
        int low = 0, high = jobs.size()-1, idx = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(jobs[mid].first <= limit){
                idx = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return idx;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int n = profit.size();

        for(int i=0; i<n; i++)
            jobs.push_back({difficulty[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());

        // instead of creating this we can modify the profit itself
        vector<int> pre_profit(n, 0);
        pre_profit[0] = jobs[0].second;
        for(int i=1; i<n; i++){
            pre_profit[i] = max(jobs[i].second, pre_profit[i-1]);
        }

        int max_profit = 0;
        for(int max_diff: worker){
            int idx = get_idx(jobs, max_diff);
            if(idx != -1)
                max_profit += pre_profit[idx];
        }

        return max_profit;
    }
};