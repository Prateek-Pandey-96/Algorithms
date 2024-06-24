// 995. Minimum Number of K Consecutive Bit Flips

class Solution {
public:
    bool shouldFlip(int affecting_flips, int num){
        return (affecting_flips%2 != 0 and num == 1) 
        || (affecting_flips%2 == 0 and num == 0);
    }
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0, affecting_flips = 0;
        vector<bool> affect_end(n, false);
        
        for(int i=0; i<=n-k; i++){
            if(affect_end[i])
               affecting_flips--;
            if (shouldFlip(affecting_flips, nums[i])){
                flips++;
                affecting_flips++;
                affect_end[i+k] = true;
            }
        }

        for(int i=n-k+1; i<n; i++){
            if(affect_end[i])
               affecting_flips--;
            if (shouldFlip(affecting_flips, nums[i]))
                return -1;
        }

        return flips;
    }
};