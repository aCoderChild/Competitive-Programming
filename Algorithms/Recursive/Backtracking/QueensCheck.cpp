#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<bool> >& board, int row, int col, int rowIndex, int colIndex) {
    //same column
    for (int i = 0 ; i < row; i++) {
        if (board[i][colIndex] == board[rowIndex][colIndex] && i != rowIndex) return false;
    }

    //same row
    for (int i = 0; i < col; i++) {
        if (board[rowIndex][i] == board[rowIndex][colIndex] && i != colIndex) return false;
    }

    //down main diagonal
    for (int i = 1; i < min(row - rowIndex, col - colIndex); i++) {
        if (board[rowIndex+i][colIndex+i] == board[rowIndex][colIndex]) return false;
    }

    //up main diagonal
    for (int i = 1; i <= min(rowIndex, colIndex); i++) {
        if (board[rowIndex-i][colIndex-i] == board[rowIndex][colIndex]) return false;
    }

    //down other diagonal
    for (int i = 1; i <= min((row-1-rowIndex), colIndex); i++) {
        if (board[rowIndex+i][colIndex-i] == board[rowIndex][colIndex]) return false;
    }

    //up other diagonal
    for (int i = 1; i <= min((col-1-colIndex), rowIndex); i++) {
        if (board[rowIndex-i][colIndex+i] == board[rowIndex][colIndex]) return false;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;

    vector<bool> col (n, false); 
    vector<vector<bool> > board(n, col);

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        board[x-1][y-1] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                if (!isSafe(board, n, n, i, j)) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}