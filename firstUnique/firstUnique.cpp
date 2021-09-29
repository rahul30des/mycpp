#include<unordered_map>
#include<deque>
#include<iostream>

using namespace std;

class Node {
   public:
  int value;
  Node *next;
  Node *prev;  
};

class SNode {
    public:
    bool flag;
    Node *node;
};

int firstUnique(int *arr, int n) {
    int unique = INT_MIN;
    unordered_map <int, SNode*> umap (n);
    deque <Node*> dll;

    
    for (int i = 0; i < n;i++) {
        // IsExists
       if(umap[arr[i]]) {
           SNode *tbd = umap[arr[i]];
           if(tbd->flag == true) {
               tbd->flag = false;
               //  Iterate over DLL and find element to be deleted
               for(auto it = dll.begin(); it != dll.end(); it++) {
                   if((*it)->value == tbd->node->value) {
                      dll.erase(it);
                      tbd->node = NULL;
                      break;
                   }
               }
           }           
       } else {
           SNode *tmp = new SNode;
           tmp->node = new Node;
           tmp->node->value = arr[i];
           tmp->flag = true;
           umap[arr[i]] = tmp;
           dll.push_back(tmp->node);
       }
    }
    // Nothing unique case
    if (dll.empty()) {
        return unique; // default value
    }
    auto it = dll.front();
    unique = (*it).value;
    return unique;
}

int main() {
    unsigned int n;

    cin>>n;
   int arr[n];
    for(int i = 0; i < n;i++) {
       cin>>arr[i];     
    }

    cout<<firstUnique(arr, n)<<endl;
    return 0;
}

