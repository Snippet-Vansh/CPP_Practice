#include <iostream>
using namespace std;

int board[10], n;

bool isSafe(int row, int col)
{
    for (int i = 1; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void nQueen(int row)
{
    if (row > n)
    {
        for (int i = 1; i <= n; i++)
            cout << board[i] << " ";
        cout << endl;
        return;
    }

    for (int col = 1; col <= n; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;
            nQueen(row + 1);
        }
    }
}

int main()
{
    cout << "Enter number of queens: ";
    cin >> n;

    nQueen(1);

    return 0;
}