class Solution {
    int DFS(vector<vector<int>>& grid, int rowIndex, int colIndex, vector<vector<bool>>& visited) {
        int perimeter = 0;

        // when access the border, perimeter + 1
        if(!((rowIndex >= 0) && (rowIndex < grid.size()) && (colIndex >= 0) && (colIndex < grid[0].size()))){
            return 1;
        }
        // when access the water, perimeter + 1
        if(grid[rowIndex][colIndex] == 0) {
            return 1;
        }
        // when access the visited node, perimeter + 0;
        if(visited[rowIndex][colIndex]) {
            return 0;
        }

        vector<int> rowNbr = {-1, 0, 0, 1};
        vector<int> colNbr = {0, -1, 1, 0};

        visited[rowIndex][colIndex] = true; 

        for(int i = 0; i < 4; ++i) {
           perimeter += DFS(grid, rowIndex + rowNbr[i], colIndex + colNbr[i], visited);
        }
        return perimeter;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty())
        {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        int result = 0;
        for(int rowIndex = 0; rowIndex < row; ++rowIndex)
        {
            for(int colIndex = 0; colIndex < col; ++colIndex)
            {
                if(grid[rowIndex][colIndex] == 1 && !visited[rowIndex][colIndex])
                {
                   result += DFS(grid, rowIndex, colIndex, visited);
                }
            }
        }
        return result;
    }
};