#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, q;
  cin >> n >> q;

  vector<ll> d(n + 2, 0);

  while (q--)
  {
    ll l, r, v;
    cin >> l >> r >> v;
    d[l] += v;
    d[r + 1] -= v;
  }

  ll cur = 0;
  for (ll i = 1; i <= n; i++)
  {
    cur += d[i];
    cout << cur << " ";
  }

  return 0;
}
