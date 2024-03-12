// 1658. Minimum Operations to Reduce X to Zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        int i=0, j=0, sum=0;
        n = nums.size();
        int min_operations = INT_MAX;
        
        while(j < 2*n){
            sum += nums[j%n];

            while(sum > x){
                sum -= nums[i%n];
                i++;
            }

            if(sum == x){
                if(j-i+1 < min_operations and (i==0 || j==n-1 || (n>=i and n<=j)))
                    min_operations = j-i+1;
                sum -= nums[i%n]; 
                i++;
            } 

            j++;
        }
        
        if(min_operations == INT_MAX || min_operations > n)
            return -1;
        return min_operations;
    }
};