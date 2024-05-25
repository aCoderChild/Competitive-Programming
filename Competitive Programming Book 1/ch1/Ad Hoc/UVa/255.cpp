#include <bits/stdc++.h>
using namespace std;

string solve(int state[]) {
    if (state[0] == state[1]) return "Illegal state";

    int queenMove = state[2];
    int queenState = state[1];

    int r2 = queenMove % 8;
    int r1 = queenState % 8;
    int q2 = queenMove / 8;
    int q1 = queenState / 8;

    if (r1 - r2 != 0 && q1 - q2 != 0) return "Illegal move";

    int kingState = state[0];
    int r0 = kingState % 8;
    int q0 = kingState / 8;

    if (r1 - r0 == 0  && ((q1 - q0) * (q2 - q0) < 0)) return "Illegal move";

    if (q1 - q0 == 0  && ((r1 - r0) * (r2 - r0) < 0)) return "Illegal move";

    if (kingState == queenMove || queenState == queenMove) return "Illegal move";

    if ((abs(r0 - r2) == 1 && abs(q0 - q2) == 0) || (abs(r0 - r2) == 0 && abs(q0 - q2) == 1)) return "Move not allowed";

    if ((kingState == 0 && queenMove == 9) || (kingState == 7 && queenMove == 14) || (kingState == 56 && queenMove == 49) || ((kingState == 63 && queenMove == 54))) return "Stop";

    return "Continue";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int state[3];
        if (!(cin >> state[0] >> state[1] >> state[2])) break;
        string result = solve(state);
        cout << result << endl;
    }

    return 0;
}

/*
Some Reviews:
    - It's the if-else problem, do as the instruction
    - use return, so that you would not need to do the else thing, but do 
    consider the order seriously
*/