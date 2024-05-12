// 518. Coin Change II

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Wrong answer treating {2, 2, 1} and {2, 1, 2} different
        // vector<int> ways(amount+1, 0);
        // ways[0] = 1;
        // for(int i=1; i<=amount; i++)
        //     for(int coin: coins)
        //         if(i-coin >= 0)
        //             ways[i] += ways[i-coin];
        // return ways[amount];

        //Correct answer removing duplicate combinations
        vector<int> ways(amount+1, 0);
        ways[0] = 1;
        for(int coin: coins){
            for(int i=0; i<=amount; i++){
                if(coin>i)
                    continue;
                ways[i] = ways[i] + ways[i-coin];
            }
        }
        return ways[amount];
    }
};