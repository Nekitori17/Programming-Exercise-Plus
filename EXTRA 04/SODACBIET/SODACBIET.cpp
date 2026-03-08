#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("SODACBIET.inp", "r", stdin);
  freopen("SODACBIET.out", "w", stdout);

  ll L, R;
  cin >> L >> R;
  vector<vector<ll>> uoc(R + 1);
  for (ll i = 1; i <= R; i++) {
    for (ll j = i; j <= R; j += i) {
      uoc[j].push_back(i);
    }
  }

  ll ans = 0;
  for (ll i = L; i <= R; i++) {
    ll sum = accumulate(uoc[i].begin(), uoc[i].end(),0LL);
    ll result = sum - i;
    if (result > i) ans++;
  }

  cout << ans;

  return 0;
};