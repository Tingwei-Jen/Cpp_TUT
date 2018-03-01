#include "iostream"

using namespace std;

#define V 7
#define INT_MAX 100000

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
  // Initialize min value
  int min = INT_MAX; 
  int min_index;
 
  for (int v = 0; v < V; v++){
    if (sptSet[v] == false && dist[v] <= min) //sptSet[v] == false ==== Q
      min = dist[v], min_index = v;           //sptSet[v] == true ==== S
  }
 
   return min_index;
}
int printSolution(int dist[], int path[],int n)
{
   cout<<"Vertex   Distance from Source  Path"<<endl;
   for (int i = 0; i < V; i++){
   	  cout<<i<<"           "<<dist[i]<<"     "<<path[i]<<endl;
   }
}
void dijkstra(int graph[V][V],int source){

  int dist[V]; // The output array.  dist[i] will hold the shortest
               // distance from src to i
  bool sptSet[V];    // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
   
  int path[V];

  // Initialize all distances as INFINITE and stpSet[] as false
  for (int i = 0; i < V; i++){
    dist[i] = INT_MAX;
    sptSet[i] = false;
    path[i] = 0;
  }

  // Distance of source vertex from itself is always 0
  dist[source] = 0;

  // Find shortest path for all vertices
  for (int count = 0; count < V-1; count++){

    // Pick the minimum distance vertex from the set of vertices not
    // yet processed. u is always equal to src in first iteration.
    int u = minDistance(dist, sptSet);
    sptSet[u] = true;
    // Update dist value of the adjacent vertices of the picked vertex.
    for (int v = 0; v < V; v++){

      // Update dist[v] only if is not in sptSet, there is an edge from 
      // u to v, and total weight of path from src to  v through u is 
      // smaller than current value of dist[v]
      if (graph[u][v] && dist[u] != INT_MAX 
      						&& dist[u]+graph[u][v] < dist[v]){
      	dist[v] = dist[u] + graph[u][v];
        path[v] = u;
      }
    }
  }
  printSolution(dist,path,V);
}



int main(){
   int graph[V][V] = {{0, 4, 6, 6, 0, 0, 0},
                      {0, 0, 1, 0, 7, 0, 0},
                      {0, 0, 0, 0, 6, 4, 0},
                      {0, 0, 2, 0, 0, 5, 0},
                      {0, 0, 0, 0, 0, 0, 6},
                      {0, 0, 0, 0, 1, 0, 8},
                      {0, 0, 0, 0, 0, 0, 0}
                  };
 
    dijkstra(graph, 0);



  return 0;	
}