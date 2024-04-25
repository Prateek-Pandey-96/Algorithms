// 790. Domino and Tromino Tiling

class Solution {
public:
    int numTilings(int n) {
        if(n<=2)
            return n;
        
        vector<long> full(n+1, 0), partTop(n+1, 0), partBottom(n+1, 0);
        long mod = 1e9 + 7;
        full[1] = 1;
        full[2] = 2;
        partTop[2] = 1;
        partBottom[2] = 1;

        for(int i=3; i<=n; i++){
            full[i] = ((full[i-1] + full[i-2])%mod + (partTop[i-1] + partBottom[i-1])%mod)%mod;
            partTop[i] = (partBottom[i-1] + full[i-2])%mod;
            partBottom[i] = (partTop[i-1] + full[i-2])%mod; 
        }

        return (int)full[n];
    }
};