#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, c;
  cin >> n >> c;
  vector<pair<ll, ll>> a(n + 1);
  for (ll i = 1; i <= n; i++)
  {
    cin >> a[i].first >> a[i].second;
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(c + 1, 0));
  for (ll i = 1; i <= n; i++)
  {
    for (ll j = 1; j <= c; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (j >= a[i].first)
      {
        dp[i][j] = max(
            dp[i][j],
            dp[i - 1][j - a[i].first] + a[i].second);
      }
    }
  }

  cout << dp[n][c] << endl;

  return 0;
};