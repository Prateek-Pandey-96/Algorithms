//946. Validate Stack Sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int popped_idx = 0;
        for(int element: pushed){
            st.push(element);

            while(popped_idx < popped.size() and !st.empty() and popped[popped_idx]==st.top())
            { 
                st.pop();
                popped_idx++;
            }
        }

        return st.empty();
    }
};