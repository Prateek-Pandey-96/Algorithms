// 648. Replace Words - Using HashSet

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> hashset(dictionary.begin(), dictionary.end());
        vector<string> words;
        string temp;
        for(char ch: sentence){
            if(ch==' '){
                words.push_back(temp);
                temp.clear();
            }else{
                temp.push_back(ch);
            }
        }
        words.push_back(temp);
        temp.clear();

        string ans = "";
        for(string word: words){
            bool found = false;
            temp.clear();
            for(char ch: word){
                temp.push_back(ch);
                if(hashset.contains(temp)){
                    ans += temp + " ";
                    found = true;
                    break;
                }
            }
            if(!found)
                ans += word + " ";
        }
        if(ans.length())
            ans.pop_back();
        return ans;
    }
};

// Trie solution
class Solution {
public:
    struct TrieNode{
        bool isLeaf;
        TrieNode* children[26];
        TrieNode(){
            isLeaf = false;
            for(int i=0; i<26; i++)
                children[i] = NULL;
        }
    };
    
    void addWord(TrieNode* root, string word){
        TrieNode* crawl = root;
        for(char ch: word){
            if(!crawl->children[ch-'a'])
                crawl->children[ch-'a'] = new TrieNode();
            crawl = crawl->children[ch-'a'];
        }
        crawl->isLeaf = true;
    }

    string getPrefix(TrieNode* root, string word){
        TrieNode* crawl = root;
        string prefix;
        for(char ch: word){
            if(!crawl->children[ch-'a'])
                break;
            crawl = crawl->children[ch-'a'];
            prefix.push_back(ch);

            if(crawl->isLeaf)
                return prefix;
        }
        if(crawl->isLeaf)
                return prefix;
        return "";
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        for(auto word: dictionary)
            addWord(root, word);
        
        string temp, ans = "";
        for(char ch: sentence){
            if(ch==' '){
                string prefix = getPrefix(root, temp); 
                ans += (prefix!=""? prefix: temp)  + " ";
                temp.clear();
            }else{
                temp.push_back(ch);
            }
        }
        string prefix = getPrefix(root, temp); 
        ans += (prefix!=""? prefix: temp)  + " ";
        if(ans.length())
            ans.pop_back();
        return ans;
    }
};