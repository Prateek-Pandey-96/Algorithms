// 2240. Number of Ways to Buy Pens and Pencils

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int pens = total/cost1;
        long long ways = 0;

        for(int pen=pens; pen>=0; pen--)
            ways = ways + (long long)(total - cost1*pen)/cost2 + (long long)1;

        return ways;
    }
};