class Solution {
public:
    vector<string> ans;

    void solve(int i, int j, string &path,
               vector<vector<int>> &grid,
               int n,
               vector<vector<int>> &vis) {

        // invalid cell
        if (i < 0 || j < 0 || i >= n || j >= n ||
            grid[i][j] == 0 || vis[i][j]) {
            return;
        }

        // mark visited
        vis[i][j] = 1;

        // destination reached
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            vis[i][j] = 0;
            return;
        }

        // Down
        path.push_back('D');
        solve(i + 1, j, path, grid, n, vis);
        path.pop_back();

        // Left
        path.push_back('L');
        solve(i, j - 1, path, grid, n, vis);
        path.pop_back();

        // Right
        path.push_back('R');
        solve(i, j + 1, path, grid, n, vis);
        path.pop_back();

        // Up
        path.push_back('U');
        solve(i - 1, j, path, grid, n, vis);
        path.pop_back();

        // unmark visited (backtrack)
        vis[i][j] = 0;
    }

    vector<string> findPath(vector<vector<int>> &grid) {
        ans.clear();
        int n = grid.size();

        if (grid[0][0] == 0) return {"-1"};

        vector<vector<int>> vis(n, vector<int>(n, 0));
        string path = "";

        solve(0, 0, path, grid, n, vis);

        if (ans.empty()) return {"-1"};
        return ans;
    }
};

//T.C = O(4^(N^2))
//S.C = O(N^2)
