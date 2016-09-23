#include <iostream>
#include <vector>

using namespace std;

// Process each cell and use estd logic to update cells
void processLife(vector <vector<int> > mat, vector < vector<int> >& out) {
  int row = mat.size();
  int col = mat[0].size();
  for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
          unsigned int count = 0;
          
          // Right Sweep same row
          if((j + 1 < col) && (mat[i][j+1] == 1)) {
                ++count;   
          }
          // Left Sweep same row
          if((j - 1 >= 0) && (mat[i][j-1])) {
                ++count;   
          }
          // Top same row
          if((i - 1 >= 0) && (mat[i-1][j])) {
                ++count;   
          }
          // Bottom same row
          if((i + 1 < row) && (mat[i+1][j])) {
                ++count;   
          }
          // Top Right Sweep same row
          if((j + 1 < col) && (i - 1 >= 0) && (mat[i-1][j+1]) ) {
                ++count;   
          }
          // Top Left Sweep same row
          if((j - 1 >= 0) && (i - 1 >= 0) && (mat[i-1][j-1])) {
                ++count;   
          }
          // Bottom Left Sweep same row
          if((j - 1 < col) && (i + 1 < row) && (mat[i+1][j-1])) {
                ++count;   
          }
           
          // Bottom Right Sweep same row
          if((j + 1 < col) && (i + 1 < row) && (mat[i+1][j+1])) {
                ++count;   
          }
        
          if(mat[i][j]) {    
            if((count == 2) || (count == 3)) {
                out[i][j] = 1;
                
            }               
          } else if(count == 3)   {
                out[i][j] = 1; 
          }
      }
  }
}

// Display matrices
void display(vector< vector<int> > out) {
  for(unsigned int i = 0; i < out.size(); i++) {
      for(unsigned int j = 0; j < out[0].size(); j++) {
          cout<<out[i][j]<<"\t";
      }
    cout<<endl;
  }
}

// To execute C++, please define "int main()"
int main() {
  vector < vector<int> > mat(2, vector<int>(5, 0));
  mat = {{1, 0, 1, 1, 1} , {0, 1, 0, 1, 1}};
  vector < vector<int> > out (mat.size(), vector<int> (mat[0].size(), 0));
  processLife(mat, out);
  display(out);
  return 0;
}
