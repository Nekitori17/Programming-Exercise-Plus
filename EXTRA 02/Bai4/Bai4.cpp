#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;
ll ans = 0;

void traceback(ll cs, ll hs, ll hk, bool izf) {
  if (cs > n) return;
  if (hk > k) return;
  if (hk == k && !izf) {
    ans++;
  }
  
  traceback(cs + hs, hs * 2, hk, false);
  traceback(cs, hs * 2, hk + 1, true);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("BAI4.inp", "r", stdin);
  freopen("BAI4.out", "w", stdout);

  cin >> n >> k;

  traceback(0, 1, 0, true);

  cout << ans;

  return 0;
};