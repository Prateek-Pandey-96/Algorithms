// 1626. Best Team With No Conflicts

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int, int>> age_scores;
        for(int i=0; i<n; i++)
            age_scores.push_back({ages[i], scores[i]});
        sort(age_scores.begin(), age_scores.end());
        
        vector<int> possible_scores(n, 0);
        possible_scores[0] = age_scores[0].second;
        
        int max_score = possible_scores[0];
        for(int i=1; i<n; i++){
            possible_scores[i] = age_scores[i].second;
            for(int j=i-1; j>=0; j--){
                if(age_scores[i].second >= age_scores[j].second)
                    possible_scores[i] = max(possible_scores[i], age_scores[i].second + possible_scores[j]);
            }
            max_score = max(max_score, possible_scores[i]);
        }

        return max_score;
    }
};