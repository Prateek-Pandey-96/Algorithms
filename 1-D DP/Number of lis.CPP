// 673. Number of Longest Increasing Subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), freq(n, 1);
        int mx_lis = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j] and lis[i]<lis[j]+1){
                    lis[i] = lis[j]+1;
                    freq[i] = freq[j];
                }else if(nums[i]>nums[j] and lis[i]==lis[j]+1){
                    freq[i] += freq[j];
                }
            }
            mx_lis = max(mx_lis, lis[i]);
        }
        cout<<mx_lis;
        int count = 0;
        for(int i=0; i<n; i++){
            cout<<freq[i]<<" ";
            if(lis[i]==mx_lis)
                count += freq[i];
        }

        return count;
    }
};