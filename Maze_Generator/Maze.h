#ifndef MAZE_H
#define	MAZE_H

#include <iostream>

using namespace std;

class Cell {
public:
    
    Cell();
    
    int theIndex;
    bool NBorder;
    bool NWall;
    bool SBorder;
    bool SWall;
    bool EBorder;
    bool EWall;
    bool WBorder;
    bool WWall;
    
    void setIndex(int index);
    int getIndex();
    
    bool getBorder(int wall); 
    void setBorder(int wall);
    
    void knockWall(int wall);   
    bool getWall(int wall);   
    
     

};

#endif	
