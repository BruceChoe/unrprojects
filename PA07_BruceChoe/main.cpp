// CPP program to implement traveling salesman
// problem using naive approach.
#include <bits/stdc++.h>
using namespace std;
#define V 5
#include <fstream>

// implementation of traveling Salesman Problem
template <class ItemType>
ItemType travellingSalesmanProblem(ItemType graph[][V], int s)
{
    ofstream outfile;
    outfile.open ("tsp.txt");
    
   // store all vertex apart from source vertex
   vector<int> vertex;
   int path[V],temp[V];
   for (int i = 0; i < V; i++) {
       if (i != s)
           vertex.push_back(i);
    }
   // store minimum weight Hamiltonian Cycle.
   float min_path = INT_MAX;
   do {

       // store current Path weight(cost)
       float current_pathweight = 0;
      
       // compute current path weight
       int k = s;
       outfile << k+1 << "->";
       for (int i = 0; i < vertex.size(); i++) {
          
           current_pathweight += graph[k][vertex[i]];
           k = vertex[i];
           temp[i]=k;
       }
       current_pathweight += graph[k][s];
       for(int i = 0; i < V-1; i++)
       {
           if (i==V-2) 
                outfile<< temp[i]+1 <<endl;
           else 
                outfile << temp[i]+1 << "->";
       }
       // update minimum
       min_path = min(min_path, current_pathweight);
       if(min_path == current_pathweight)
       {
           for(int i = 0; i < V-1; i++)
           {
               path[i]=temp[i];
           }
       }
      
   } while (next_permutation(vertex.begin(), vertex.end()));
   outfile<<"Selected path: " << s+1 << "->";
   for(int i = 0; i < V-1; i++)
   {    
       if(i==V-2) 
        outfile << path[i]+1 << "->" << s+1 << endl;
       else 
        outfile << path[i]+1<< "->";
   }
   outfile.close();
   return min_path;
}


int main()
{
// matrix representation of graph
   int graph[][V] = { { 0, 218, 518, 704, 439 }, // Reno to X
                   { 218, 0, 1000000, 808, 569 }, // SF to X
                   { 518, 1000000, 0, 835, 421 }, // Salt Lake City to X
                   { 704, 808, 835, 0, 1115 }, // Seattle to X
                   {439, 569, 421, 1115, 0 }  // Las Vegas to X
                   };
   int s = 0;
   travellingSalesmanProblem(graph, s);
   return 0;
}
