// 260. Single Number III

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size(), XOR = 0;
        for(int i=0; i<n; i++)
            XOR ^= nums[i];
        
        int idx = 0;
        for(int i=0; i<32; i++){
            if((XOR & (1<<i))!=0)
            {
                idx = i;
                break;
            }
        }

        int num1 = 0;
        for(int i=0; i<n; i++){
            if((nums[i]&(1<<idx))!=0)
                num1 = num1^nums[i];
        }

        return {num1, XOR^num1};
    }
};