// 846. Hand of Straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize)
            return false;
        
        sort(hand.begin(), hand.end());
        
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++)
            freq[hand[i]]++;
        
        for(int i=0; i<n; i++){
            if(freq[hand[i]]!=0){
                int k = groupSize;
                int curr = hand[i];
                while(k--){
                    if(freq[curr]){
                        freq[curr]--;
                        curr++;
                    }else{
                        return false;
                    }
                }
            }
        }

        return true;
    }
};