#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Ada karena membutuhkan 2 output yaitu alur perjalanan kota dan minimum cost
pair<int, vector<int>> tsp_brute_force(vector<vector<int>> &dist_matrix)
{
    int n = dist_matrix.size();
    vector<int> kota(n);
    for (int i = 0; i < n; ++i)
    {
        kota[i] = i;
    }
    int min_cost = INT_MAX;
    vector<int> best_path;
    do
    {
        int cost = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            cost += dist_matrix[kota[i]][kota[i + 1]];
        }
        cost += dist_matrix[kota[n - 1]][kota[0]];
        if (cost < min_cost)
        {
            min_cost = cost;
            best_path = kota;
        }
    } while (next_permutation(kota.begin() + 1, kota.end()));
    return {min_cost, best_path};
}

int main()
{
    vector<vector<int>> dist_matrix = {
        // A   B   C   D
        {0, 10, 30, 25},  // A
        {10, 0, 20, 15},  // B
        {30, 20, 0, 35},  // C
        {25, 15, 35, 0}}; // D

    // Pemanggilan fungsi tsp_brute_force() dengan matriks dist_matrix.
    pair<int, vector<int>> result = tsp_brute_force(dist_matrix);

    // Mencetak biaya perjalanan minimum dan Mencetak urutan kota
    cout << "Minimum Cost: " << result.first << endl;
    cout << "Kota yang dilalui: ";

    // loop yang mencetak urutan kota yang dilalui yang berisi indeks kota yang dilalui, kemudian mencetaknya sebagai karakter.
    for (int i : result.second)
    {
        cout << char('A' + i) << ' ';
    }
    cout << 'A' << endl;
}