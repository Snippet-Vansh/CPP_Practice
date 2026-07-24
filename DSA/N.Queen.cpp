#include <iostream>
#include <cmath>
using namespace std;

int board[10];

bool isSafe(int row, int col)
{
    for (int i = 1; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void queen(int row)
{
    if (row == 9)
    {
        for (int i = 1; i <= 8; i++)
            cout << board[i] << " ";
        cout << endl;
        return;
    }

    for (int col = 1; col <= 8; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;
            queen(row + 1);
        }
    }
}

int main()
{
    queen(1);
    return 0;
}