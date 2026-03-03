#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("BAI2.inp", "r", stdin);
  freopen("BAI2.out", "w", stdout);

  string s;
  cin >> s;

  ull sum = 0;
  string tmp;
  for (char c : s)
  {
    if (c >= '0' && c <= '9')
    {
      tmp += c;
      continue;
    }

    if (tmp.size())
    {
      sum += stoll(tmp);
      tmp = "";
    }
  }

  if (tmp.size()) sum += stoll(tmp);

  cout << sum;

  return 0;
};