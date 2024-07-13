#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_M = 100;
const int MAX_N = 100;

vector<vector<char> > board(MAX_M, vector<char>(MAX_N));
vector<vector<int> > countMines(MAX_M, vector<int>(MAX_N, -1));
vector<vector<bool> > visited(MAX_M, vector<bool>(MAX_N, false));

int m,n,k;

void initBoard() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
}

void countMinesAround (int x, int y) {
    int count = 0;
    for (int i = - 1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'M') {
                count++;
            }
        }
    }
    countMines[x][y] = count;
}

void floodFill(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = cx +i;
                int ny = cy + j;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && board[nx][ny] == 'E') {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                    countMinesAround(nx, ny);
                }
            }
        }
    }
}

void printBoard() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << countMines[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> m >> n >> k;
    initBoard();

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        if (board[x][y] == 'M') {
            cout << "YOU'RE DEAD!" << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << board[i][j];
                }
                cout << endl;
            }
            return 0;
        }

        floodFill(x, y);
        printBoard();
    }

    return 0;
}