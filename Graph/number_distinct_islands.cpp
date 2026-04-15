/*
  https://takeuforward.org/data-structure/number-of-distinct-islands

    Problem Statement: Given a boolean 2D matrix grid of size N x M. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island.
    Two islands are considered to be distinct if and only if one island is equal to another (not rotated or reflected).

    🔹 Time Complexity
1. Grid Traversal
for (i = 0 → R)
  for (j = 0 → C)

👉 Cost:

O(R × C)
2. DFS Traversal

Key property:

Each cell is visited exactly once

So across all DFS calls:

O(R × C)
3. Shape Construction

For each island:

You store coordinates of size K

Across all islands:

Total stored coordinates ≤ R × C

👉 Cost:

O(R × C)
4. Insertion into set

This is the non-trivial part.

You do:

set<vector<pair<int,int>>> shapes;
Cost of insertion:
Comparing vectors = O(K) (lexicographical compare)
Set insertion = O(log N) where N = number of islands

👉 Per island:

O(K log N)

👉 Across all islands:

O((R × C) log N)
🔹 Final Time Complexity
O(R × C) + O((R × C) log N)
≈ O((R × C) log N)
🔹 Worst Case
Every cell is its own island → N = R × C

👉 Then:

O((R × C) log(R × C))
🔹 Space Complexity
1. Visited array
O(R × C)
2. Shape storage

Worst case:

All islands distinct
Total stored coordinates = R × C
O(R × C)
3. DFS recursion stack

Worst case (snake-like island):

O(R × C)
🔹 Final Space Complexity
O(R × C)

*/


class Solution {
    /* row, col are cordinates of cell. baser, basec cords of starting cell*/
    void dfs(int row, int col, int baser, int basec,
             vector<vector<int>>& grid,
             vector<vector<int>>& visited,
             vector<pair<int,int>>& shape) {

        int m = grid.size();
        int n = grid[0].size();

        visited[row][col] = 1;

        /* store relative coordinate wrt to base cordinates */
        shape.emplace_back(row - baser, col - basec);

        static vector<pair<int,int>> dirs = {
            {1,0}, {0,1}, {-1,0}, {0,-1}
        };

        for (auto &[dx, dy] : dirs) {
            int nx = row + dx;
            int ny = col + dy;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                !visited[nx][ny] && grid[nx][ny] == 1) {
                dfs(nx, ny, baser, basec, grid, visited, shape);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        set<vector<pair<int,int>>> shapes;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (!visited[i][j] && grid[i][j] == 1) {
                    vector<pair<int,int>> shape;

                    dfs(i, j, i, j, grid, visited, shape);

                    shapes.insert(shape); // insert ONLY once per island
                }
            }
        }

        return shapes.size();
    }
};