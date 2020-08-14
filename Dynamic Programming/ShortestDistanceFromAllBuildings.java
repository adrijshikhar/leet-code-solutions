import java.util.*;

class Solution {

  class P {
    int x;
    int y;
    int step;

    public P(final int x, final int y, final int step) {
      this.x = x;
      this.y = y;
      this.step = step;
    }
  }

  public int shortestDistance(final int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    final int[][] dist = new int[m][n];
    final int[][] counter = new int[m][n];
    int numBuildings = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ++numBuildings;
          bfs(grid, dist, counter, i, j, m, n);
        }
      }
    }

    int min = Integer.MAX_VALUE;
    boolean found = false;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][j] != 0 && counter[i][j] == numBuildings && grid[i][j] == 0) {
          min = Math.min(min, dist[i][j]);
          found = true;
        }
      }
    }

    return found ? min : -1;
  }

  private void bfs(final int[][] grid, final int[][] dist, final int[][] counter, final int x, final int y, final int m,
      final int n) {
    final boolean[][] visited = new boolean[m][n];
    final int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    final Queue<P> queue = new LinkedList<P>();
    queue.add(new P(x, y, 0));
    while (!queue.isEmpty()) {
      final P p = queue.poll();
      for (final int[] dir : dirs) {
        final int i = p.x + dir[0];
        final int j = p.y + dir[1];
        if (i >= 0 && i < m && j >= 0 && j < n && !visited[i][j] && grid[i][j] == 0) {
          queue.add(new P(i, j, p.step + 1));
          dist[i][j] += p.step + 1;
          counter[i][j] += 1;
          visited[i][j] = true;
        }
      }
    }
  }

}

public class ShortestDistanceFromAllBuildings {

  public static void main(final String[] args) {
    final int[][] grid = { { 1, 0, 2, 0, 1 }, { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, };
    final Solution s = new Solution();
    System.out.println(s.shortestDistance(grid));
  }

}
