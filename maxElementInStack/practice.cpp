#include<iostream>
#include<stack>

using namespace std;

class maxStack {
    stack<int> stk;
    stack<int> mstk;
public:
    int push(int item);
    int pop();
    int popMax();
};

int maxStack::push(int item) {
    stk.push(item);
    if (mstk.empty() || item >= mstk.top()) {
        mstk.push(item);
    }

    return item;
}

int maxStack::pop() {
    int item = -1;

    if (!stk.empty()) {
        item = stk.top();
        stk.pop();
        if ((!mstk.empty()) && (item == mstk.top())) {
            mstk.pop();
        }
    }
    return item;
}

int maxStack::popMax() {
    int item = -1;
    if(!mstk.empty()) {
        item = mstk.top();
    }
    return item;
}

/*
 * Output:
 * 7 7 4 5
 *
 */
int main() {
    maxStack obj;
    obj.push(5);
    obj.push(3);
    obj.push(1);
    obj.push(4);
    obj.push(7);
    cout<<obj.popMax();
    cout<<obj.pop();
    cout<<obj.pop();
    cout<<obj.popMax();
    return 0;
}
