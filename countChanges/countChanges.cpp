#include<iostream>
#include<map>
#include<utility>

using namespace std;

map<int, int> count(map<int,int> hmap) {
   map<int, int> shmap;
   unsigned int count  = 0;

   // Simplify 
   // T O(nlogn) S O(n)
   for(auto it = hmap.begin(); it != hmap.end(); it++) {
       pair <int,int> hpair = *it;
       // Entering
       if (shmap[hpair.first]) {
            ++shmap[hpair.first];
       } else {
            shmap[hpair.first] = 1;
       }
       // Leaving
       if (shmap[hpair.second]) {
            --shmap[hpair.second];
       } else {
            shmap[hpair.second] = -1;
       }
   }

   // Add to previous count
   for(auto it = shmap.begin(); it != shmap.end(); it++) {
       pair <int,int> hpair = *it;
       shmap[hpair.first] += count;
       count = shmap[hpair.first];
   }
   return shmap;
}

// Total time complexity O(nlogn) Space O(n)
// Main
int main() {
    // Accepting input in map T O(nlogn) S O(n)
    map <int,int> umap, shmap;
    umap[3] = 7;
    umap[5] = 7;
    umap[8] = 13;
    umap[9] = 15;
    umap[7] = 17;
    shmap = count(umap);
   for(auto it = shmap.begin(); it != shmap.end(); it++) {
       pair <int,int> hpair = *it;
       cout<<endl<<hpair.first<<","<<hpair.second;
   }
   cout<<endl;

   return 0;
}
