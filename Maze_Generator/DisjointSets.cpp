#include "DisjointSets.h"


DisjointSets::DisjointSets(int elementCount) {   
    // Each cell is originally in its own set
    for(int i = 0; i < elementCount; i++) {
        set.push_back(i);
    }
    setCount = elementCount;
}


int DisjointSets::find(int x) {
    // quick find
    return set[x];
}


void DisjointSets::combine(int p, int q) {

    int pset = set[p];
    //already the same set
    if (pset == set[q])
        return;
    //if different sets
    setCount--;
    for (int i = 0; i < set.size(); i++)
        if (set[i] == pset)
            set[i] = set[q];
}            


int DisjointSets::getSetCount() {
    return setCount;
}





