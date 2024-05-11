// 857. Minimum Cost to Hire K Workers

#define maxHeap priority_queue<int>
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        maxHeap pq;

        vector<pair<double, int>> ratios;
        for(int i=0; i<n; i++)
            ratios.push_back({(1.0)*wage[i]/quality[i], i});
        
        sort(ratios.begin(), ratios.end());
        double ans = INT_MAX, curr_ratio = ratios[k-1].first;
        int curr_quality_sum = 0;

        for(int i=0; i<k; i++)
        {
            curr_quality_sum += quality[ratios[i].second];
            pq.push(quality[ratios[i].second]);
        }

        ans = min(ans, curr_quality_sum * curr_ratio);

        for(int i=k; i<n; i++){
            curr_quality_sum -= pq.top();
            pq.pop();
            curr_quality_sum += quality[ratios[i].second];
            pq.push(quality[ratios[i].second]);
            ans = min(ans, curr_quality_sum * ratios[i].first);
        }

        return ans;
    }
};