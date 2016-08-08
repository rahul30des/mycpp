#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

// Program to print a matrix in spiral fashion
void spiralPrint(vector <vector<int>>& matrix, int r, int c) {
    int i = 0, k = 0, l = 0;
 
    /*  k - starting row index
        r - ending row index
        l - starting column index
        c - ending column index
        i - iterator
    */
    while (k < r && l < c) {
        // Right Row Sweep (col-by-col)
        for(i = l; i < c; i++) {
                cout<<"\t"<<matrix[k][i];
        }
        k++;

        // Down Col Sweep (row-by-row)
        for(i = k; i < r; i++) {
                cout<<"\t"<<matrix[i][c-1];
        }
        c--;

        if (k < r) {
            // Left Row Sweep (col-by-col)
            for(i = c-1; i >= l; i--) {
                    cout<<"\t"<<matrix[r-1][i];
            }
            r--;
        }
       
        if (l < c) {
            // Up Sweep Col (Row-by-row)
            for(i = r-1; i >= k; i--) {
                    cout<<"\t"<<matrix[i][l];
            }
            l++;
        }
    }
}

// Main Function
int main() {
    //vector <vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector <vector<int>> matrix = {{1, 2, 7, 8}, {9, 3, 5, 6}, {17, 18, 19,20}};
    spiralPrint(matrix, matrix.size(), matrix[0].size());
    return 0;
}
