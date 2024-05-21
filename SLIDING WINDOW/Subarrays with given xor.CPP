int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> hashmap;
    
    int xr = 0, total = 0;
    for(int i=0; i<n; i++){
        xr ^= A[i];
        if(xr == B)
            total++;

        if(hashmap.find(xr^B)!=hashmap.end())
            total += hashmap[xr^B];
        
        hashmap[xr]++;
    }
    
    return total;
}
