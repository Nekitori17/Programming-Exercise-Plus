#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> color;

void bfs(vector<vector<ll>> &fl, ll st)
{
  queue<ll> q;
  q.push(st);
  color[st] = 1;

  while (!q.empty())
  {
    ll u = q.front();
    q.pop();

    for (ll &v : fl[u])
    {
      if (color[v] == 0)
      {
        color[v] = 3 - color[u];
        q.push(v);
      }
      else
      {
        if (color[v] == color[u])
        {
          cout << "IMPOSSIBLE";
          exit(0);
        }
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, m;
  cin >> n >> m;
  color.resize(n + 1);
  vector<vector<ll>> fl(n + 1);
  for (int i = 0; i < m; i++)
  {
    ll a, b;
    cin >> a >> b;
    fl[a].push_back(b);
    fl[b].push_back(a);
  }

  for (int i = 1; i <= n; i++)
  {
    if (color[i] == 0)
    {
      bfs(fl, i);
    }
  }

  for (int i = 1; i <= n; i++)
    cout << color[i] << " ";

  return 0;
};