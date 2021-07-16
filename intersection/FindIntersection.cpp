#include <iostream>
#include <string>
using namespace std;

string FindIntersection(string strArr[], int arrLength) {
  int a=0, b=0;
  string res="";
  
  for(int i=0; i<strArr[0].length(); i++) {
    if(strArr[0].find(',',i)!=string::npos){
      a=stoi(strArr[0].substr(i, strArr[0].find(',',i)-i));
      i=strArr[0].find(',',i);
    }
    else{
      a=stoi(strArr[0].substr(i));
      i=strArr[0].length();
    }

    for (int j = 0; j < strArr[1].length(); j++) {
      if(strArr[1].find(",", j) != string::npos) {
        b = stoi(strArr[1].substr(j, strArr[1].find(',',j)-j));
        j = strArr[1].find(',', j);
      } else {
        b = stoi(strArr[1].substr(j));
        j = strArr[1].length();
      }
      if (a == b) {
        res.append(to_string(a)+ ",");
        break;
      }
      if (b > a) {
        break;
      }
    }

  }

  if(res.empty())
    return "false";
  else{
    res.erase(res.length()-1);
    return res;
  }
}

// Main Function
int main(void) { 
  
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << FindIntersection(A, arrLength);
  return 0;
}
