#include <bits/stdc++.h>
using namespace std;
int dpt[100] = {0};

int topDowm(int n)
{
    int a, b, c;
    a = b = c = INT_MAX;
    if (n == 1 || n == 0)
        return 0;

    if (dpt[n] != 0)
        return dpt[n];

    if (n % 2 == 0)
    {
        a = topDowm(n / 2);
    }
    if (n % 3 == 0)
    {
        b = topDowm(n / 3);
    }
    c = topDowm(n - 1);
    dpt[n] = min(min(a, b), c) + 1;

    return dpt[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
        dp[i] = 1 + min(min(i % 2 == 0 ? dp[i / 2] : INT_MAX, i % 3 == 0 ? dp[i / 3] : INT_MAX), dp[i - 1]);
    topDowm(n);
    cout << dp[n] << " " << dpt[n];
    return 0;
}
