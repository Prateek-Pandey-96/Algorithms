// 846. Hand of Straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        unordered_map<int, int> freq;
        int n = hand.size();
        if(n%k)
            return false;
        
        for(int h: hand)
            freq[h]++;
        sort(hand.begin(), hand.end());
        
        for(int i=0; i<n; i++){
            if(freq.contains(hand[i])){
                int num = hand[i], curr = 0;
                while(freq.contains(num) and curr<k){
                    freq[num]--;
                    if(freq[num]==0)
                        freq.erase(num);
                    curr++;
                    num++;
                }
                if(curr!=k)
                    return false;
            }
        }
        return !freq.size();
    }
};