class Solution {
public:
    void dfs(int idx, vector<int>& nums, int k, unordered_map<int, int>& temp, int& count){
        if(idx == nums.size()){
            count += 1;
            return;
        }

        if(temp[nums[idx]-k]){
            dfs(idx+1, nums, k, temp, count);
        }else{
            dfs(idx+1, nums, k, temp, count);
            temp[nums[idx]]++;
            dfs(idx+1, nums, k, temp, count);
            temp[nums[idx]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> temp;
        int count = 0;
        sort(nums.begin(), nums.end());
        dfs(0, nums, k, temp, count);
        //remove empty beautiful subset and return
        return --count;
    }
};