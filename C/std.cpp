#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string expr;  // 表达式
vector<ll>nums;  // 被+间隔的数字

ll dfs(ll currentNum, int position) {
    if (position == (int)expr.size()) {
        // 如果遍历完整个表达式，则对nums求和，并加上curr
        return accumulate(nums.begin(), nums.end(), currentNum);
    }
    ll ans = 0;
    // 这里对两种情况进行搜索
    // 不在当前这一位数字前放加号
    ans += dfs(currentNum * 10 + expr[position] - '0', position + 1);
    // 在当前这一位数字前放加号
    nums.push_back(currentNum);
    ans += dfs(expr[position] - '0', position + 1);
    // 记得还原nums数组
    nums.pop_back();
    return ans;
}

void solve() {
    cin >> expr;
    // 由于dfs会使得表达式重复，故需除2
    cout << dfs(0, 0) / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}