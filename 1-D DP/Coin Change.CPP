// 322. Coin Change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ways(amount+1, INT_MAX);
        ways[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int coin: coins){
                if(coin<=i and ways[i-coin]!=INT_MAX)
                    ways[i] = min(ways[i], 1+ways[i-coin]);
            }
        }
        return ways[amount]==INT_MAX? -1: ways[amount];
    }
};