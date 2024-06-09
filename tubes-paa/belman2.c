#include <stdio.h>
#include <limits.h>
#include <string.h>

#define V 10

struct Edge
{
  int u, v, distance, cost;
};

// Fungsi untuk menemukan jalur terpendek menggunakan algoritma Bellman-Ford
void bellmanFord(struct Edge edges[], int E, int src, int dest, int useDistance)
{
  int dist[V], cost[V], predecessor[V];
  for (int i = 0; i < V; ++i)
  {
    dist[i] = INT_MAX;
    cost[i] = INT_MAX;
    predecessor[i] = -1;
  }
  dist[src] = 0;
  cost[src] = 0;

  // Relaksasi semua tepi V-1 kali
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

  // Memeriksa apakah terdapat siklus negatif
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
        return;
      }
    }
    else
    {
      if (cost[u] != INT_MAX && cost[u] + c < cost[v])
      {
        printf("Graph contains negative weight cycle\n");
        return;
      }
    }
  }

  printf("Total Distance: ");
  if (dist[dest] == INT_MAX)
  {
    printf("No path found\n");
  }
  else
  {
    printf("%d km\n", dist[dest]);
  }

  printf("Total Cost: ");
  if (cost[dest] == INT_MAX)
  {
    printf("No path found\n");
  }
  else
  {
    printf("%d\n", cost[dest]);
  }

  // Mencetak jalur
  if (dist[dest] != INT_MAX)
  {
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

int main()
{
  // (u, v, distance, cost)
  struct Edge edges[] = {
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

  // Convert user input to 0-based index
  start -= 1;
  destination -= 1;

  int useDistance = strcmp(priority, "distance") == 0 ? 1 : 0;

  printf("Shortest path from city %d to city %d based on %s:\n", start + 1, destination + 1, priority);
  bellmanFord(edges, E, start, destination, useDistance);

  return 0;
}