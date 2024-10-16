#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int TOTAL_PLAYERS = 6;

struct Player {
    string name;
    int r1_rank, r2_rank, score;

    Player() {}
    Player(string _name, int _r1_rank, int _r2_rank) {
        name = _name, r1_rank = _r1_rank, r2_rank = _r2_rank;
        score = _r1_rank + _r2_rank;
    }

    bool operator<(const Player& rhs) const {
        if (score != rhs.score) {
            return score < rhs.score;
        }
        // 同分时把jhseng放到后面
        // jhseng的总排名即为下标 + 1
        return name < rhs.name;
    }
};

int simulate(vector<int>& r1_rank, vector<int>& r2_rank) {
    // r1_rank, r2_rank分别代表每个玩家的第1、2轮排名
    // 默认第一个为jhseng排名
    vector<string>player_name = { "j", "a", "b", "c", "d", "e" };
    // 计算jhseng排名
    vector<Player>player;
    for (int i = 0; i < TOTAL_PLAYERS; i++) {
        player.push_back(Player(player_name[i], r1_rank[i], r2_rank[i]));
    }
    sort(player.begin(), player.end());
    for (int i = 0; i < (int)player.size(); i++) {
        if (player[i].name == "j") {
            return i + 1;
        }
    }

    // 实际上不会走到这
    return -1;
}

void solve() {
    // best_rank[x][y]代表JHSeng第一轮排名为x，第二轮排名为y时，对应的最好排名
    // worst_rank同理，代表最坏排名
    int best_rank[TOTAL_PLAYERS + 1][TOTAL_PLAYERS + 1];
    int worst_rank[TOTAL_PLAYERS + 1][TOTAL_PLAYERS + 1];
    // 排名矩阵初始化
    for (int i = 1; i <= TOTAL_PLAYERS; i++) {
        for (int j = 1; j <= TOTAL_PLAYERS; j++) {
            best_rank[i][j] = TOTAL_PLAYERS + 1, worst_rank[i][j] = -1;
        }
    }

    // 枚举第一、二轮排名情况
    // 这里展示如何优雅地生成vector<int>{1, 2, ..., TOTAL_PLAYERS}
    // 注意: ranges库要求使用c++20
    auto per = ranges::iota_view(1, TOTAL_PLAYERS + 1);
    // 定义第一轮排名
    vector<int> r1_rank(per.begin(), per.end());

    // 注意到每一轮比赛不会有排名并列的情况
    // 所以，每一轮比赛的名次，可以用N的全排列进行表示
    // 利用STL全排列(next_permutation)算法，枚举每一轮比赛所有的排名情况
    // 约定排名数组第一项为jhseng排名
    do {
        // 定义第二轮排名
        vector<int> r2_rank(per.begin(), per.end());
        do {
            int simulate_result = simulate(r1_rank, r2_rank);
            // 更新排名矩阵
            best_rank[r1_rank[0]][r2_rank[0]] = min(best_rank[r1_rank[0]][r2_rank[0]], simulate_result);
            worst_rank[r1_rank[0]][r2_rank[0]] = max(worst_rank[r1_rank[0]][r2_rank[0]], simulate_result);
        } while (next_permutation(r2_rank.begin(), r2_rank.end()));
    } while (next_permutation(r1_rank.begin(), r1_rank.end()));

    // 输出最好排名矩阵
    cout << "best rank result\n";
    for (int i = 1; i <= TOTAL_PLAYERS; i++) {
        for (int j = 1; j <= TOTAL_PLAYERS; j++) {
            cout << best_rank[i][j] << ' ';
        }
        cout << '\n';
    }
    // 输出最坏排名矩阵
    cout << "worst rank result\n";
    for (int i = 1; i <= TOTAL_PLAYERS; i++) {
        for (int j = 1; j <= TOTAL_PLAYERS; j++) {
            cout << worst_rank[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
