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
  for (int i = 0; i < n; i++)
    cin >> a[i];

  unordered_map<ll, ll> mp;
  mp[0] = 1;

  ll sum = 0, res = 0;
  for (int i = 0; i < n; i++)
  {
    sum += a[i];
    res += mp[sum - x];
    mp[sum]++;
  }

  cout << res;

  return 0;
};