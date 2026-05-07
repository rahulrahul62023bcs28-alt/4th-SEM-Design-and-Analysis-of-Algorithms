#include <iostream>
using namespace std;
#define INF 99999
void floydWarshall(int dist[][10], int n)
{
   for (int k = 0; k < n; k++)
   {
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            if (dist[i][k] != INF && dist[k][j] != INF)
            {
               if (dist[i][k] + dist[k][j] < dist[i][j])
               {
                  dist[i][j] = dist[i][k] + dist[k][j];
               }
            }
         }
      }
   }
}
int main()
{
   int n;
   cout << "Enter number of vertices: ";
   cin >> n;
   int dist[10][10];
   cout << "Enter adjacency matrix (use 99999 for INF):\n";
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cin >> dist[i][j];
      }
   }
   floydWarshall(dist, n);
   cout << "\nShortest distance matrix:\n";
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (dist[i][j] == INF)
            cout << "INF ";
         else
            cout << dist[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}
