// 1964. Find the Longest Valid Obstacle Course at Each Position

class Solution {
public:
    int getIdx(vector<int>& arr, int x){
        int low = 0, high = arr.size()-1, idx = -1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid]>x){
                high = mid-1;
            }else{
                idx = mid;
                low = mid+1;
            }
        }

        return idx+1;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // lis using binary search
        int n = obstacles.size();
        vector<int> result;
        vector<int> inc_array;
        for(int i=0; i<n; i++){
            if(inc_array.size()==0 || inc_array.back()<=obstacles[i]){
                inc_array.push_back(obstacles[i]);
                result.push_back(inc_array.size());
            }else{
                // find last element smaller than or equal to obstacles[i]
                int idx = getIdx(inc_array, obstacles[i]);
                inc_array[idx] = obstacles[i];
                result.push_back(idx+1);
            }
        }
        return result;                                       
    }
};