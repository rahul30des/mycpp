#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class q {
  stack<int> first_stack;
  stack<int> second_stack;
  unsigned int capacity;
  public:
  q(int val) {
    capacity = val;
  }
  // Enque on the queue DS
  void enq(unsigned int val) {
  // Transfer from second->first required
  if(!second_stack.empty()) {
    if(second_stack.size() >= capacity) {
      cout<<"Queue Full!"<<endl;
      return;
    }
    while(!second_stack.empty()) {
      first_stack.push(second_stack.top());
      second_stack.pop();
    }
  }
  
  if(first_stack.size() < capacity) {
    first_stack.push(val);  
  } else {
    cout<<"Queue Full!";
    return;
  }
}

// Dequeue from the queue DS
int deq() {
  unsigned int top = INT_MIN;
  
  if(first_stack.empty() && second_stack.empty()) {
    cout<<"Queue Empty!"<<endl;
    return top;
  }
  
  // Transfer from first->second required
  if(!first_stack.empty()) {
    while(!first_stack.empty()) {
      second_stack.push(first_stack.top());
      first_stack.pop();
    }
  }
  
  if(!second_stack.empty()) {
    top = second_stack.top();
    second_stack.pop();
  }
  return top;
}
};


// Main Function
int main() {
  q* inst = new (nothrow) q(5);
  inst->enq(1);
  inst->enq(2);
  inst->enq(3);
  inst->enq(4);
  inst->enq(5);
  inst->enq(6);
  
  cout<<inst->deq()<<" ";
  cout<<inst->deq()<<" ";
  cout<<inst->deq()<<" ";
  cout<<inst->deq()<<" ";
  cout<<inst->deq()<<" ";
  cout<<inst->deq()<<" ";

  return 0;
}
