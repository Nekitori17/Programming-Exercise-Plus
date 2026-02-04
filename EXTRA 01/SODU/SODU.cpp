#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("SODU.inp", "r", stdin);
  freopen("SODU.out", "w", stdout);

  ull a, b, c;
  cin >> a >> b >> c;

  ull res = a;
  for (ull i = 0; i < b - 1; i++)
  {
    res *= a;
  }

  cout << res % c;

  return 0;
};