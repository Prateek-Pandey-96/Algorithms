// 239. Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        
        deque<int> dq;
        for(int i=0; i<k; i++){
            while(!dq.empty() and nums[i] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);

        for(int i=k; i<n; i++){
            while(!dq.empty() and i-dq.front()>=k)
                dq.pop_front();
            while(!dq.empty() and nums[i] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            result.push_back(nums[dq.front()]);
        }

        return result;
    }
};