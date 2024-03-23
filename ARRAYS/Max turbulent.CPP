// 978. Longest Turbulent Subarray

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), max_turbulent = 1;
        vector<int> incr(n, 1), decr(n, 1);

        for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1])
                incr[i] = decr[i-1]+1;
            else if(arr[i]<arr[i-1])
                decr[i] = incr[i-1]+1;
            else
                incr[i] = decr[i] = 1;
            max_turbulent = max({max_turbulent, incr[i], decr[i]});
        }

        return max_turbulent;
    }
};