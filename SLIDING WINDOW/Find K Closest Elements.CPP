// 658. Find K Closest Elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int distance = 0, n = arr.size(), min_distance = INT_MAX;
        
        int start = 0, end = k-1;
        for(int i=0; i<k; i++)
            distance += abs(arr[i]-x);
        min_distance = distance;

        for(int i=k; i<n; i++){
            distance += abs(arr[i]-x) - abs(arr[i-k]-x);
            if(distance < min_distance){
                min_distance = distance;
                start = i-k+1;
                end = i;
            }
        } 

        vector<int> result;
        for(int ctr=start; ctr<=end; ctr++)
            result.push_back(arr[ctr]);
        
        return result;
    }
};