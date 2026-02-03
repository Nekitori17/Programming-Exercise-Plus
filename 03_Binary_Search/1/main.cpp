#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll h, ll x, vector<ll> &a)
{
  ll sum = 0;
  for (ll &i : a)
  {
    if (i > h)
      sum += i - h;
  }

  return sum >= x;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (ll &i : a)
    cin >> i;

  ll ans = 0;
  ll left = 1, right = *max_element(a.begin(), a.end());
  while (left <= right)
  {
    ll mid = left + (right - left) / 2;
    if (check(mid, x, a))
      ans = mid,
      left = mid + 1;
    else
      right = mid - 1;
  }

  cout << ans;

  return 0;
};