#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
string bin;

void backtrack(ll pos)
{
    if (pos == n)
    {
        cout << bin << '\n';
        return;
    }

    bin[pos] = '0';
    backtrack(pos + 1);

    bin[pos] = '1';
    backtrack(pos + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);

    cin >> n;
    bin.resize(n);

    backtrack(0);

    return 0;
}
