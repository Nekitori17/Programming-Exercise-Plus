#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll x, ll k, vector<ll> &a)
{
  ll g = 0, cs = 0;

  for (ll &i : a)
  {
    cs += i;
    if (cs > x)
    {
      g++;
      cs = i;
    }
  }

  if (cs > 0)
    g++;

  return g <= k;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (ll &i : a)
    cin >> i;

  ll ans = 0;
  ll l = 0, r = 0;
  for (ll &i : a)
  {
    l = max(l, i);
    r += i;
  }

  while (l <= r)
  {
    ll m = l + (r - l) / 2;
    if (check(m, k, a))
    {
      ans = m;
      r = m - 1;
    }
    else
      l = m + 1;
  }

  cout << ans;

  return 0;
};