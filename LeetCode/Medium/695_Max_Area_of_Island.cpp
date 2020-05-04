class Solution {
    int DFS(vector<vector<int>>& grid, int rowIndex, int colIndex, vector<vector<bool>>& visited) {
        int area = 1;

        // when access the border, area + 0
        if(!((rowIndex >= 0) && (rowIndex < grid.size()) && (colIndex >= 0) && (colIndex < grid[0].size()))){
            return 0;
        }
        // when access the water, perimeter + 0
        if(grid[rowIndex][colIndex] == 0) {
            return 0;
        }
        // when access the visited node, perimeter + 0;
        if(visited[rowIndex][colIndex]) {
            return 0;
        }

        vector<int> rowNbr = {-1, 0, 0, 1};
        vector<int> colNbr = {0, -1, 1, 0};

        visited[rowIndex][colIndex] = true; 

        for(int i = 0; i < 4; ++i) {
           area += DFS(grid, rowIndex + rowNbr[i], colIndex + colNbr[i], visited);
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
        {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        vector<int> resultSet;
        for(int rowIndex = 0; rowIndex < row; ++rowIndex)
        {
            for(int colIndex = 0; colIndex < col; ++colIndex)
            {
                if(grid[rowIndex][colIndex] == 1 && !visited[rowIndex][colIndex])
                {
                    int result = 0;
                    result += DFS(grid, rowIndex, colIndex, visited);
                    resultSet.push_back(result);
                }
            }
        }
        return resultSet.empty()? 0 : *max_element(resultSet.begin(), resultSet.end());
    }
};