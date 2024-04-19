// 127. Word Ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(!words.contains(endWord))
            return 0;
        queue<string> q;
        int level = 0;
        q.push(beginWord);
        words.erase(beginWord);

        while(!q.empty()){
            level += 1;

            int size = q.size();
            while(size--){
                string front = q.front();
                q.pop();
                if(front == endWord)
                    return level;
                for(int i=0; i<front.size(); i++){
                    for(char ch = 'a'; ch<='z'; ch++){
                        if(ch==front[i])
                            continue;
                        char temp = front[i];
                        front[i] = ch;
                        if(words.contains(front)){
                            q.push(front);
                            words.erase(front);
                        }
                        front[i] = temp;
                    }
                }
            }
        }
        return 0;
    }
};