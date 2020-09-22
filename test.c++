#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, long long> dp;

int helper(int n) {
    if (n == 1) {
        return 0;
    }
    if (dp[n] > 0) {
        return dp[n];
    }
    int a = helper(n - 1);
    int min_val = a;
    if (n % 2 == 0) {
        int b = helper(n / 2);
        min_val = min(min_val, b);
    }
    return dp[n] = min_val + 1;
}

int main() {
    int n;
    cin >> n;
    //memset(dp, 0, sizeof(dp));
    cout << helper(n) << endl;
    return 0;
}