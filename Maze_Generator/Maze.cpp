#include <iostream> 

#include "Maze.h"
#include "DisjointSets.h"

using namespace std;                           // 0 is north, 1 is south, 2 is east, 3 is west


Cell::Cell() {
    // Set intial border and walls
    NBorder = false;
    NWall = true;
    SBorder = false;
    SWall = true;
    EBorder = false;
    EWall = true;
    WBorder = false;
    WWall = true;
    
}

void Cell::setIndex(int index) {
    // setter for index
    theIndex = index;
}


int Cell::getIndex() {
    // getter for index
    return theIndex;
}


void Cell::setBorder(int wall) { 
    // setter for borders
    if (wall == 0) {
        NBorder = true;     
    } else if (wall == 1) {
        SBorder = true;
    } else if (wall == 2) {
        EBorder = true;
    } else {
        WBorder = true;
    }
    
}


bool Cell::getBorder(int wall) { 
    // getter for borders
    if (wall == 0) {
        return NBorder;
    } else if (wall == 1) {
        return SBorder;
    } else if (wall == 2) {
        return EBorder;
    } else {
        return WBorder;
    }
   
}


bool Cell::getWall(int wall) { 
    // getter for walls
    if (wall == 0) {
        return NWall;
    } else if (wall == 1) {
        return SWall;
    } else if (wall == 2) {
        return EWall;
    } else {
        return WWall;
    }
    
}


void Cell::knockWall(int wall) {  
    
   if (wall == 0) {
        NWall = false;
    } else if (wall == 1) {
        SWall = false;
    } else if (wall == 2) {
        EWall = false;
    } else {
        WWall = false;
    } 
    
}


int main(){
    

    // Prompt for maze dimensions
    cout << "Welcome to maze generator!" << endl << endl;
    int rows;
    int columns;
    cout << "Number of rows for maze? ";
    cin >> rows;
    cout << endl << "Number of columns for maze? ";
    cin >> columns;
    cout << endl;
    
    
    DisjointSets theSet(rows * columns);
    Cell Grid[rows][columns];
    
    // Set index for grid
    int indexx = 0;
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            Grid[i][j].setIndex(indexx);
            indexx++;
        }
    }
    
    
    // Set borders for all cells 
    for(int i = 0; i < columns; i++) {
        Grid[0][i].setBorder(0);            
        Grid[(rows - 1)][i].setBorder(1);   
    }
     
    for(int i = 0; i < rows; i++) {
        Grid[i][(columns - 1)].setBorder(2);      
        Grid[i][0].setBorder(3);                  
    }

   
    // Breaking walls
    srand (time(0));
    
    while(theSet.setCount > 1) {   
        
        int randomWall = rand() % 4;
        int randomRow = rand() % rows;
        int randomColumn = rand() % columns;
        

        // Index number of chosen cell
        int index = Grid[randomRow][randomColumn].getIndex();


        
        // Disjoint set data structure used (quick find)
        if (randomWall == 0) { 
            if(Grid[randomRow][randomColumn].getBorder(0) != true) {
                if(theSet.find(index) != theSet.find(index-columns)) {
                    theSet.combine(index, index - columns);
                    Grid[randomRow][randomColumn].knockWall(0);
                    Grid[randomRow - 1][randomColumn].knockWall(1);
                }
            }
        } else if (randomWall == 1) { 
            if(Grid[randomRow][randomColumn].getBorder(1) != true) {
                if(theSet.find(index) != theSet.find(index + columns)) {
                    theSet.combine(index, index + columns);
                    Grid[randomRow][randomColumn].knockWall(1);
                    Grid[(randomRow + 1)][randomColumn].knockWall(0);
                }
            }
        } else if (randomWall == 2) { 
            if(Grid[randomRow][randomColumn].getBorder(2) != true) {
                if(theSet.find(index) != theSet.find(index + 1)) {
                    theSet.combine(index, index + 1);
                    Grid[randomRow][randomColumn].knockWall(2);
                    Grid[randomRow][randomColumn + 1].knockWall(3);
                }
            }
        } else { 
            if(Grid[randomRow][randomColumn].getBorder(3) != true) {
                if(theSet.find(index) != theSet.find(index - 1)) {
                    theSet.combine(index, ((index - 1)));
                    Grid[randomRow][randomColumn].knockWall(3);
                    Grid[randomRow][randomColumn - 1].knockWall(2);
                }
            }
        }
        
    }
  
  // Break 2 obligated walls (on east side and west side)
    int wallOne = rand() % rows;
    Grid[wallOne][0].knockWall(3);
    int wallTwo = rand() % rows;
    Grid[wallTwo][columns - 1].knockWall(2);
  
    
   // ******* Print Maze *******
    
  // Print north border wall
    cout << '+';
    for(int j = 0; j < columns; j++) {
        cout << "--+";
    }
    cout << endl;

    for(int i = 0; i< rows; i++) {  
       // Print west walls and spaces for each cell
        for(int j = 0; j < columns; j++) {
            if(Grid[i][j].getWall(3)) {
                cout << "|  ";
            }
            else {
                cout << "   ";
            }
         }

        // East border wall
        if(Grid[i][columns-1].getWall(2)) {
            cout << "|";
        } else {
            cout << " ";
        }
        cout << endl;

         // South wall for each cell
        cout << '+';
        for(int j = 0; j < columns; j++) {
            if(Grid[i][j].getWall(1)) {
                cout << "--";
            } else {
                cout << "  ";
            }
            cout << "+";
        }
        cout << endl;
    }
      
    return 0;
}
