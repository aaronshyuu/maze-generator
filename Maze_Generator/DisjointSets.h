#ifndef DISJOINTSETS_H
#define	DISJOINTSETS_H

#include <vector>

using namespace std;

class DisjointSets {
public:
    
    DisjointSets(int numElements);
    
    vector<int> set;
    int setCount;
    
    int find(int x);
    void combine(int root1, int root2);
    int getSetCount();
    
    
};

#endif	


