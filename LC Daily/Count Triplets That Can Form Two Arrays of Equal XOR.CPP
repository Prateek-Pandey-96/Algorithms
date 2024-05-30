// 1442. Count Triplets That Can Form Two Arrays of Equal XOR

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), count = 0;

        for(int i=0; i<n; i++){
            int rx = arr[i];
            for(int k=i+1; k<n; k++){
                rx ^= arr[k];
                if(rx == 0){
                    count += k-i;
                }
            }
        }

        return count;
    }
};