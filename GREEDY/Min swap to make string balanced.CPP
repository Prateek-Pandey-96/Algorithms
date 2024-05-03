// 1963. Minimum Number of Swaps to Make the String Balanced

class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int open = 0, j = n-1, count = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='[')
                open++;
            else{
                open--;
                if(open<0)
                {
                    open = 1;
                    while(j>i and s[j]!='[')
                        j--;
                    swap(s[i], s[j]);
                    count++;
                    j--;
                }
            }
        }
        return count;
    }
};