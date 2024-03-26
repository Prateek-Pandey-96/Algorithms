// Ways to split string
#include <bits/stdc++.h>
using namespace std;

int getWays(string s){
    int n = s.length();
    unordered_map<char, int> freq, curr;
    for(char ch: s)
        freq[ch]++;
    
    // imaginary line between i and i+1
    int count = 0;
    for(int i=0; i<n-1; i++){
        curr[s[i]]++;
        freq[s[i]]--;
        if(freq[s[i]]==0)
            freq.erase(s[i]);
        if(curr.size()==freq.size())
            count++;
    }
    return count;
}

int main() {
    cout<<getWays("ababa")<<endl;
    return 0;
}