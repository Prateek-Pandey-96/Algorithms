// 45. Jump Game II

class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0, farthest = 0, steps = 0;
        int n = nums.size();
        while(!(start<=n-1 and end>=n-1)){
            for(int i=start; i<=end and i<n; i++)
                farthest = max(farthest, i+nums[i]);
            
            start = end + 1;
            end = farthest;
            steps++;
        }

        return steps;
    }
};