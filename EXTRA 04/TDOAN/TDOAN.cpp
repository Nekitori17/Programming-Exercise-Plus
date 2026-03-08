#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e9;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("TDOAN.inp", "r", stdin);
  freopen("TDOAN.out", "w", stdout);

  ll N, K;
  cin >> N >> K;
  vector<ll> a(N + 1);
  for (ll i = 1; i <= N; i++)
    cin >> a[i];

  ll sum = 0;
  ll L = 1;
  ll bestL = INF, bestD = 0;
  for (ll R = 1; R <= N; R++)
  {
    sum += a[R];

    while (a[L] == 0) {
      L++;
    }

    while (sum > K && L < R)
    {
      sum -= a[L];
      L++;
    }

    if (sum != K)
      continue;

    ll lg = R - L + 1;
    if (lg <= bestL)
    {
      bestL = lg;
      bestD = L;
    }
  }

  if (bestL == INF)
  {
    cout << 0;
  }
  else
  {
    cout << bestD << "\n";
    cout << bestL;
  }

  return 0;
};