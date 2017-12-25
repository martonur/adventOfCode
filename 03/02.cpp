#include <iostream>
#include <math.h>

using namespace std;

void calcNxNmatrix(int n);

int main() {
    calcNxNmatrix(5);
    return 0;
}

void calcNxNmatrix(int n) {
    int T[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            T[i][j] = 0;
        }
    }
    
    int m = int(ceil(n/2));
    T[m][m] = 1;
    T[m][m + 1] = T[m][m];
    T[m - 1][m + 1] = T[m][m] + T[m][m + 1];
    T[m - 1][m] = T[m][m] + T[m][m + 1] + T[m - 1][m + 1];
    T[m - 1][m - 1] = T[m][m] + T[m - 1][m];
    T[m][m - 1] = T[m][m] + T[m - 1][m] + T[m - 1][m - 1];
    T[m + 1][m - 1] = T[m][m - 1] + T[m][m];
    T[m + 1][m] = T[m][m - 1] + T[m][m] + T[m + 1][m - 1] + T[m][m + 1];
    T[m + 1][m + 1] = T[m][m] + T[m + 1][m] + T[m][m + 1];

    for(int i = 2; i <= m; i++) {
        T[m + i - 1][m + i] = T[m + i - 1][m + i - 1] + T[m + i - 2][m + i - 1];
        T[m + i - 2][m + i] = T[m + i - 1][m + i] + T[m + i - 1][m + i - 1] + T[m][m + 1] + T[m - 1][m + 1];
        // RIGHT SIDE               / WHILE 2ND COORDINATE > 0
        // 1st: under the number    / 1st coordinate + 1
        // 2nd: lower-left          / 1st coordinate + 1, 2nd coordinate - 1
        // 3rd: left                / 2nd coordinate - 1
        // 4th: upper-left          / 1st coordinate - 1, 2nd coordinate - 1
        T[m + i - 3][m + i] = T[m + i - 2][m + i] + T[m + i - 3 + 1][m + i - 1] + T[m + i - 3][m + i - 1] + T[m + i - 3 - 1][m + i - 1];
        // TOP RIGHT / 2ND COORDINATE = 0
        // 1st: under the number    / 1st coordinate + 1
        // 2nd: lower-left          / 1st coordinate + 1, 2nd coordinate - 1
        // T[m + i - 4][m + i] = T[m + i - 3][m + i] + T[m + i - 4 + 1][m + i - 1];
        // TOP MIDDLE / WHILE 1ST COORDINATE > 0
        // 1st: right side          / 2nd coordinate + 1
        // 2nd: lower-right         / 1st coordinate + 1, 2nd coordinate + 1
        // 3rd: under the number    / 1st coordinate + 1
        // 4th: lower-left          / 1st coordinate + 1, 2nd coordinate - 1
        // T[0][n - tmp]            / tmp: 1..2..3: n - top right - top left = n - 2 is the last one
        // I DON'T KNOW HOW, BUT THIS IS WORKING FOR THE TOP RIGHT, TOO LOL
        // WELL, IT SHOULDN'T BECAUSE ITS RIGHT SIDE IS NOT IN THE MATRIX FOR EXAMPLE..
        for(int j = 1; j < n; j++) {
            T[0][n - j] = T[0][n - j + 1] + T[1][n - j + 1] + T[1][n - j] + T[1][n - j - 1];
        }
        // TOP LEFT / 
    }
    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << T[i][j] << "\t";
        }
        cout << endl;
    }

    

}