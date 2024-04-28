#include <bits/stdc++.h>
using namespace std;
int segTree[10000];

void build(int idx, int low, int high, vector<int>& arr){
    if(low == high){
        segTree[idx] = arr[low];
        return;
    }
    
    int mid = low + (high-low)/2;
    build(2*idx+1, low, mid, arr);
    build(2*idx+2, mid+1, high, arr);
    segTree[idx] = max(segTree[2*idx+1], segTree[2*idx+2]);
}

void update(int idx, int low, int high, int node, int value, vector<int>& arr){
    if(low == high){
        segTree[idx] = value;
        return;
    }
    
    int mid = low + (high-low)/2;
    if(node <= mid and node >= low)
        update(2*idx+1, low, mid, node, value, arr);
    else
        update(2*idx+2, mid+1, high, node, value, arr);
    segTree[idx] = max(segTree[2*idx+1], segTree[2*idx+2]);
    
}

int query(int idx, int low, int high, int l, int r, vector<int>& arr){
    // full overlap
    if(low>=l and high<=r)
        return segTree[idx];
    // null overlap
    if(l > high || r < low)
        return INT_MIN;
    //partial overlap
    int mid = low + (high-low)/2;
    int left = query(2*idx+1, low, mid, l, r, arr);
    int right = query(2*idx+2, mid+1, high, l, r, arr);
    
    return max(left, right);
}
/* Segment trees */
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 2, 1, 8};

    build(0, 0, 9, arr);

    int q;
    cin>>q;
    int ctr = 0;
    while(q--){
        int x, y;
        cin>>x>>y;
        if(ctr++ == 0)
            update(0, 0, 9, 4, 18, arr);
        else
            update(0, 0, 9, 9, 1, arr);
        cout<<query(0, 0, 9, x, y, arr)<<endl;
    }
    return 0;
}