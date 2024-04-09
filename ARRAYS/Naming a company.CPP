// 2306. Naming a Company

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<int, unordered_set<string>> suffixes;
        long long total_names = 0;
        for(string idea: ideas){
            if(idea.length()>1)
                suffixes[idea[0]-'a'].insert(idea.substr(1));
            else
                suffixes[idea[0]-'a'].insert("");
        }

        for(auto [key, val]: suffixes){
            unordered_set<string> a = val;
            for(auto [key2, val2]: suffixes){
                if(key==key2)
                    continue;
                unordered_set<string> b = val2;

                int common_suffix_count = 0;
                for(auto str: a)
                    if(b.contains(str))
                        common_suffix_count++;
                
                total_names += (a.size()-common_suffix_count)*(b.size()-common_suffix_count);
            }
        }

        return total_names;
    }
};