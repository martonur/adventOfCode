#include <iostream>
#include <math.h>

using namespace std;

void calcNxNmatrix(int n);

int main() {
    calcNxNmatrix(9);
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
    int tmp = 1;

    for(int i = 1; i <= m; i++) {
        // RIGHT SIDE               / WHILE 2ND COORDINATE > 0
        // 1st: under the number    / 1st coordinate + 1
        // 2nd: lower-left          / 1st coordinate + 1, 2nd coordinate - 1
        // 3rd: left                / 2nd coordinate - 1
        // 4th: upper-left          / 1st coordinate - 1, 2nd coordinate - 1
        for(int j = m + i - 1; j > m - i; j--) {
            T[j][m + i] = T[j + 1][m + i] + T[j + 1][m + i - 1] + T[j][m + i - 1] + T[j - 1][m + i - 1];
            cout << "RIGHT SIDE" << endl;
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < n; l++) {
                    cout << T[k][l] << "\t";
                }
                cout << endl;
            }
            cout << endl;

            
        }

        // TOP RIGHT / 2ND COORDINATE = 0
        // 1st: under the number    / 1st coordinate + 1
        // 2nd: lower-left          / 1st coordinate + 1, 2nd coordinate - 1
        T[m - i][m + i] = T[m - i + 1][m + i] + T[m - i + 1][m + i - 1];
        cout << "TOP RIGHT" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << T[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;

        // TOP MIDDLE / WHILE 1ST COORDINATE > 0
        // 1st: right side          / 2nd coordinate + 1
        // 2nd: lower-right         / 1st coordinate + 1, 2nd coordinate + 1
        // 3rd: under the number    / 1st coordinate + 1
        // 4th: lower-left          / 1st coordinate + 1, 2nd coordinate - 1
        // T[0][n - tmp]            / tmp: 1..2..3: n - top right - top left = n - 2 is the last one
        // I DON'T KNOW HOW, BUT THIS IS WORKING FOR THE TOP RIGHT, TOO LOL
        // WELL, IT SHOULDN'T BECAUSE ITS RIGHT SIDE IS NOT IN THE MATRIX FOR EXAMPLE..
        
        if(i != 1) {
            tmp = tmp + 2;
        }
        for(int j = 1; j <= tmp; j++) {
            cout << "j: " << j  << tmp << endl;
            T[m - i][m + i - j] = T[m - i][m + i - j + 1] + T[m - i + 1][m + i - j + 1] + T[m - i + 1][m + i - j] + T[m - i + 1][m + i - j - 1];
            cout << "TOP SIDE" << endl;
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < n; l++) {
                    cout << T[k][l] << "\t";
                }
                cout << endl;
            }
            cout << endl;
        }

        // WORKING
        // TOP LEFT / T[0][0]
        // 1st: right side          / 2nd coordinate + 1
        // 2nd: lower-right         / 1st coordinate + 1, 2nd coordinate + 1
        T[m - i][m - i] = T[m - i][m - i + 1] + T[m - i + 1][m - i + 1];
        cout << "TOP LEFT" << endl;
        for(int k = 0; k < n; k++) {
            for(int l = 0; l < n; l++) {
                cout << T[k][l] << "\t";
            }
            cout << endl;
        }
        cout << endl;

        // WORKING
        // LEFT SIDE                / WHILE 1ST COORDINATE < N
        // 1st: over the number     / 1st coordinate - 1  
        // 2nd: upper-right         / 1st coordinate - 1, 2nd coordinate + 1
        // 3rd: right               / 2nd coordinate + 1
        // 4th: lower-right         / 1st coordinate + 1, 2nd coordinate + 1
        // IF I CALCULATE THE BOTTOM LEFT WITH THIS IT RETURNS GOOD VALUE + 1
        for(int j = 1; j <= tmp; j++) {
            T[m - i + j][m - i] = T[m - i + j - 1][m - i] + T[m - i + j - 1][m - i + 1] + T[m - i + j][m - i + 1] + T[m - i + j + 1][m - i +1];
            cout << "LEFT SIDE" << endl;
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < n; l++) {
                    cout << T[k][l] << "\t";
                }
                cout << endl;
            }
            cout << endl;
        }

        // WORKING
        // BOTTOM LEFT              / [N][0]
        // 1st: over the number     / 1st coordinate - 1
        // 2nd: upper-right         / 1st coordinate - 1, 2nd coordinate + 1
        T[m + i][m - i] = T[m + i - 1][m - i] + T[m + i - 1][m - i + 1];
        cout << "BOTTOM LEFT" << endl;
        for(int k = 0; k < n; k++) {
            for(int l = 0; l < n; l++) {
                cout << T[k][l] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        
        // WORKING
        // BOTTOM MIDDLE
        // 1st: left                / 2nd coordinate - 1
        // 2nd: upper left          / 1st coordinate - 1, 2nd coordinate - 1
        // 3rd: over the number     / 1st coordinate - 1  
        // 4th: upper-right         / 1st coordinate - 1, 2nd coordinate + 1
        for(int j = tmp; j > 0; j--) {
            T[m + i][m + i - j] = T[m + i][m + i - j - 1] + T[m + i - 1][m + i - j - 1] + T[m + i - 1][m + i - j] + T[m + i - 1][m + i - j + 1];
            
            // T[4][3]
            // T[5][2-3-4]
            // T[6][1-2-3-4-5]
            

            cout << "BOTTOM SIDE" << endl;
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < n; l++) {
                    cout << T[k][l] << "\t";
                }
                cout << endl;
            }
            cout << endl;
        }

        // WORKING
        // BOTTOM RIGHT
        // 1st: left                / 2nd coordinate - 1
        // 2nd: upper left          / 1st coordinate - 1, 2nd coordinate - 1
        // 3rd: over the number     / 1st coordinate - 1  
        cout << "m: " << m << ", i: " << i << endl;
        T[m + i][m + i] = T[m + i][m + i - 1] + T[m + i - 1][m + i - 1] + T[m + i - 1][m + i];
        cout << "BOTTOM RIGHT" << endl;
        for(int k = 0; k < n; k++) {
            for(int l = 0; l < n; l++) {
                cout << T[k][l] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << T[i][j] << "\t";
        }
        cout << endl;
    }

    

}