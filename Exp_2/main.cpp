class Solution {
public:
    double helper(double x, int n, unordered_map<int, double> &dp) {
        if (dp.find(n) != dp.end())
            return dp[n];
        else if(x == 0) dp[n] = 0;
        else if(x == 1) dp[n] = 1;
        else if (n % 2 == 0)
            dp[n] = helper(x, n / 2, dp) * helper(x, n / 2, dp);
        else
            dp[n] = x * helper(x, (n - 1) / 2, dp) * helper(x, (n - 1) / 2, dp);

        return dp[n];
    }
    double myPow(double x, int n) {
        if(x == -1) return (n%2 == 0)? 1 : -1;
        unordered_map<int, double> dp;
        dp[1] = (n < 0)? 1/x : x; dp[0] = 1;
        if(n == INT_MIN) return (1/x) * helper(1/x,INT_MAX,dp);
        return (n < 0) ? helper(1/x,-n,dp) : helper(x,n,dp);
    }
};