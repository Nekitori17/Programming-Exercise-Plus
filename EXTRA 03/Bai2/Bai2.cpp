#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("Bai2.inp", "r", stdin);
  freopen("Bai2.out", "w", stdout);

  ll n, k, b;
  cin >> n >> k >> b;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll sum = 0;
  ll s = (b - 1) % n;
  for (ll i = 0; i < k; i++) {
    sum += a[(s + i) % n];
  }

  cout << sum;

  return 0;
}