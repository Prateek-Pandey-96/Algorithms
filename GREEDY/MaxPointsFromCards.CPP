// 1423. Maximum Points You Can Obtain from Cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), sum = 0, max_score = 0;
        for(int i=0; i<k; i++){
            sum += cardPoints[i];
        }
        max_score = sum;

        for(int i=0; i<k; i++){
            sum += cardPoints[n-1-i] - cardPoints[k-1-i];
            max_score = max(max_score, sum);
        }

        return max_score;
    }
};