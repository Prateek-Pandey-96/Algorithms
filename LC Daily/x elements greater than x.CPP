// 1608. Special Array With X Elements Greater Than or Equal X

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = n;

        while(low <= high){
            int mid = low + (high-low)/2;
            // first number equal to mid
            int idx = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
            if(n-idx == mid)
                return mid;
            else if(n-idx > mid)
                low = mid+1;
            else
                high = mid-1;
        }

        return -1;
    }
};