#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool check(ll x, ll t, vector<ll> &a)
{
  ll sum = 0;
  for (ll &m : a)
  {
    ll o;
    o = x / m;
    sum += o;
    if (sum >= t)
      return true;
  }

  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, t;
  cin >> n >> t;
  vector<ll> a(n);
  for (ll &i : a)
    cin >> i;

  ll ans = 0;
  ull l = 1, r = t * *min_element(a.begin(), a.end());
  while (l <= r)
  {
    ll mid = l + (r - l) / 2;
    if (check(mid, t, a))
    {
      ans = mid;
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }

  cout << ans;

  return 0;
};