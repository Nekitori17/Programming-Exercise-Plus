#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("BAI3.inp", "r", stdin);
  freopen("BAI3.out", "w", stdout);

  ll n;
  cin >> n;

  ll sz = 0;
  vector<ll> da(sz);
  while (n--) {
    ll u, v;
    cin >> u >> v;
    sz = max(sz, v + 2);
    da.resize(sz);

    da[u] += 1;
    da[v + 1] -= 1;
  }

  for (ll i = 1; i < sz; i++) {
    da[i] += da[i - 1];
  }

  ll q;
  cin >> q;
  while (q--) {
    ll x;
    cin >> x;
    cout << da[x] << "\n";
  }

  return 0;
};