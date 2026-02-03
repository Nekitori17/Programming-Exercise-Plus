#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, x;
  cin >> n >> x;
  vector<pair<ll, ll>> a;
  for (ll i = 0; i < n; i++)
  {
    ll t;
    cin >> t;
    a.push_back({t, i});
  }

  sort(a.begin(), a.end());
  ll l = 0, r = n - 1;
  while (l < r)
  {
    ll sum = a[l].first + a[r].first;
    if (sum == x)
    {
      cout << a[l].second + 1 << " " << a[r].second + 1;
      return 0;
    }
    else if (sum < x)
      l++;
    else
      r--;
  }

  cout << "IMPOSSIBLE";

  return 0;
};