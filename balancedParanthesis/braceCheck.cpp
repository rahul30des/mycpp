#include <stack>
#include <string>
#include <cstdio>
#include <limits>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector <bool> brace_check(vector < string > values) {
    vector <bool> result;
    vector <char> stk;
    vector <char> in = {'{', '(', '['};
    vector <char> out = {'}', ')', ']'};
                

    for(vector<string>::iterator it = values.begin(); it != values.end(); ++it) {
        string temp = *it;
        bool flag = true;
        int i = 0;
        stk.clear();
        for(; i < temp.length(); i++) {
            char ch = temp[i];

            auto iti = find(in.begin(), in.end(), ch);
            if(iti != in.end()) {
                stk.push_back(ch);
                continue;
            } 

            auto ito = find(out.begin(), out.end(), ch);
            if (ito != out.end()) {
                char top = stk.back();
                stk.pop_back();
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
    vector <string> values = {"{}", "{"};
    vector <bool> out;
    out = brace_check(values);
    for(vector <bool>::iterator it = out.begin(); it != out.end(); ++it) {
        bool temp = *it;
        cout<<endl<<boolalpha<<temp;
    }

    return 0;
}
