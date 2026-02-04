#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("XOAPHANTU.inp", "r", stdin);
  freopen("XOAPHANTU.out", "w", stdout);

  ll n, x;
  cin >> n >> x;

  ll nb = 1e18;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    nb = min(nb, abs(a[i] - x));
  }

  for (ll &i : a)
    if (abs(i - x) != nb)
      cout << i << " ";

  return 0;
};