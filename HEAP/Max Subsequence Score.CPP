// 2542. Maximum Subsequence Score

class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
    long long maxNum(long long a, long long b){
        if(a>=b)
            return a;
        return b;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pair_vec;
        int n = nums1.size();
        for(int i=0; i<n; i++)
            pair_vec.push_back({nums1[i], nums2[i]});
        sort(pair_vec.begin(), pair_vec.end(), compare);

        long long result = -1;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i=0; i<k; i++){
            sum += (long long)pair_vec[i].first;
            minHeap.push(pair_vec[i].first);
        }
        result = (long long)pair_vec[k-1].second * sum;
        
        for(int i=k; i<n; i++){
            // we want heap to always have k-1 elements
            sum += (long long)pair_vec[i].first;
            if(minHeap.size() > k-1){
                long long remove = minHeap.top();
                sum -= remove;
                minHeap.pop();
            }
            minHeap.push(pair_vec[i].first);
            result = maxNum(result, sum  * pair_vec[i].second);
        }

        return result;
    }
};