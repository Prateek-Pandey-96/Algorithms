// 1404. Number of Steps to Reduce a Number in Binary Representation to One

class Solution {
public:
    // greedy
    int numSteps(string s) {
        int n = s.length(), steps = 0, i = n-1;
        while(i>=0){
            if(s[i]=='0'){
                steps+=1;
                i--;
            }else{
                if(i==0)
                    break;
                //find next 0
                int j = i;
                while(j>=0 and s[j]=='1')
                {
                    j--;
                    steps+=1;
                }
                steps+=1;
                if(j>=0)
                    s[j]='1';
                i = j;
            }
        }
        return steps;
    }
};