#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    // 幺九牌类型
    set<string> cardsNeeded = {
        "1m", "9m", "1p", "9p", "1s", "9s",
        "1z", "2z", "3z", "4z", "5z", "6z", "7z"
    };
    // 手牌
    string cards;
    // 手牌中幺九牌种类统计
    set<string> cardCount;
    cin >> cards;
    for (int i = 0; i < (int)cards.size(); i += 2) {
        string currentCard = cards.substr(i, 2);
        // 若当前牌不属于幺九牌，必不合法
        if (cardsNeeded.find(currentCard) == cardsNeeded.end()) {
            cout << "NO\n";
            return;
        }
        cardCount.insert(currentCard);
    }
    // 手牌均为幺九牌，且统计map包含十三张牌，必为十三面听牌
    if (cardCount.size() == cardsNeeded.size()) {
        cout << "YES\n";
        cout << "1m 1p 1s 1z 2z 3z 4z 5z 6z 7z 9m 9p 9s\n";
        return;
    }
    // 单吊时(只听一张牌)，cardCount必然只有十二类幺九牌
    if ((int)cardCount.size() < 12) {
        cout << "NO\n";
        return;
    }
    // cardsNeeded集合与cardCount集合作差，剩下的唯一元素即为所听牌
    cout << "YES\n";
    for (auto card : cardsNeeded) {
        if (cardCount.find(card) == cardCount.end()) {
            cout << card << endl;
            break;
        }
    }
    // 如果你会set_difference这个比较偏门的STL函数就更好了(它在algorithm库)
    // set_difference(
    //     cardsNeeded.begin(), cardsNeeded.end(),
    //     cardCount.begin(), cardCount.end(),
    //     ostream_iterator<string>(cout, "\n")
    // );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}