// 438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int, int> freq;
        int i=0, j=0, len = 1;

        while(j<n){
            freq[nums[j]]++;
            while((freq.rbegin()->first - freq.begin()->first) > limit){
                freq[nums[i]]--;
                if(freq[nums[i]]==0)
                    freq.erase(nums[i]);
                i++;
            }
            len = max(len, j-i+1);
            j++;
        }
        return len;
    }
};