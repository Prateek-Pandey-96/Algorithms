// 1209. Remove All Adjacent Duplicates in String II

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(char ch: s){
            if(st.empty())
                st.push({ch, 1});
            else{
                auto [top, freq] = st.top();
                if(top == ch){
                    st.pop();
                    if(freq+1 < k)
                        st.push({ch, freq+1});
                }else{
                    st.push({ch, 1});
                }
            }
        }
        string result;
        while(!st.empty()){
            auto [top, freq] = st.top();
            st.pop();
            while(freq--){
                result.push_back(top);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};