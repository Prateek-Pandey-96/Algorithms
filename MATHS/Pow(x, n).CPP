// 50. Pow(x, n)

class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
            return myPow(1/x,abs(n));
        if(n==0 || x==1)
            return 1.00;
        double temp = myPow(x,n/2);
        if(n%2)
            return x*temp*temp;
        else
            return temp*temp;
    }
};