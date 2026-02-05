#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans = 1e18;
ll sum_1 = 0, sum_2 = 0;
vector<ll> a;

void backtrack(ll i) {
  if (i == a.size()) {
    ans = min(ans, abs(sum_1 - sum_2));
    return;
  }

  sum_1 += a[i];
  backtrack(i + 1);
  sum_1 -= a[i];

  sum_2 += a[i];
  backtrack(i + 1);
  sum_2 -= a[i];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n;
  cin >> n;
  a.resize(n);
  for (ll &i : a)
    cin >> i;
  
  backtrack(0);
  cout << ans;

  return 0;
};