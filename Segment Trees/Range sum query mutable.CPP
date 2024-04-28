// 307. Range Sum Query - Mutable

class NumArray {
public:
    vector<int> arr, segTree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        segTree.resize(4 * n);
        build(0, 0, n-1);
    }
    void build(int idx, int low, int high){
        if(low == high){
            segTree[idx] = arr[low];
            return;
        }
        
        int mid = low + (high-low)/2;
        build(2*idx+1, low, mid);
        build(2*idx+2, mid+1, high);
        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }
    void updateTree(int idx, int low, int high, int node, int value){
        if(low == high){
            segTree[idx] = value;
            return;
        }
        
        int mid = low + (high-low)/2;
        if(node <= mid and node >= low)
            updateTree(2*idx+1, low, mid, node, value);
        else
            updateTree(2*idx+2, mid+1, high, node, value);
        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
        
    }
    void update(int index, int val) {
        updateTree(0, 0, n-1, index, val);
    }
    int getSum(int idx, int low, int high, int l, int r){
        // full overlap
        if(low>=l and high<=r)
            return segTree[idx];
        // null overlap
        if(l > high || r < low)
            return 0;
        //partial overlap
        int mid = low + (high-low)/2;
        int left = getSum(2*idx+1, low, mid, l, r);
        int right = getSum(2*idx+2, mid+1, high, l, r);
        
        return left + right;
    }
    int sumRange(int left, int right) {
        return getSum(0, 0, n-1, left, right);
    }
};