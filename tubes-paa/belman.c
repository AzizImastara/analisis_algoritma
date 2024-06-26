#include <stdio.h>
#include <limits.h>
#include <string.h>

#define V 10

typedef struct
{
  int u, v, distance, cost;
} Edge;

// inisiasi array dist, cost,dan predecessor
void initializeArrays(int dist[], int cost[], int predecessor[], int src)
{
  for (int i = 0; i < V; ++i)
  {
    dist[i] = INT_MAX;
    cost[i] = INT_MAX;
    predecessor[i] = -1;
  }
  dist[src] = 0;
  cost[src] = 0;
}

// relaksasi semua tepi V-1 kali
void relaxEdges(Edge edges[], int E, int dist[], int cost[], int predecessor[], int useDistance)
{
  for (int i = 1; i <= V - 1; ++i)
  {
    for (int j = 0; j < E; ++j)
    {
      int u = edges[j].u - 1;
      int v = edges[j].v - 1;
      int d = edges[j].distance;
      int c = edges[j].cost;

      if (useDistance)
      {
        if (dist[u] != INT_MAX && dist[u] + d < dist[v])
        {
          dist[v] = dist[u] + d;
          cost[v] = cost[u] + c;
          predecessor[v] = u;
        }
      }
      else
      {
        if (cost[u] != INT_MAX && cost[u] + c < cost[v])
        {
          cost[v] = cost[u] + c;
          dist[v] = dist[u] + d;
          predecessor[v] = u;
        }
      }
    }
  }
}

// memeriksa apakah terdapat siklus negatif
int checkForNegativeCycle(Edge edges[], int E, int dist[], int cost[], int useDistance)
{
  for (int j = 0; j < E; ++j)
  {
    int u = edges[j].u - 1;
    int v = edges[j].v - 1;
    int d = edges[j].distance;
    int c = edges[j].cost;

    if (useDistance)
    {
      if (dist[u] != INT_MAX && dist[u] + d < dist[v])
      {
        printf("Graph contains negative weight cycle\n");
        return 1;
      }
    }
    else
    {
      if (cost[u] != INT_MAX && cost[u] + c < cost[v])
      {
        printf("Graph contains negative weight cycle\n");
        return 1;
      }
    }
  }
  return 0;
}

void printResult(int dist[], int cost[], int predecessor[], int dest)
{
  if (dist[dest] == INT_MAX)
  {
    printf("Total Distance: No path found\n");
    printf("Total Cost: No path found\n");
  }
  else
  {
    printf("Total Distance: %d km\n", dist[dest]);
    printf("Total Cost: %d\n", cost[dest]);

    printf("Path: ");
    int path[V];
    int count = 0;
    for (int at = dest; at != -1; at = predecessor[at])
    {
      path[count++] = at + 1;
    }
    for (int i = count - 1; i > 0; --i)
    {
      printf("%d -> ", path[i]);
    }
    printf("%d\n", path[0]);
  }
}

void bellmanFord(Edge edges[], int E, int src, int dest, int useDistance)
{
  int dist[V], cost[V], predecessor[V];
  initializeArrays(dist, cost, predecessor, src);
  relaxEdges(edges, E, dist, cost, predecessor, useDistance);

  if (!checkForNegativeCycle(edges, E, dist, cost, useDistance))
  {
    printResult(dist, cost, predecessor, dest);
  }
}

int main()
{
  // (u, v, distance, cost)
  Edge edges[] = {
      {1, 2, 2, 14},
      {1, 3, 4, 10},
      {1, 4, 3, 8},
      {2, 5, 7, 7},
      {2, 6, 4, 7},
      {2, 7, 6, 10},
      {3, 5, 3, 12},
      {3, 6, 2, 8},
      {3, 7, 4, 6},
      {4, 5, 4, 15},
      {4, 6, 1, 6},
      {4, 7, 5, 4},
      {5, 8, 1, 10},
      {5, 9, 4, 8},
      {6, 8, 6, 5},
      {6, 9, 3, 5},
      {7, 8, 3, 9},
      {7, 9, 3, 7},
      {8, 10, 3, 3},
      {9, 10, 4, 5}};

  int E = sizeof(edges) / sizeof(edges[0]);
  int start, destination;
  char priority[10];

  printf("Enter start city (1-10): ");
  scanf("%d", &start);
  printf("Enter end city (1-10): ");
  scanf("%d", &destination);
  printf("Enter priority (distance/cost): ");
  scanf("%s", priority);

  start -= 1;
  destination -= 1;

  int useDistance = strcmp(priority, "distance") == 0;

  printf("Shortest path from city %d to city %d based on %s:\n", start + 1, destination + 1, priority);
  bellmanFord(edges, E, start, destination, useDistance);

  return 0;
}
