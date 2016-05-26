#include<iostream>

using namespace std;

int countTriangles(int **gr1, int n);

void display(int **mat, int N) {
    for (int i = 0; i < N; i++) {
        for(int j =0; j < N; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

//Main Function
int main() {
    int m  = 0, n = 0;
    cin>>m;
    cin>>n;
    int k = 0, l = 0;

    int list[m][2];
    // Get input edges
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < 2; j++) {
            cin>>list[i][j];
        }
    }
    
    // Initialize adj matrix
    int **adj_mat = new int*[n];
    for(int i = 0; i < n; i++) {
       adj_mat[i] = new int[n];
    }
    memset(&adj_mat[0][0], 0, n * n * sizeof(int));

    // Create adjacency matrix from the list of input edges
    for (int i = 0; i < m; i++) {
            k  = list[i][0];
            l  = list[i][1];
            adj_mat[k][l] = 1;
            adj_mat[l][k] = 1;
    }   
    cout<<endl<<"adj_mat :"<<endl;
    display(adj_mat ,n);
    
    // Driver Function will pass adj matrix representing graph to the countTriangles()
    cout<<countTriangles(adj_mat, n);
}

int  countTriangles(int **gr1, int n) {
    int **gr2= new int*[n];
    for(int i = 0; i < n; i++) {
        gr2[i] = new int[n];
    }
    memset(&gr2[0][0], 0, n * n * sizeof(int));
    
    int **out= new int*[n];
    for(int i = 0; i < n; i++) {
        out[i] = new int[n];
    }
    memset(&out[0][0], 0, n * n * sizeof(int));

    int result = 0;
    
    cout<<endl<<"1";

    //   graph * graph
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            out[i][k] = 0;
            for (int j = 0; j < n; j++) {
                out[i][k] += (gr1[i][j] * gr1[j][k]);
            }
        }
    }
    cout<<"out:"<<endl;
    display(out, n);
    
    cout<<endl<<"2";

    // graph * graph * graph
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            gr2[i][k] = 0;
            for (int j = 0; j < n; j++) {
                gr2[i][k] += (gr1[i][j] * out[j][k]);
            }
        }
    }
    
    cout<<endl<<"gr2 : "<<endl;
    display(gr2,n);

    for (int i = 0; i < n; i++) {
            result += gr2[i][i];
    }
    
    return result/6;   
}
