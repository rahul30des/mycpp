#include <stack>
#include <string>
#include <cstdio>
#include <limits>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;


vector <bool> brace_check(list < string > values) {
    vector <bool> result;
    stack <char> stk;
    list <char> in = {'{', '(', '['};
    list <char> out = {'}', ')', ']'};
                

    for(list <string>::iterator it = values.begin(); it != values.end(); ++it) {
        string temp = *it;
        bool flag = true;
        int i = 0;
        stk = stack<char> ();
        for(; i < temp.length(); i++) {
            char ch = temp[i];

            auto iti = find(in.begin(), in.end(), ch);
            if(iti != in.end()) {
                stk.push(ch);
                continue;
            } 

            auto ito = find(out.begin(), out.end(), ch);
            if (ito != out.end()) {
                if(stk.empty()) {
                    result.push_back(false);
                    break;
                }
                char top = stk.top();
                stk.pop();
                // Ideally should have been a check on the out index equivalent
                // of top and ch 
                if (!((ch == '}' && top == '{') || (ch == ']' && top == '[')|| (ch == ')' && top == '('))) {
                    result.push_back(false);
                    break;
                } else {
                    continue;
                }
            } else {
                result.push_back(false);
                break;
            }
        }
        if (i == temp.length() && stk.empty()) {
            result.push_back(true);
        } else {
            result.push_back(false);
        }
    }
    return result;
}

// Main Function

int main() {
    list <string> values = {"{}", "{"};
    vector <bool> out;
    out = brace_check(values);
    for(vector <bool>::iterator it = out.begin(); it != out.end(); ++it) {
        bool temp = *it;
        cout<<endl<<boolalpha<<temp;
    }

    return 0;
}
