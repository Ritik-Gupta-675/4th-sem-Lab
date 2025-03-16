#include <iostream>
using namespace std;
int main() {
    int rows = 4, cols = 4; 
    int data[4][4] = { 
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 0},
        {0, 0, 1, 1} 
    };
    int lrc[4] = {0, 0, 0, 0}; 
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            lrc[j] = lrc[j]^data[i][j];
        }
    }
    cout << "Data Block:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << "LRC Row: ";
    for (int j = 0; j < cols; j++) {
        cout << lrc[j] << " ";
    }
    cout << endl;

    return 0;
}
