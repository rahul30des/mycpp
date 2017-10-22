#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int size = 0;
    cin>>size;
    vector <string> str(size);
    // Input - O(n)
    for(int i = 0; i < size; i++) {
        string temp;
        cin>>temp;
        str.push_back(temp);
    }

    // Sorting - Time Complexity O(nlogn)
    sort(str.begin(), str.end());

    for(auto it = str.begin(); it != str.end(); it++) {
        cout<<endl<<*it;
    }
    return 0;
}
