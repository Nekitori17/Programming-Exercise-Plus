#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("CHIAK.inp", "r", stdin);
  freopen("CHIAK.out", "w", stdout);

  ll n, k;
  cin >> n >> k;

  map<ll, ll> mp;
  mp[0] = 1;

  ll cs = 0, ans = 0;
  for (ll i = 0; i < n; i++)
  {
    ll x; cin >> x;
    cs += x;

    ll rem = ((cs % k) + k) % k;

    ans += mp[rem];
    mp[rem]++;
  }

  cout << ans;

  return 0;
};