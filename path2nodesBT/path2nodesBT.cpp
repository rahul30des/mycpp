#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


typedef struct node
{
    struct node *left, *right;
    int val;
}NODE;

NODE* newNode(int val)
{
    NODE*temp = new NODE;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}


/* 
 * Driver func returns LCA of two values n1 and n2
 * v1 is set as true by this function if n1 is found
 * v2 is set as true by this function if n2 is found 
 */
NODE* findLCAUtil(NODE* root, int n1, int n2, bool &v1, bool &v2)
{
    if (root == NULL) {
        return NULL;
    }

    // If either n1 or n2 matches with root's val, mark the presence
    if (root->val == n1)
    {
        v1 = true;
        return root;
    }

    if (root->val == n2)
    {
        v2 = true;
        return root;
    }

    // Look for vals in left and right subtrees
    NODE* left_lca = findLCAUtil(root->left, n1, n2, v1, v2);
    NODE* right_lca = findLCAUtil(root->right, n1, n2, v1, v2);

    // Both values are present in different subtrees
    if (left_lca && right_lca) { 
        return root;
    }

    return (left_lca != NULL) ? left_lca: right_lca;
}

bool findNODE(NODE* root, int val)
{
    if (root == NULL) {
        return false;
    }

    if (root->val == val || findNODE(root->left, val) || findNODE(root->right, val)) {
        return true;
    }

    return false;
}

// Unoptimized Code for now
void createPath(NODE* root, int val, vector <int> &stk)
{
    if (root == NULL) {
        return;
    }

    stk.push_back(root->val);
    if (root->val == val) {
        return;
    } else if (findNODE(root->left, val)) {
        createPath(root->left, val, stk);
    } else if (findNODE(root->right, val)) {
        createPath(root->right, val, stk);
    }
}

// Uses Driver func and checks (for both nodes in same subtree)
NODE* findLCA(NODE* root, int n1, int n2)
{
    bool v1 = false, v2 = false;

    NODE* lca = findLCAUtil(root, n1, n2, v1, v2);

    // Return LCA only if both n1 and n2 are present in tree
    if ((v1 && v2) || (v1 && findNODE(lca, n2)) || (v2 && findNODE(lca, n1))) {
        return lca;
    }

    return NULL;
}

// Main
int main() {
    int v1 = 0;
    int v2 = 0;

    // Binary Tree creation
    NODE* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);
    root->left->right->left = newNode(8);
    root->right->left->left = newNode(9);
    root->right->left->right = newNode(10);
    root->right->right->right = newNode(11);

    cin>>v1>>v2;

    NODE* lca = findLCA(root, v1, v2);
    if (lca != NULL) {
        cout << "LCA("<<v1<<","<<v2<<") = " << lca->val;
    }
    else {
        cout << "vals are not present ";
        return 1;
    }

    vector <int> stk;
    createPath(lca, v1, stk);
    cout<<endl;
    while (!stk.empty()) {
        cout<<stk.back()<<"\t";
        stk.pop_back();
    }
    stk.clear();
    createPath(lca, v2, stk);
    stk.erase(stk.begin());
    for(auto it=stk.begin(); it != stk.end(); it++) {
        cout<<*it<<"\t";
    }

    return 0;
}
