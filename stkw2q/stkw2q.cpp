// Implement a Stack using 2 queues 
/* 
Solution - At any item one queue (first/second) is active for stack push in O(1),
pop takes O(n) time every time and requires copying n-1 elements to non-active queue
*/

#include<iostream>
#include<queue>
#include<climits>

using namespace std;

class stack{
  unsigned int capacity;
  queue<int> fq;
  queue<int> sq;
  public:
  stack(unsigned int size) {
    capacity = size;
  }
  void push(int val) {
    // Requires sq->fq transfer
    if(!sq.empty()) {
      if(sq.size() >= capacity) {
        cout<<"Stack Full!"<<endl;
        return;
      }
      sq.push(val);
    } else {
      // Elements are in fq
      if(fq.size() >= capacity) {
        cout<<"Stack Full!"<<endl;
        return;
      } else {
        fq.push(val);
      }
    }
  }
  int pop() {
    int top = INT_MAX;
    if(fq.empty() && sq.empty()) {
      cout<<"Stack Empty!"<<endl;
      return top;
    }
    if(fq.size() >= 1) {
      while(fq.size() > 1) {
        sq.push(fq.front());
        fq.pop();
      }
      top = fq.front();
      fq.pop();
    } else {
      while(sq.size() > 1) {
        fq.push(sq.front());
        sq.pop();
      }
      top = sq.front();
      sq.pop();
    }

    return top;
  }
};

// Main Function
int main() {
  stack *inst = new stack(5);
  inst->push(1);
  inst->push(2);
  inst->push(3);
  inst->push(4);
  inst->push(5);
  inst->push(6);
  
  cout<<inst->pop()<<" ";
  cout<<inst->pop()<<" ";
  cout<<inst->pop()<<" ";
  cout<<inst->pop()<<" ";
  cout<<inst->pop()<<" ";
  cout<<inst->pop()<<" ";
  
  return 0;
}
