#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);
  
  ll n, q;
  cin >> n >> q;
  
  vector<ll> c(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
    ll j;
    cin >> j;
    c[i] = c[i-1] + j;
  }
  
  for (ll i = 0; i < q; i++) {
    ll l, r;
    cin >> l >> r;
    cout << c[r] - c[l - 1] << "\n";
  }
  
  return 0;
}