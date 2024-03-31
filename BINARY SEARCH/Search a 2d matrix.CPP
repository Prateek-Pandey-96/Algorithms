// 74. Search a 2D Matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first get the row with start just less than target
        int n = matrix.size();
        int low = 0, high = n-1, row = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[mid][0] > target)
                high = mid-1;
            else if(matrix[mid][0]==target)
                return true;
            else
                low = mid+1, row = mid;
        }
        // no row found with start smaller than target
        if(row == -1)
            return false;
        
        low = 0, high = matrix[0].size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[row][mid]==target)
                return true;
            else if(matrix[row][mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }

        return false;
    }
};