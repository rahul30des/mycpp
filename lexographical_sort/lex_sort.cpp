#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

// Main Function
int main() {
     int size = 0;
     cin>>size;
     vector <string> vstr(size);
    
     for(int i = 0; i < size; i++) {
         string str;
         cin>>str;
         vstr.push_back(str);
     }
     sort(vstr.begin(), vstr.end());

     for(vector<string>::iterator it = vstr.begin(); it !=vstr.end(); it++) {
         string str = *it;
         cout<<str<<endl;
     }

     return 0;
}


