#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  if (n == 1)
  {
    cout << a[1];
    return 0;
  }

  if (n == 2)
  {
    cout << abs(a[1] - a[2]);
    return 0;
  }

  vector<ll> dp(n + 1, 0);
  dp[2] = abs(a[1] - a[2]);
  for (ll i = 3; i <= n; i++)
  {
    dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
  }
  cout << dp[n];

  return 0;
};