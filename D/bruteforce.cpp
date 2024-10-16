#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int TOTAL_PLAYERS = 5;

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

set<int> simulate(int j_r1_rank, int j_r2_rank) {
    // 构造set<int>，记录jhseng可能出现的总排名
    set<int>result;
    // j_r1_rank, j_r2_rank分别代表jhseng第1/2轮排名
    // x_r1_rank, x_r2_rank分别代表玩家x第1/2轮排名
    // 枚举A排名
    for (int a_r1_rank = 1; a_r1_rank <= TOTAL_PLAYERS; a_r1_rank++) {
        for (int a_r2_rank = 1; a_r2_rank <= TOTAL_PLAYERS; a_r2_rank++) {
            // 枚举B排名
            for (int b_r1_rank = 1; b_r1_rank <= TOTAL_PLAYERS; b_r1_rank++) {
                for (int b_r2_rank = 1; b_r2_rank <= TOTAL_PLAYERS; b_r2_rank++) {
                    // 枚举C排名
                    for (int c_r1_rank = 1; c_r1_rank <= TOTAL_PLAYERS; c_r1_rank++) {
                        for (int c_r2_rank = 1; c_r2_rank <= TOTAL_PLAYERS; c_r2_rank++) {
                            // 枚举D排名
                            for (int d_r1_rank = 1; d_r1_rank <= TOTAL_PLAYERS; d_r1_rank++) {
                                for (int d_r2_rank = 1; d_r2_rank <= TOTAL_PLAYERS; d_r2_rank++) {
                                    set<int>r1_rank = { a_r1_rank, b_r1_rank, c_r1_rank, d_r1_rank, j_r1_rank };
                                    set<int>r2_rank = { a_r2_rank, b_r2_rank, c_r2_rank, d_r2_rank, j_r2_rank };
                                    // 由于每一轮内不存在排名并列的情况，需要剔除不合法的排名结果
                                    if ((int)r1_rank.size() != TOTAL_PLAYERS || (int)r2_rank.size() != TOTAL_PLAYERS) {
                                        continue;
                                    }
                                    // 计算jhseng排名
                                    vector<Player>player = {
                                        Player("a", a_r1_rank, a_r2_rank),
                                        Player("b", b_r1_rank, b_r2_rank),
                                        Player("c", c_r1_rank, c_r2_rank),
                                        Player("d", d_r1_rank, d_r2_rank),
                                        Player("j", j_r1_rank, j_r2_rank),
                                    };
                                    sort(player.begin(), player.end());
                                    for (int i = 0; i < (int)player.size(); i++) {
                                        if (player[i].name == "j") {
                                            result.insert(i + 1);
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return result;
}

void solve() {
    // best_rank[x][y]代表JHSeng第一轮排名为x，第二轮排名为y时，对应的最好排名
    // worst_rank同理，代表最坏排名
    int best_rank[TOTAL_PLAYERS + 1][TOTAL_PLAYERS + 1];
    int worst_rank[TOTAL_PLAYERS + 1][TOTAL_PLAYERS + 1];

    // 枚举JHSeng第1、2轮排名
    for (int j_r1_rank = 1; j_r1_rank <= TOTAL_PLAYERS; j_r1_rank++) {
        for (int j_r2_rank = 1; j_r2_rank <= TOTAL_PLAYERS; j_r2_rank++) {
            auto simulate_result = simulate(j_r1_rank, j_r2_rank);
            // 获取JHSeng最好最坏排名
            // set<int>是有序容器，begin()方法返回指向最小元素的迭代器
            // rbegin()方法返回指向最大元素的迭代器
            // 因为返回的是迭代器，所以要用*解引用
            best_rank[j_r1_rank][j_r2_rank] = *simulate_result.begin();
            worst_rank[j_r1_rank][j_r2_rank] = *simulate_result.rbegin();
        }
    }
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
