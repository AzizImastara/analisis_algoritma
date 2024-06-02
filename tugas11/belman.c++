#include <iostream>
#include <vector>
#include <climits> // Untuk konstanta INT_MAX
using namespace std;
class Edge
{
public:
  int src, dest, weight;
};
class Graph
{
public:
  int V, E;
  vector<Edge> edges;
  Graph(int V, int E)
  {
    this->V = V;
    this->E = E;
  }
  void addEdge(int u, int v, int w)
  {
    Edge edge;
    edge.src = u;
    edge.dest = v;
    edge.weight = w;
    edges.push_back(edge);
  }
  void bellmanFord(int src)
  {
    vector<int> distance(V, INT_MAX);
    distance[src] = 0;
    for (int i = 1; i <= V - 1; i++)
    {
      for (int j = 0; j < E; j++)
      {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (distance[u] != INT_MAX && distance[u] + weight <
                                          distance[v])
        {
          distance[v] = distance[u] + weight;
        }
      }
    }
    // Memeriksa apakah ada siklus negatif
    for (int j = 0; j < E; j++)
    {
      int u = edges[j].src;
      int v = edges[j].dest;
      int weight = edges[j].weight;
      if (distance[u] != INT_MAX && distance[u] + weight <
                                        distance[v])
      {
        cout << "Graph contains a negative-weight cycle" << endl;
        return;
      }
    }
    printSolution(distance);
  }
  void printSolution(const vector<int> &distance)
  {
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
      if (distance[i] == INT_MAX)
      {
        cout << i << "\t\t" << "Infinity" << endl;
      }
      else
      {
        cout << i << "\t\t" << distance[i] << endl;
      }
    }
  }
};
int main()
{
  int V = 7;  // Jumlah vertex
  int E = 10; // Jumlah edge
  Graph graph(V, E);
  graph.addEdge(0, 1, 6);
  graph.addEdge(0, 2, 5);
  graph.addEdge(0, 3, 5);
  graph.addEdge(1, 4, -1);
  graph.addEdge(2, 1, -2);
  graph.addEdge(2, 4, 1);
  graph.addEdge(3, 2, -2);
  graph.addEdge(3, 5, -1);
  graph.addEdge(4, 6, 3);
  graph.addEdge(5, 6, 3);
  int source = 0; // Vertex sumber
  graph.bellmanFord(source);
  return 0;
}