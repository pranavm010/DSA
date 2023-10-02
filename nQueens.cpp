#include <iostream>
using namespace std;

bool safe(int queens[][3], int row, int col, int n) {
    
    for (int i = 0; i < col; i++) {
        if (queens[row][i] == 1) {
            return false;
        }
    }

    //diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (queens[i][j] == 1) {
            return false;
        }
    }

    //diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (queens[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solve(int queens[][3], int col, int n) {
    if (col >= n) {
        return true; 
    }

    for (int i = 0; i < n; i++) {
        if (safe(queens, i, col, n)) {
            queens[i][col] = 1;

            if (solve(queens, col + 1, n)) {
                return true;
            }

            queens[i][col] = 0; 
        }
    }

    return false; 
}

int main() {
    int queens[3][3] = {0}; 
    if (solve(queens, 0, 3)) {
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << queens[i][j] << " ";
            }
            cout << endl;
        }
    }

    else{
        cout<<"No solution exits.";
    }

    return 0;
}
