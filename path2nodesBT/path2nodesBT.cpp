#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct node{
    int val;
    struct node *left, *right;
}NODE;

NODE* NewNode(int value) {
    NODE *root = new NODE;
    root->val = value;
    root->left = root->right = NULL;
    return root;
}    

NODE* FindLCAUtil(NODE* root, int v1, int v2, bool& n1, bool& n2) {
    if(root == NULL) {
        return NULL;
    }

    if(root->val == v1) {
        n1 = true;
        return root;
    }

    if(root->val == v2) {
        n2 = true;
        return root;
    }

    NODE* left_lca = FindLCAUtil(root->left, v1, v2, n1, n2); 
    NODE* right_lca = FindLCAUtil(root->right, v1, v2, n1, n2); 

    if(left_lca && right_lca) {
        return root;
    } 
    return (left_lca?left_lca:right_lca);    
}

bool FindNode(NODE* root, int value) {
    if(root == NULL) {
        return false;
    }
    return ((root->val == value) || FindNode(root->left, value) || FindNode(root->right, value));
}

NODE* FindLCA(NODE* root, int v1, int v2) {
    bool n1 = false, n2 = false;
    NODE* lca = FindLCAUtil(root, v1, v2, n1, n2);
    if((n1 && n2) || (n1 && FindNode(lca, v2)) || (n2 && FindNode(lca, v1))) {
        return lca;
    } else {
        return NULL;
    }
}


void CreatePath(NODE* root, int value, vector <int>& stk) {
    if (root == NULL) {
        return;
    }

    stk.push_back(root->val);
    if (root->val == value) {
        return;
    } else if (FindNode(root->left, value)) {
        CreatePath(root->left, value, stk);
    } else if (FindNode(root->right, value)) {
        CreatePath(root->right, value, stk);
    }
}

// Main
int main() {
    int v1 = 0;
    int v2 = 0;

    // Binary Tree creation
    NODE* root = NewNode(0);
    root->left = NewNode(1);
    root->right = NewNode(2);
    root->left->left = NewNode(3);
    root->left->right = NewNode(4);
    root->right->left = NewNode(5);
    root->right->right = NewNode(6);
    root->left->left->left = NewNode(7);
    root->left->right->left = NewNode(8);
    root->right->left->left = NewNode(9);
    root->right->left->right = NewNode(10);
    root->right->right->right = NewNode(11);

    cin>>v1>>v2;

    NODE* lca = FindLCA(root, v1, v2);
    if (lca != NULL) {
        cout << "LCA("<<v1<<","<<v2<<") = " << lca->val;
    }
    else {
        cout << "vals are not present ";
        return 1;
    }

    vector <int> stk;
    CreatePath(lca, v1, stk);
    cout<<endl;
    while (!stk.empty()) {
        cout<<stk.back()<<"\t";
        stk.pop_back();
    }
    stk.clear();
    CreatePath(lca, v2, stk);
    stk.erase(stk.begin());
    for(auto it=stk.begin(); it != stk.end(); it++) {
        cout<<*it<<"\t";
    }
    cout<<endl;

    return 0;
}
