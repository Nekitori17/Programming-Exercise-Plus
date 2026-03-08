#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;

vector<int> adj[MAXN];
ll dp[MAXN][2];
int N;

void dfs(int u, int parent)
{
  dp[u][0] = 0;
  dp[u][1] = 1;

  for (int v : adj[u])
  {
    if (v == parent)
      continue;

    dfs(v, u);

    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += dp[v][0];
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  cin >> N;

  for (int i = 1; i < N; i++)
  {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);

  cout << max(dp[1][0], dp[1][1]);

  return 0;
}