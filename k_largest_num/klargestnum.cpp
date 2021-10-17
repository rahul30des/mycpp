/*
*  K largest elements from a stream of elements using Min Heap
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
  public:
  int value;
  string name;
  bool greater(Node *snode) {
    return (this->value > snode->value);
  }
};

struct compare {
  bool operator()(Node *snode1, Node* snode2) {
    return snode1->greater(snode2);
  }
};


// Main Function
int main() {
  unsigned int capacity = 3;
  unsigned int curr_size = 0;
  vector<Node*> arr;
  
  Node *snode1 = new Node();
  snode1->value = 43;
  snode1->name = "apple";
  arr.push_back(snode1);
  
  Node *snode2 = new Node();
  snode2->value = 9;
  snode2->name = "orange";
  arr.push_back(snode2);
  
  Node *snode3 = new Node();
  snode3->value = 150;
  snode3->name = "cherry";
  arr.push_back(snode3);
  
  Node *snode4 = new Node();
  snode4->value = 7;
  snode4->name = "berry";
  arr.push_back(snode4);
  
  
  priority_queue<Node*, vector<Node*>, compare> pq;
  
  for(unsigned int i = 0; i < arr.size(); i++) {
    if(curr_size < capacity) {
      pq.push(arr[i]); 
      curr_size++;
    } else {
      Node* top = pq.top();
      if(top->value < arr[i]->value) {
        pq.pop();
        pq.push(arr[i]);
      }
    }
  }
  
  while(!pq.empty()) {
    cout<<pq.top()->name<<" "<<pq.top()->value<<endl;
    pq.pop();
  }

  return 0;
}
