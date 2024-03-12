// 912. Sort an Array

class Solution {
public:
    vector<int> Merge2SortedArrays(vector<int>& left, vector<int>& right){
        int i=0, j=0, k=0, m = left.size(), n = right.size();
        vector<int> result(m+n, 0);
        
        while(i<m and j<n){
            if(left[i]<=right[j])
                result[k++]=left[i++];
            else
                result[k++]=right[j++];
        }

        while(i<m)
            result[k++] = left[i++];

        while(j<n)
            result[k++] = right[j++];
        
        return result;
    }

    vector<int> MergeSort(vector<int>& nums, int low, int high){
        if(low==high)
            return {nums[low]};
        int mid = low + (high-low)/2;

        vector<int> left = MergeSort(nums, low, mid);
        vector<int> right = MergeSort(nums, mid+1, high);

        return Merge2SortedArrays(left, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        return MergeSort(nums, 0, nums.size()-1);
    }
};