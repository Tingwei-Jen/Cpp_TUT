#include "iostream"
#include <stdlib.h>

using namespace std;

struct PathConfig{
  int startX,startY,targetX,targetY;
  int mapWidth,mapHeight;
};

class AStar{
 public: 
  AStar(PathConfig config);
  ~AStar();
  int FindPath();
  void ReadPath();
  void obstacle(int x1,int x2,int y1,int y2);

 private:
  bool CornerWalkable(int i, int j);
  PathConfig _config;
 
 private:
  static const int found = 1;
  static const int nonexistent = 2;
  static const int noPath = 3;
  static const int walkable = 0;
  static const int unwalkable = 1;
  static const int onOpenList = 1;
  static const int onClosedList = 2;  
  static const int notfinished = 0;
  static const int notStarted = 0;

 private:
  int **walkability;
  int **whichList;
  int *openList;

  int *openX;
  int *openY;
  int **parentX;
  int **parentY;
  
  int pathLength;
  int pathLocation;
  int numberOfOpenListItems;
  int parentXval; 
  int parentYval;
  bool corner;
  int newOpenListItemID;

  int *Fcost;
  int **Gcost;
  int *Hcost;
  int* pathBank;

 private:
  int m;
  int addedGCost;
  int temp;
  int tempGcost;
  int path;
  int pathX;
  int pathY;
  int tempx;
  int cellPosition;
};

