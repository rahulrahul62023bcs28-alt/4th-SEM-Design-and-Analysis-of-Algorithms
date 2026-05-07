#include <iostream>
#include <cmath>
using namespace std;

int x[10];
int n;

// Function to print board
void printBoard()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Check safe position
bool Place(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}

// Backtracking function
void NQueens(int k)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Trying Row " << k << " Col " << i << endl;

        if (Place(k, i))
        {
            x[k] = i;

            cout << "Placed at (" << k << "," << i << ")" << endl;
            printBoard();

            if (k == n)
            {
                cout << "Solution Found:\n";
                printBoard();
            }
            else
            {
                NQueens(k + 1);
            }

            // Backtracking
            cout << "Backtracking from (" << k << "," << i << ")\n";
        }
        else
        {
            cout << "Conflict at (" << k << "," << i << ")\n";
        }
    }
}

int main()
{
    cout << "Enter number of queens: ";
    cin >> n;

    NQueens(1);

    return 0;
}
