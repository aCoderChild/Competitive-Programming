#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void generate(int n) {
    int pown = pow(2,n);

    //initialising a matrix of order pown
    vector<vector<int> > hadamard(pown, vector<int> (pown));

    //recursive step
    hadamard[0][0] = 1;
    //k doubles because the matrix is in 2D dimension
    for (int k = 1; k < pown; k+= k) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                hadamard[i+k][j] = hadamard[i][j];
                hadamard[i][j+k] = hadamard[i][j];
                hadamard[i+k][j+k] = -hadamard[i][j];
            }
        }
    }

    //print the matrix
    for (int i = 0; i < pown; i++) {
        for (int j = 0; j < pown; j++) {
            if (hadamard[i][j] == 1) cout << ". ";
            else cout << "o ";
        }
        cout << endl;
    }

    return;
}

int main()
{
    int n;
    cin >> n;
 
    // Function call
    generate(n);
    return 0;
}