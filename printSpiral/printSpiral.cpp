#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

// Program to print a matrix in spiral fashion
void spiralPrint(vector <vector<int>>& matrix, int r, int c) {
    int start_row = 0, end_row = r - 1;
    int start_col = 0, end_col = c - 1;

    int i = 0, j = 0;
 
    while (start_row <= end_row && start_col <= end_col) {
        // Right Row Sweep (col-by-col)
        for(j = start_col; j <= end_col; j++) {
                cout<<"\t"<<matrix[start_row][j];
        }
        start_row++;

        // Down Col Sweep (row-by-row)
        for(i = start_row; i <= end_row; i++) {
                cout<<"\t"<<matrix[i][end_col];
        }
        end_col--;

        if (start_row <= end_row) {
            // Left Row Sweep (col-by-col)
            for(j = end_col; j >= start_col; j--) {
                    cout<<"\t"<<matrix[end_row][j];
            }
            end_row--;
        }
       
        if (start_col <= end_col) {
            // Up Sweep Col (Row-by-row)
            for(i = end_row; i >= start_row; i--) {
                    cout<<"\t"<<matrix[i][start_col];
            }
            start_col++;
        }
    }
}

// Main Function
int main() {
    //vector <vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector <vector<int>> matrix = {{1, 2, 7, 8}, 
                                   {9, 3, 5, 6}, 
                                   {17, 18, 19,20}};
    spiralPrint(matrix, matrix.size(), matrix[0].size());
    cout<<endl;
    return 0;
}
