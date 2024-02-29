// 71. Simplify Path

class Solution {
public:
    string simplifyPath(string path) {
        /* Implementation based problem */
        stack<string> st;
        string curr, canonicalPath;
        
        /*Seperation based on slashes*/
        for(auto ch: path){
            if(ch!='/'){
                curr.push_back(ch);
            }else{
                if(curr.size() and curr!=".")
                    st.push(curr);
                curr = "";
            }
        }
        if(curr.size() and curr!=".")
            st.push(curr);
        
        /*Temp will contain either ".." or "directory_name" */
        vector<string> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        
        vector<string> cleanedTemp;
        for(auto str: temp){
            if(str != "..")
                cleanedTemp.push_back("/"+str);
            else if(cleanedTemp.size())
                cleanedTemp.pop_back();
        }

        for(auto str: cleanedTemp)
            canonicalPath += str;

        return canonicalPath.size()? canonicalPath: "/";
    }
};