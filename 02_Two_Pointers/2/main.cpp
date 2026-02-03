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
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  ll count = 0, sum = 0, l = 0;
  for (ll r = 0; r < n; r++)
  {
    sum += a[r];

    while (l <= r && sum > x)
    {
      sum -= a[l];
      l++;
    }

    if (sum == x)
      count++;
  }

  cout << count;

  return 0;
};