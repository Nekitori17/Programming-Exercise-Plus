#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("SUM.inp", "r", stdin);
  freopen("SUM.out", "w", stdout);

  ll n;
  cin >> n;

  unordered_map<ll, ll> cnt;
  cnt[0] = 1;

  ll sum = 0, ans = 0;

  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;

    sum += x;
    ans += cnt[sum];
    cnt[sum]++;
  }

  cout << ans;
}