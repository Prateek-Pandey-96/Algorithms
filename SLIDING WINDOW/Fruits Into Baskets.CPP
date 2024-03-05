// 904. Fruit Into Baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> type_freq;
        int start = 0, end = 0;
        int n = fruits.size(), max_trees = INT_MIN;
        
        while(end < n){
            type_freq[fruits[end]]++;
            while(type_freq.size()>2){
                type_freq[fruits[start]]--;
                if(type_freq[fruits[start]]==0)
                    type_freq.erase(fruits[start]);
                start++;
            }

            max_trees = max(max_trees, end-start+1);
            end++;
        }

        return max_trees;
    }
};