// 2337. Move Pieces to Obtain a String

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0, j = 0;
        for(int i=0; i<n; i++){
            if(start[i]!='_'){
                while(j<n and target[j]=='_')
                        j++;
                if((target[j]==start[i] and j<i and start[i]=='R') 
                || (target[j]==start[i] and j>i and start[i]=='L') 
                || target[j]!=start[i])
                    return false;
                else
                    j++;
            }
        }
        while(j<n){
            if(target[j]!='_')
                return false;
            j++;
        }
        return true;
    }
};