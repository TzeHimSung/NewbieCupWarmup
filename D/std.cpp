#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    cout << max(1, min(n, x + y + 1 - n)) << ' ' << min(x + y - 1, n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}