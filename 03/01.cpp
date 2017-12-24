#include <iostream>

using namespace std;

int main() {
    int input = 277678;
    int i = 1;
    int grid = 0;
    bool l = true;
    while(grid < input) {
        grid = i * i;
        if(grid > input) {
            l = false;
        }
        else{
            i += 2;
        }
    }
    cout << i << " " << grid << endl;
    int distance = 263 + 263 - 51;
    cout << distance << endl;
    return 0;
}