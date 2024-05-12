// 2410. Maximum Matching of Players With Trainers

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int matchings = 0, p = players.size(), t = trainers.size();
        int trainer_idx = 0, player_idx = 0;

        while(player_idx < p and trainer_idx < t){
            if(trainers[trainer_idx] >= players[player_idx]){
                player_idx++;
                trainer_idx++;
                matchings++;
            }else{
                trainer_idx++;
            }
        }

        return matchings;
    }
};