#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> adj(n + 1);
  for (int i = 0; i < m; i++)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  vector<ll> dist(n + 1, INF);
  dist[1] = 0;

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0, 1});

  while (!pq.empty())
  {
    ll d = pq.top().first;
    ll u = pq.top().second;
    pq.pop();

    if (d > dist[u])
      continue;

    for (pair<ll, ll> edge : adj[u])
    {
      ll v = edge.first;
      ll w = edge.second;

      if (dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << dist[i] << " ";
  }

  return 0;
};