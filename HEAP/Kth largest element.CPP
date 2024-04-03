// 215. Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min Heap with max size k
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = nums.size();
        for(int i=0; i<n; i++){
            minHeap.push(nums[i]);
            if(minHeap.size()>k)
                minHeap.pop();
        }

        return minHeap.top();
    }
};