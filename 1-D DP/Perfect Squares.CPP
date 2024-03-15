// 279. Perfect Squares

class Solution {
public:
    int numSquares(int n) {
        vector<int> count(n+1, INT_MAX);
        count[0] = 0;

        for(int i=1; i<=n; i++){
            for(int j=sqrt(i); j>=1; j--){
                int rem = i - j*j;
                if(rem == 0)
                {
                    count[i] = 1;
                    break;
                }
                else
                {
                    count[i] = min(count[i], count[rem]+1);
                }
            }
        }

        return count[n];
    }
};