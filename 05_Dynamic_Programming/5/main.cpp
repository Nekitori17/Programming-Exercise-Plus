#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll N, L, T;
  cin >> N >> L >> T;

  vector<pair<ll, ll>> cars(N + 1);
  for (int i = 1; i <= N; i++)
    cin >> cars[i].first >> cars[i].second;

  vector<double> dp(N + 1, 1e18);
  dp[0] = 0;

  for (int i = 1; i <= N; i++)
  {
    ll sumP = 0;
    ll minV = 1e18;

    for (int j = i; j >= 1; j--)
    {
      sumP += cars[j].second;
      if (sumP > T)
        break;

      minV = min(minV, cars[j].first);

      double time = (double)L / minV;

      dp[i] = min(dp[i], dp[j - 1] + time);
    }
  }

  cout << fixed << setprecision(6) << dp[N];
}