// 212. Word Search II

class Solution {
public:
    struct TrieNode{
        bool isLeaf;
        TrieNode* children[26];
        TrieNode()
        {
            for(int i=0; i<26; i++)
                children[i] = NULL;
            isLeaf = false;
        }
    };
    void addWord(string word, TrieNode* root){
        TrieNode* crawl = root;
        for(int i=0;i<(int)word.length();i++){
            int idx = word[i]-'a';
            if(crawl->children[idx]==NULL)
                crawl->children[idx] = new TrieNode();
            crawl = crawl->children[idx];
        }
        crawl->isLeaf = true;
    }
    // returns 1 for word 0 for prefix and -1 if prefix not there
    int searchWord(string word, TrieNode* root){
        TrieNode* curr = root;
        for(int i=0;i<(int)word.length();i++){
            if(curr->children[word[i]-'a']==NULL)
                return -1;
            curr = curr->children[word[i]-'a'];
        }
        return curr->isLeaf == true? 1: 0;
    }
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    void DFS(int x, int y, string curr, vector<vector<char>>& board, TrieNode* root, unordered_set<string>& words){
        char t = board[x][y];
        board[x][y]='#';

        curr.push_back(t);
        int search = searchWord(curr, root);
 
        if(search == -1)
        {
            curr.pop_back();
            board[x][y] = t;
            return;
        }
        else if(search == 1)
            words.insert(curr);
        
        for(int i=0; i<4; i++){
            int newx = x + dx[i], newy = y + dy[i];
            if(newx >= 0 and newy >= 0 and newx < m and newy < n and board[newx][newy]!='#'){
                DFS(newx, newy, curr, board, root, words);
            }
        }
            
        curr.pop_back();
        board[x][y]=t;
    }
    int m, n;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        int totalWords = words.size();
        // create the tree
        TrieNode* root = new TrieNode();
        for(auto word: words)
            addWord(word, root);
        
        unordered_set<string> found;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                DFS(i, j, "", board, root, found);
            }
        }
        vector<string> result;
        for(auto word: found)
            result.push_back(word);
        
        return result;
    }
};