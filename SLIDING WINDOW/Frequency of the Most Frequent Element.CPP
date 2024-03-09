// 1838. Frequency of the Most Frequent Element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        // sorting is necessary to ensure last element in a window is the largest
        sort(nums.begin(), nums.end());
        long sum=0, i=0, j=0, max_f = 0;

        while(j < n){
            sum += nums[j];

            while((nums[j]*(j-i+1) - sum) > k){
                sum -= nums[i];
                i++;
            }

            max_f = max(max_f, j-i+1);
            j++;
        }

        return max_f;
    }
};