AStar::AStar(PathConfig config):_config(config),
  pathLength(notStarted),pathLocation(notStarted),numberOfOpenListItems(0),
  parentXval(0),parentYval(0),corner(true),newOpenListItemID(0),
  m(0),addedGCost(0),temp(0),tempGcost(0),path(0){
  
  openList = new int [_config.mapWidth*_config.mapHeight];
  openX = new int [_config.mapWidth*_config.mapHeight];
  openY = new int [_config.mapWidth*_config.mapHeight];
  Fcost = new int [_config.mapWidth*_config.mapHeight];
  Hcost = new int [_config.mapWidth*_config.mapHeight];

  walkability = new int *[_config.mapWidth];
  whichList = new int *[_config.mapWidth];
  parentX = new int *[_config.mapWidth];
  parentY = new int *[_config.mapWidth];
  Gcost = new int *[_config.mapWidth];

  for(int i = 0; i < _config.mapWidth; i++){
    walkability[i] = new int[_config.mapHeight];
    whichList[i] = new int[_config.mapHeight];
    parentX[i] = new int[_config.mapHeight];
    parentY[i] = new int[_config.mapHeight];
    Gcost[i] = new int[_config.mapHeight];
  }

  for(int i=0; i<_config.mapWidth;i++){
    for(int j=0;j<_config.mapHeight;j++){
      whichList[i][j] = 0;
    }
  }

  
  Gcost[_config.startX][_config.startY] = 0;
  cout<<"Construct Astar"<<endl;
}
AStar::~AStar(){

  delete walkability;
  delete whichList;
  delete openList;
  delete openX;
  delete openY;
  delete parentX;
  delete parentY;
  delete Fcost;
  delete Gcost;
  delete Hcost;
  delete pathBank;
}
int AStar::FindPath(){
  
  if (_config.startX == _config.targetX && _config.startY == _config.targetY )
    return nonexistent;
  if (walkability[_config.targetX][_config.targetY] == unwalkable)
    return noPath;
  
  numberOfOpenListItems =1;
	openList[1] = 1;
  openX[1] = _config.startX ; 
  openY[1] = _config.startY;

  while(1){
    if (numberOfOpenListItems != 0){
      parentXval = openX[openList[1]];
      parentYval = openY[openList[1]];
      whichList[parentXval][parentYval] = onClosedList;
      numberOfOpenListItems--;
      openList[1] = openList[numberOfOpenListItems+1];

      for (int j = parentYval-1; j <= parentYval+1; j++){
        for (int i = parentXval-1; i <= parentXval+1; i++){
          if (i != -1 && j != -1 && i != _config.mapWidth && j != _config.mapHeight){
            if (whichList[i][j] != onClosedList){
              if (walkability [i][j] != unwalkable){

                corner = CornerWalkable(i,j);
                if(corner==walkable){
                  if (whichList[i][j] != onOpenList) {

                    newOpenListItemID = newOpenListItemID + 1; 
                    m = numberOfOpenListItems+1;
                    openList[m] = newOpenListItemID;
                    openX[newOpenListItemID] = i;
                    openY[newOpenListItemID] = j;

                    if (abs(i-parentXval) == 1 && abs(j-parentYval) == 1)
                      addedGCost = 14;
                    else  
                      addedGCost = 10;

                    Gcost[i][j] = Gcost[parentXval][parentYval] + addedGCost;
                    Hcost[openList[m]] = 
                       10*(abs(i - _config.targetX) + abs(j - _config.targetY));
                    Fcost[openList[m]] = Gcost[i][j] + Hcost[openList[m]];
                    parentX[i][j] = parentXval; 
                    parentY[i][j] = parentYval;

                    while (m != 1){
                      if (Fcost[openList[m]] <= Fcost[openList[m/2]]){
                        temp = openList[m/2];
                        openList[m/2] = openList[m];
                        openList[m] = temp;
                        m = m/2;
                      } else {
                          break;
                      }
                    } 
                    numberOfOpenListItems = numberOfOpenListItems+1;
                    whichList[i][j] = onOpenList;
                  
                  } else {

                    if (abs(i-parentXval) == 1 && abs(j-parentYval) == 1)
                      addedGCost = 14;
                    else  
                      addedGCost = 10;   
                    
                    tempGcost = Gcost[parentXval][parentYval] + addedGCost;

                    if (tempGcost < Gcost[i][j]){
                      parentX[i][j] = parentXval; 
                      parentY[i][j] = parentYval;
                      Gcost[i][j] = tempGcost;

                      for (int x = 1; x <= numberOfOpenListItems; x++) {
                        if (openX[openList[x]] == i && openY[openList[x]] == j) {
                          Fcost[openList[x]] = Gcost[i][j] + Hcost[openList[x]];
                          while (m != 1){
                            if (Fcost[openList[m]] < Fcost[openList[m/2]]){
                              temp = openList[m/2];
                              openList[m/2] = openList[m];
                              openList[m] = temp;
                              m = m/2;
                            } else
                              break;
                          } 
                          break; 
                        }
                      } 
                    }
                  }
                }
              }
            }
          }
        }
      }
    } else {
      path = nonexistent; 
      break;
    }
    if (whichList[_config.targetX][_config.targetY] == onOpenList){
      path = found; 
      break;
    }
  }
  if (path == found){
    pathX = _config.targetX; 
    pathY = _config.targetY;

    while (pathX != _config.startX || pathY != _config.startY){
      tempx = parentX[pathX][pathY];    
      pathY = parentY[pathX][pathY];
      pathX = tempx;
      pathLength++;
    }
    pathBank = new int [pathLength*2];

    pathX = _config.targetX; 
    pathY = _config.targetY;
    cellPosition = pathLength*2;
    
    while (pathX !=  _config.startX || pathY !=  _config.startY){

      cellPosition = cellPosition - 2;
      pathBank[cellPosition] = pathX;
      pathBank[cellPosition+1] = pathY;
      tempx = parentX[pathX][pathY];    
      pathY = parentY[pathX][pathY];
      pathX = tempx;
    }
    return path;
  }
}
void AStar::ReadPath(){


  int map[_config.mapWidth][_config.mapHeight];
  for(int i=0;i<_config.mapWidth;i++){
    for(int j=0;j<_config.mapHeight;j++){
      map[i][j] = 0;
    }
  }
  for(int i=0;i<_config.mapWidth;i++){
    for(int j=0;j<_config.mapHeight;j++){
      if(walkability[i][j] == unwalkable){
        map[i][j] = 2;
      }
    }
  }
  pathLocation =1;
  while (pathLocation < pathLength){
    int a = pathBank[pathLocation*2-2];
    int b = pathBank[pathLocation*2-1];
    pathLocation = pathLocation+ 1;
    map[a][b] = 1;
  } 
  for(int j=0;j<_config.mapHeight;j++){
    for(int i=0;i<_config.mapWidth;i++){
      cout<<map[i][j]<<"  ";
    }
    cout<<endl;
  }



}
bool AStar::CornerWalkable(int i, int j){

  if (i == parentXval-1) {
    if (j == parentYval-1){
      if (walkability[parentXval-1][parentYval] == unwalkable
          || walkability[parentXval][parentYval-1] == unwalkable){
        return true;
      }                      
    } else if (j == parentYval+1) {
      if (walkability[parentXval][parentYval+1] == unwalkable
          || walkability[parentXval-1][parentYval] == unwalkable){
        return true;
      } 
    } 
  } else if (i == parentXval+1) {
    if (j == parentYval-1) {
      if (walkability[parentXval][parentYval-1] == unwalkable 
          || walkability[parentXval+1][parentYval] == unwalkable){ 
        return true;
      }
    } else if (j == parentYval+1) {
      if (walkability[parentXval+1][parentYval] == unwalkable 
          || walkability[parentXval][parentYval+1] == unwalkable) {
        return true;
      }
    }
  } else {
    return false;
  } 
}
void AStar::obstacle(int x1,int x2,int y1,int y2){

  for(int i=x1;i<x2;i++){
    for(int j=y1;j<y2;j++){
      walkability[i][j] = unwalkable;
    }
  }
}

int main(){
  
  PathConfig config;
  config.startX = 2;
  config.startY = 2;
  config.targetX = 18;
  config.targetY = 18;
  config.mapWidth = 20;
  config.mapHeight = 20;

  AStar* path = new AStar(config);
  path->obstacle(4,7,4,7);
  path->FindPath();
  path->ReadPath();



  return 0;
}