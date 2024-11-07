// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool sol = false;
int firstRow, firstCol;

void printboard(const vector<vector<string>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int col, int n, vector<vector<string>> &board, vector<int> &leftRow,
           vector<int> &lowerD, vector<int> &upperD)
{
    if (col == n)
    {
        printboard(board, n);
        sol = true;
        return;
    }
    if (col == firstCol)
    {
        solve(col + 1, n, board, leftRow, lowerD, upperD);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && lowerD[row + col] == 0 && upperD[n - 1 + col - row] == 0)
        {
            board[row][col] = "Q";
            leftRow[row] = 1;
            lowerD[row + col] = 1;
            upperD[n - 1 + col - row] = 1;

            solve(col + 1, n, board, leftRow, lowerD, upperD);

            // backtrack
            board[row][col] = ".";
            leftRow[row] = 0;
            lowerD[row + col] = 0;
            upperD[n - 1 + col - row] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "Enter n as size of board: ";
    cin >> n;
    vector<vector<string>> board(n, vector<string>(n, "."));
    cout << "Enter coordinates for the first queen (row and column): ";
    cin >> firstRow >> firstCol;

    // validate ip for 1st queen
    if (firstRow >= n || firstCol >= n || firstRow < 0 || firstCol < 0)
    {
        cout << "Invalid pos for first queen" << endl;
        return 1;
    }
    board[firstRow][firstCol] = "Q";
    vector<int> leftRow(n, 0), lowerD(2 * n - 1, 0), upperD(2 * n - 1, 0);
    leftRow[firstRow] = 1;
    lowerD[firstRow + firstCol] = 1;
    upperD[n - 1 + firstCol - firstRow] = 1;
    cout << "Printing solutions for first queen placed: " << endl;
    solve(0, n, board, leftRow, lowerD, upperD);
    if (!sol)
        cout << "No solution exists" << endl;

    return 0;
}