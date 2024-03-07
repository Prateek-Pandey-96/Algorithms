// 752. Open the Lock

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        queue<pair<string, int>> q;

        if(deadset.contains("0000") || deadset.contains(target))
            return -1;
        
        q.push({"0000", 0});
        deadset.insert("0000");


        while(!q.empty()){
            int size = q.size();
            while(size--){
                string front = q.front().first;
                int moves = q.front().second;
                q.pop();
                if(front == target)
                    return moves;
                
                for(int pos=0; pos<4; pos++){
                    char prevChar = front[pos]; 
                    string newCombination1 = front, newCombination2 = front;
                    char ch1 = (prevChar-'0' + 1)%10 + '0';
                    char ch2 = (10 + prevChar-'0' - 1)%10 + '0';
                    newCombination1[pos] = ch1;
                    newCombination2[pos] = ch2;
                    if(!deadset.contains(newCombination1)){
                        deadset.insert(newCombination1);
                        q.push({newCombination1, moves + 1});
                    }
                    if(!deadset.contains(newCombination2)){
                        deadset.insert(newCombination2);
                        q.push({newCombination2, moves + 1});
                    }
                }
            }
        }
        return -1;
    }
};