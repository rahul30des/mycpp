/*
 * Program to reverse words in a sentence. 
 * Words are separated by a SPACE
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

/*
 * Function to reverse a string 
 */
void rev(char *str, int len) {
    int i = 0, j = len - 1;
    while(i < len/2) {
        str[i] = str[i] ^ str[j];
        str[j] = str[i] ^ str[j];
        str[i] = str[i] ^ str[j];
        i++;
        j--;
    }
}

/*
 * Function to reverse a sentence
 */
string rev_sen(string str) {
    stringstream st;
    string word;
    string out;
    st<<str;
    while(st>>word) {
       rev(&word[0], word.size());
       out.append(word); 
       out.append(" "); 
    }
    out[out.size() - 1] = '\0';
    return out;
}

int main() {
    string inputStr;
    string out;
    getline(cin, inputStr);
    out = rev_sen(inputStr);
    rev(&out[0], out.size());
    cout<<endl<<out;
    return 0;
}
