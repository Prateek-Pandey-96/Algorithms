// 11. Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size()-1;
        int max_water = 0;

        while(low < high){
            int curr_capacity = (high-low) * min(height[low], height[high]);
            max_water = max(max_water, curr_capacity);
            if(height[low] < height[high])
                low++;
            else
                high--;
        }

        return max_water; 
    }
};