#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("DIVISOR.inp", "r", stdin);
  freopen("DIVISOR.out", "w", stdout);

  ll n, x;
  cin >> n >> x;

  vector<ll> res;
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      res.push_back(i);
      if (n / i != i)
        res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());

  if (x > 0 && x < res.size())
    cout << res[x - 1];
  else
    cout << -1;

  return 0;
};