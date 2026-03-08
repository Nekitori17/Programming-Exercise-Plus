#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int N, M;

struct Edge
{
  int u, v;
  ll w;
};

vector<pair<int, ll>> adj[105];
vector<Edge> edges;

ll dista[105];
int parent[105];

void dijkstra(int s, int ban_u, int ban_v)
{

  for (int i = 1; i <= N; i++)
  {
    dista[i] = INF;
    parent[i] = -1;
  }

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

  dista[s] = 0;
  pq.push({0, s});

  while (!pq.empty())
  {

    auto [d, u] = pq.top();
    pq.pop();

    if (d != dista[u])
      continue;

    for (auto [v, w] : adj[u])
    {

      if ((u == ban_u && v == ban_v) || (u == ban_v && v == ban_u))
        continue;

      if (dista[v] > d + w)
      {

        dista[v] = d + w;
        parent[v] = u;

        pq.push({dista[v], v});
      }
    }
  }
}

int main()
{

  cin >> N >> M;

  edges.resize(M);

  for (int i = 0; i < M; i++)
  {

    int u, v;
    ll w;

    cin >> u >> v >> w;

    edges[i] = {u, v, w};

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  ll best = INF;
  int bestK = 0;

  for (auto e : edges)
  {

    int u = e.u;
    int v = e.v;
    ll w = e.w;

    dijkstra(u, u, v);

    if (dista[v] == INF)
      continue;

    ll cycle = dista[v] + w;

    if (cycle < best)
    {

      best = cycle;

      int len = 1;
      int cur = v;

      while (cur != u)
      {
        cur = parent[cur];
        len++;
      }

      bestK = len + 1;
    }
  }

  if (best == INF)
  {

    cout << 0;
    return 0;
  }

  cout << 1 << "\n";
  cout << best << "\n";
  cout << bestK << "\n";
}