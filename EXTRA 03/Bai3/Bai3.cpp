#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("Bai3.inp", "r", stdin);
  freopen("Bai3.out", "w", stdout);

  string S;
  cin >> S;

  vector<string> dict;
  string t;
  while (cin >> t)
    dict.push_back(t);

  int n = S.size();
  int m = dict.size();

  const int INF = 1e9;

  vector<int> dp(n + 1, INF);
  vector<int> trace(n + 1, -1);
  vector<int> prev(n + 1, -1);

  dp[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      int len = dict[j].size();

      if (i >= len)
      {

        if (S.substr(i - len, len) == dict[j])
        {

          if (dp[i] > dp[i - len] + 1)
          {
            dp[i] = dp[i - len] + 1;
            trace[i] = j + 1;
            prev[i] = i - len;
          }
        }
      }
    }
  }

  if (dp[n] == INF)
  {
    cout << 0;
    return 0;
  }

  cout << dp[n] << "\n";

  vector<int> ans;

  int cur = n;

  while (cur > 0)
  {
    ans.push_back(trace[cur]);
    cur = prev[cur];
  }

  reverse(ans.begin(), ans.end());

  for (int x : ans)
    cout << x << " ";

  return 0;
}