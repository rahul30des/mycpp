#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<list>

using namespace std;

// Delete value at a specific index
void delet(vector<int>& arr) {
    unsigned int idx = 0;
    // Can be modified to search for value and update at that slot
    cout<<endl<<"Enter index to delete : ";
    cin>>idx;
    if(idx >= arr.size()) {
        cout<<endl<<"Error : Invalid Index";
    } else {
        arr[idx] = 0;
    }
}

// Update value at a specific index
void update(vector<int>& arr) {
    unsigned int idx = 0;
    // Can be modified to search for value and update at that slot
    cout<<endl<<"Enter index to update : ";
    cin>>idx;
    if(idx >= arr.size()) {
        cout<<endl<<"Error : Invalid Index";
    } else {
        cout<<endl<<"Enter new value (0 or more) : ";
        cin>>arr[idx];
        if(arr[idx] <= 0) {
            arr[idx] = 0;
        }
    }
}

// Displays the output vector
void display(vector<int> out) {
    cout<<endl;
    for(int i = 0; i < out.size(); i++) {
        cout<<out[i]<<"\t";
    }
}

//Function to allow appending of element at end of vector
vector<int> append(vector<int> arr) {
    int value = 0;
    int vsize = arr.size();
    vector<int> narr(vsize + 1);
    copy(arr.begin(), arr.end(), narr.begin());
    cout<<endl<<"Enter value to append : ";
    cin>>narr[vsize];
    if(narr[vsize] <= 0) {
        narr[vsize] = 0;
    }
    return narr;
}


// Function to simulate cascade using dominos and their heights
vector<int> triggerCascade(vector<int> arr) {
    int vsize = arr.size();
    vector<int> out(vsize);

    // Right->Left Sweep - DP solution O(n) 
    for(int i = (vsize - 1); i >= 0; i--) {
        // No height or -ve val (error case)
        if(arr[i] <= 0) {
            out[i] = i;
        } else { 
            int reach = arr[i] + i;
            // Value at height exceeds x axis limit
            if(reach >= vsize) {
                out[i] = reach; 
            } else {
                out[i] = out[reach];
            }
        }
    }

    /* Does not cover instance of intermediate value exceeding the 
     * cascade as only check values of me and value at index of
     * my value so keep track of max value in intermediate range
     * by doing another sweep this time in reverse
     */
    // Time Complexity O(n) 
    // Pair stores current max and its index
    pair<int, unsigned int> currMax;
    // Might also need to keep a list of all backreferences that need to be
    // updated when I am updated and then update all backrefs in another pass
    vector<list<int>> dep(vsize);
    currMax.first = arr[0];
    currMax.second = 0;
    for(unsigned int i = 1; i < vsize; i++) {
        if(out[i] > currMax.first) {
            dep[i] = {};
            // Update previous max value at its index
            if (i <= currMax.first) {
                out[currMax.second] = out[i];
                dep[i].push_back(currMax.second);
            }
            currMax.first = out[i];
            currMax.second = i;
        }
    }
    // Time Complexity O(n2) for the backref traversal for every node
    // Space Complexity O(n) in addition to out - another vector of size n with
    // list of some variables lets say ~ O(n)
    for(int i = (vsize - 1); i >= 0; i--) {
        for(auto it = dep[i].begin(); it != dep[i].end(); it++) {
            out[(*it)] = out[i]; 
        }
    }
    return out;
}

// Time Complexity O(n)
// Space Complexity O(n)
// Compile using g++ -o out -std=c++11 domino.cpp
// Execute ./out
int main() {
    vector<int> arr = {0, 0, 4, 1, 0, 2, 0, 1, 0, 0, 3};
    vector<int> out;
    out = triggerCascade(arr);
    display(out);

    arr = append(arr);
    out = triggerCascade(arr);
    display(out);

    update(arr);
    out = triggerCascade(arr);
    display(out);

    // Delete
    delet(arr);
    out = triggerCascade(arr);
    display(out);

    return 0;
}
