// 1247. Minimum Swaps to Make Strings Equal

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length(), xy = 0, yx = 0;
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i] and s1[i]=='x')
                xy++;
            else if(s1[i]!=s2[i] and s1[i]=='y')
                yx++;
        }

        if(xy%2 != yx%2)
            return -1;
        return xy/2 + yx/2 + (xy%2)*2;
    }
};