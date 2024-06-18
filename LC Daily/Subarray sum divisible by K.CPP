// 974. Subarray Sums Divisible by K

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int j=0, sum=0, result=0;
        unordered_map<int, int> freq;
        freq[0] = 1;
        while(j<n){
            sum+=nums[j];
            int rem = sum%k;
            
            if(rem<0)
                rem = rem + k;
            
            if(freq.contains(rem))
                result += freq[rem];

            freq[rem]++;
            j++;
        }
        return result;
    }
};