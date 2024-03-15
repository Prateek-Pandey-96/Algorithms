// 740. Delete and Earn

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // first sort the array so that at any point we only need to worry about smaller element
        sort(nums.begin(), nums.end());
        
        //we also need count of each element
        unordered_map<int, int> freq;
        vector<int> new_nums;
        for(int num: nums)
        {
            freq[num]++;
            if(freq[num]==1)
                new_nums.push_back(num);
        }
        
        int n = new_nums.size();
        vector<vector<int>> max_points(2, vector<int>(n, 0));
        max_points[0][0] = freq[new_nums[0]]*new_nums[0];
        max_points[1][0] = 0; 

        for(int i=1; i<n; i++){
            int curr_element = new_nums[i];
            if(curr_element - new_nums[i-1] != 1)
                max_points[0][i] = max(max_points[0][i-1], max_points[1][i-1]) + freq[curr_element] * curr_element;
            else
                max_points[0][i] = max_points[1][i-1] + freq[curr_element] * curr_element;
            
            max_points[1][i] = max(max_points[0][i-1], max_points[1][i-1]);
        }

        return max(max_points[0][n-1], max_points[1][n-1]);
    }
};