#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("BAI1.inp", "r", stdin);
  freopen("BAI1.out", "w", stdout);

  ull n;
  cin >> n;

  ull kq = 0;
  while (n >= kq * kq) {
    n -= kq * kq;
    kq++;
  }

  cout << kq - 1 << "\n";
  cout << n;

  return 0;
}