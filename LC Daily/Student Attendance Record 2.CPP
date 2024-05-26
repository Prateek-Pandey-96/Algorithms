// 552. Student Attendance Record II

class Solution {
public:
    int mod = 1e9 + 7;
    int dp[100001][2][3];
    int helper(int day, int absents, int lates, char prev){
        if(day==0)
            return 1;
        if(dp[day][absents][lates]!=-1)
            return dp[day][absents][lates];

        int present_today = helper(day-1, absents, 0, 'P');
        int absent_today = 0, late_today = 0;
        if(!absents)
            absent_today = helper(day-1, absents+1, 0, 'A');
        if(lates<2)
            late_today = helper(day-1, absents, lates+1, 'L');
        
        return dp[day][absents][lates] = (present_today + (absent_today + late_today)%mod)%mod;
    }
    int checkRecord(int n) {
        // each day student can be present, absent or late
        // absent count cant exceed 1
        // late count cant exceed 2 consequtive

        memset(dp, -1, sizeof dp);
        return helper(n, 0, 0, 'P');
    }
};