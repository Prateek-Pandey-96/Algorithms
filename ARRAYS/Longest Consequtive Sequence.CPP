// 128. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), mx_len = 0;
        unordered_set<int> nums_set(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(nums_set.contains(nums[i]+1)){
                continue;
            }else{
                int size = 1, curr = nums[i];
                while(!nums_set.empty() and nums_set.contains(curr-1)){
                    curr = curr-1;
                    size++;
                }
                mx_len = max(mx_len, size);
            }
        }
        return mx_len;
    }
};