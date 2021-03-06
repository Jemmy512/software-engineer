/* Easy
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Relatives:
070. Climbing Statirs
746. Min Cost Climbing Stairs
509. Fibonacci Number
1137. N-th Tribonacci Number */

#include <iostream>
#include <vector>

using namespace std;

/* DP equation: S[i] = S[i-1] + S[i-2]
 * Time Complexity: O(N)
 * Space Complexity: O(1) */
int climbStairs(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    // vector<int> steps(n+1);
    // steps[1] = 1;
    // steps[2] = 2;

    int one_before = 2; // refers to the number of solution until the point [n - 1]
    int two_before = 1; // refers to the number of solution unitl the potin [n - 2]
    int ways = 0;

    for (int i = 3; i <= n; ++i) {
        ways = one_before + two_before;
        two_before = one_before;
        one_before = ways;
    }

    return ways;
}

int climbStairs(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    vector<int> steps(n+1);
    steps[1] = 1;
    steps[2] = 2;
    int cnt = 0;

    for (int i = 3; i <= n; ++i) {
        steps[i] = steps[i-1] + steps[i-2];
    }

    return steps[n];
}