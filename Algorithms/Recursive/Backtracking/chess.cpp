#include <iostream>
using namespace std;


bool isSafe (int board[][1001], int row, int col, int N)
{
    for (int i=1; i<=N; i++)
    {
        if (board[row][i]==1 && i!=col) return false;
    }
    for (int i=1; i<=N; i++)
    {
        if (board[i][col]==1  && i!=row) return false;
    }
    int i, j;
    //cheo len tren
    for (i=row-1, j=col+1; i>=1 && j<=N; i--, j++)
    {
        if (board[i][j]==1) return false;
    }
    //cheo len duoi
    for (i=row+1, j=col-1; i<=N && j>=1; i++, j--)
    {
        if (board[i][j]==1) return false;
    }
    //cheo xuong tren
    for (i=row-1, j=col-1; i>=1 && j>=1; i--, j--)
    {
        if (board[i][j]==1) return false;
    }
    for (i=row+1, j=col+1; i<=N && j<=N; i++, j++)
    {
        if (board[i][j]==1) return false;
    }
    return true;
}

int main ()
{
    int N; cin >> N;
    int board [1001][1001] = {0};
    int x[N]; int y[N];
    bool isThreatened=false;
    for (int i=1; i<= N; i++)
    {
        cin >> x[i] >> y[i];
        board[x[i]][y[i]] =1;

    }
    for (int i=1; i<=N;  i++)
    {
        if (!isSafe(board, x[i], y[i], N))
        {
            isThreatened=true;
            break
    ;
        }

    }
    if (isThreatened) cout << "YES"<<endl;
    else cout <<"NO"<<endl;
}