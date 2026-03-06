#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++)  
    cin >> a[i];

  vector<ll> dp(k + 1, 0);
  for (ll coin : a) {
    for (ll i = k; i >= coin; i--) {
      dp[i] = max(dp[i], dp[i - coin] + 1);
    }
  }

  cout << dp[k];

  return 0;
};