class Solution {
private:
    int memo[46] = {0};

public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        if (memo[n] != 0) return memo[n]; // Return cached answer
        
        return memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};