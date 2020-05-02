class Solution {
public:
    bool isSafe(vector<vector<char>>& grid, int rowIndex, int colIndex, vector<vector<bool>>& visited)
    {
        int ROW = grid.size();
        int COL = grid[0].size();
        return (rowIndex >= 0) && (rowIndex < ROW) && (colIndex >= 0) && (colIndex < COL) && (grid[rowIndex][colIndex] == '1' && !visited[rowIndex][colIndex]);
    }

    void DFS(vector<vector<char>>& grid, int rowIndex, int colIndex, vector<vector<bool>>& visited)
    {
        vector<int> rowNbr = {-1, 0, 0, 1};
        vector<int> colNbr = {0, -1, 1, 0};

        visited[rowIndex][colIndex] = true; 

        for(int i = 0; i < 4; ++i)
        {
            if(isSafe(grid, rowIndex + rowNbr[i], colIndex + colNbr[i], visited))
            {
                DFS(grid, rowIndex + rowNbr[i], colIndex + colNbr[i], visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        int count = 0;
        for(int rowIndex = 0; rowIndex < row; ++rowIndex)
        {
            for(int colIndex = 0; colIndex < col; ++colIndex)
            {
                if(grid[rowIndex][colIndex] == '1' && !visited[rowIndex][colIndex])
                {
                    DFS(grid, rowIndex, colIndex, visited);
                    ++count;
                }
            }
        }
        
        return count;
    }
};