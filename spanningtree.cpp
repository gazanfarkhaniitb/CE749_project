#include<iostream>
#include<fstream>
#include<climits>
using namespace std;
int main()
{
  int n;
  int a,b,w;
  ifstream in("input.txt"); //It will help in reading input file
  in>>n;                //It will store number of nodes and number of edges.
  int matrix[n][n]{0}; //Creaating a 2D integer mattrix to store the weight of the links joining nodes and storing 0 in every cell.
  while(in)
  {
    //Loop to store the weight in matrix.
      in>>a>>b>>w;
      matrix[a][b]=w;
      matrix[b][a]=w;
  }
  int e=0;            // Integer to check number of edge and setting it to 0.
  int go[n];          // Array to check the visited node (Vertex)
  for(int i=0;i<n;i++)
  {
    //initialise the go array to false
    go[i]=false;
  }
  ofstream out("output.txt");//it will open a output fill to store output in this text file.
  //As we know that, the number of edges in a minimum spanning tree is equal to (n-1).
  out<<"Minimum Spanning Tree :"<<endl;
  go[0] = true; // This means that 0th vertex is visited.
  int x;            //  row number
  int y;            //  col number
  while (e < n - 1) 
  {
    int min = INT_MAX;
    x = 0;
    y = 0;

    for (int i = 0; i < n; i++) 
    {
      if (go[i]) 
      {
        for (int j = 0; j < n; j++) 
        {
          if (!go[j] && matrix[i][j]) 
          { 
            // not in selected and there is an edge
            if (min > matrix[i][j]) 
            {
                min = matrix[i][j];
                x = i;
                y = j;
            }
          }
        }
      }
    }
    out<<x<<" "<<y<<" "<<matrix[x][y]<<endl;
    go[y] = true;
    e++;
  }
}

