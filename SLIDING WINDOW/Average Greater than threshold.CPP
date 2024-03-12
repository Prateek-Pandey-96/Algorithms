// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to
// Threshold

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, count = 0;
        for (int i = 0; i < k; i++)
            sum += arr[i];
        if(sum >= threshold*k)
            count++;
        
        //slide the window now
        for(int i=k; i<arr.size(); i++){
            sum += arr[i]-arr[i-k];
            if(sum >= threshold*k)
            count++;
        }

        return count;
    }
};