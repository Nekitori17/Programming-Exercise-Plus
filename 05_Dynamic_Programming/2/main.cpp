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

  ll ans = 0;
  vector<ll> dp(n + 1, 0);
  dp[1] = 1;
  for (ll i = 2; i <= n; i++)
  {
    dp[i]++;

    for (ll j = i - 1; j >= 1; j--)
    {
      if (a[i] > a[j])
        dp[i] = max(dp[i], dp[j] + 1);
    }

    ans = max(ans, dp[i]);
  }

  cout << ans;

  return 0;
};