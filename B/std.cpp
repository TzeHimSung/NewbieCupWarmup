#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 定义Player结构体，存储玩家对局状态
struct Player {
    string name, stack;  // 姓名与卡组
    int idx;  // 玩家当前卡组顶是第几张牌

    Player() {}
    Player(string _name, string _stack) {
        name = _name, stack = _stack, idx = 0;
    }

    char getNextPlayer() {
        return stack[idx];
    }
};

void solve() {
    string sa, sb, sc, sd;
    cin >> sa >> sb >> sc >> sd;
    Player alice = Player("Alice", sa);
    Player bob = Player("Bob", sb);
    Player charlie = Player("Charlie", sc);
    Player david = Player("David", sd);
    // 定义姓名首字母 -> Player*映射，方便修改对应玩家的状态
    map<char, Player*>playerMapping = {
        {'a', &alice},
        {'b', &bob},
        {'c', &charlie},
        {'d', &david},
    };
    Player* currPlayer = &alice;  // 当前玩家
    Player* lastPlayer = nullptr;  // 上一个玩家
    // 退出条件: 当前玩家卡组为空
    while (currPlayer->idx < (int)currPlayer->stack.size()) {
        lastPlayer = currPlayer;
        // 把当前玩家更新为弃牌上的字母开头的玩家
        currPlayer = playerMapping[currPlayer->getNextPlayer()];
        // 弃牌
        lastPlayer->idx++;
    }
    cout << currPlayer->name << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}