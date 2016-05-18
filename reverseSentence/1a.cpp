/*
 * Program to reverse words in a sentence. 
 * Words are separated by a SPACE
 * Additional storage is allowed
 */

#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<list>
#include<map>
#include<unordered_map>
#include<sstream>

using namespace std;

int main() {
    string str;
    string word;
    stack <string> stk;
    getline(cin, str);
    stringstream st;
    st<<str;
    while(st>>word) {
        stk.push(word);
        stk.push(" ");
    }
    stk.pop();
    cout<<endl;

    while (!stk.empty()) {
        cout<<stk.top();
        stk.pop();
    }
    return 0;
}
