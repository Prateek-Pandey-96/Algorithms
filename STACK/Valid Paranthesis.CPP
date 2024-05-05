// 20. Valid Parentheses

class Solution {
public:
    bool isPair(char a, char b){
        return (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']');
    }
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s){
            if(ch=='('||ch=='{'||ch=='[')
                st.push(ch);
            else{
                if(st.empty())
                    return false;
                if(isPair(st.top(), ch))
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};