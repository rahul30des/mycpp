#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DP solution Time Complexity O(n) Space Complexity O(n)
int getPathCountDp(vector <vector<int>> &matrix, vector <vector<int>> &soln, int  row, int col) {
  
    /* Mark first row and column since first row and down col are directly accessible      
     * elements if not walled 
    */
    for(int i = 0; i <= row; i++) {
      if(matrix[i][0] == 0) {
          soln[i][0] = 1;
      } else {
          break;
      }
    }
    for(int j = 0; j <= col; j++) {
      if(matrix[0][j] == 0) {
          soln[0][j] = 1;
      } else {
          break;
      }
    }
    int i = 1, j =1; 
    int k = row + 1 + col + 1;
    for(; k <= ((row+1) * (col+1)); j++, k++) {
        if(j%(col+1) == 0) {
            j = 1;
            ++i;
        }
        if (matrix[i][j] == 0) {
            if((soln[i-1][j] > 0) && (soln[i][j-1] > 0)) {
                soln[i][j] = soln[i-1][j]+soln[i][j-1];
            } else if (soln[i-1][j] > 0) {
                soln[i][j] = soln[i-1][j];
            } else if(soln[i][j-1] > 0) {
                soln[i][j] = soln[i][j-1];
            }
        }
    }
    return soln[row][col];
}

// Time Complexity O(2^n) 
// Backtracking 
void getPathCountUtil(vector <vector<int>> &matrix, vector <vector<int>> &soln, int  row, int col, int i, int j, int &pathcount) {
  
  if((i == row) && (j == col)) {
      ++pathcount;
  }
  
    // Move Right
    if (j < col && (matrix[i][j+1] == 0)) {
          getPathCountUtil(matrix, soln, row, col, i, j+1, pathcount);
    }

    // Move Down
    if (i < row && (matrix[i+1][j] == 0)) {
          getPathCountUtil(matrix, soln, row, col, i+1, j, pathcount);
    }
}


// Returns the path from (0,0) to (n-1, n-1)
int getPathCount(vector <vector<int>> matrix, vector <vector<int>> soln, int row, int col) {
    // Expo Solution
    int pathcount = 0;
    
    // If source/destination is blocked return 0
    if((matrix[0][0] == 1) || (matrix[row][col] == 1) ) {
      return 0;
    }
  
    // Exponential solution O(2^n)
    //getPathCountUtil(matrix, soln, row, col, 0, 0, pathcount);
    
    // DP Solution O(n^2)
    pathcount = getPathCountDp(matrix, soln, row, col);
    
    return pathcount;
}

// To execute C++, please define "int main()"
int main() {
  
  vector <vector<int>> matrix = {{0, 0, 1, 0},
                                 {0 ,0, 0 ,0},
                                 {1, 0, 1, 0},
                                 {0, 0 ,0 ,0}}; // Answer = 4
  int row = matrix.size();
  int col = matrix[0].size();
  // Allocate solution matrix to keep track and init to 0
  vector <vector<int>> soln (row, vector<int> (col, 0));
  
  cout<<getPathCount(matrix, soln, row - 1, col - 1);
  
  return 0;
}
