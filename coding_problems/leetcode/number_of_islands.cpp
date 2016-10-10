#include <vector>

using namespace std;

typedef vector<vector<char> > vvc;

struct Direction {
  int row_inc;
  int col_inc;
  Direction(int ri, int ci) : row_inc(ri), col_inc(ci) {};
};

Direction dirs[] = {Direction(-1, 0), Direction(1, 0), Direction(0, 1), Direction(0, -1)};

bool need_explore(vvc& grid, int row, int col) {
  bool in_bounds = row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
  bool part_of_island = in_bounds && grid[row][col] == '1';
  return part_of_island;
}

void dfs(vvc& grid, int row, int col) {
  for (int i = 0; i < 4; ++i) {
    int moved_row = row+dirs[i].row_inc;
    int moved_col = col+dirs[i].col_inc;
    if (need_explore(grid, moved_row, moved_col)) {
      grid[moved_row][moved_col] = '0';
      dfs(grid, moved_row, moved_col);
    }
  }
}

int numIslands(vvc& grid) {
  if (grid.empty()) return 0;
  int islands = 0, rows = grid.size(), cols = grid[0].size();
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (grid[i][j] == '1') {
        ++islands;
        grid[i][j] = '0';
        dfs(grid, i, j);
      }
    }
  }

  return islands;
}
