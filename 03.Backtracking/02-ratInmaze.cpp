#include <iostream>
#include <vector>
using namespace std;

void ratInMaze(int maze[][3], int row, int col, int srcx, int srcy, vector<vector<bool>> &vis, vector<string> &path, string output)
{
    // base case
    if (srcx == row - 1 && srcy == col - 1)
    {
        path.push_back(output);
        return;
    }
    vector<int> delCol = {0, -1, 1, 0};
    vector<int> delRow = {1, 0, 0, -1};
    vector<char> directions = {'D', 'L', 'R', 'U'};

    for (int i = 0; i < 4; i++)
    {
        int nRow = delRow[i] + srcx;
        int nCol = delCol[i] + srcy;

        if (nRow >= 0 && nCol >= 0 && nRow < row && nCol < col && maze[nRow][nCol] && vis[nRow][nCol] == false)
        {
            // now mark it visited
            vis[nRow][nCol] = true;

            // rec  call
            ratInMaze(maze, row, col, nRow, nCol, vis, path, output + directions[i]);

            // backtrack
            vis[nRow][nCol] = false;
        }
    }
}

int main()
{
    int maze[3][3] = {{1, 0, 0},
                      {1, 1, 0},
                      {1, 1, 1}};
    int row = 3;
    int col = 3;
    vector<string> path;
    string output = "";
    vector<vector<bool>> vis(row, vector<bool>(col, false));

    if (maze[0][0] == 0 || maze[row - 1][col - 1] == 0)
    {
        cout << "No path exits";
    }
    vis[0][0] = true;
    ratInMaze(maze, row, col, 0, 0, vis, path, output);

    for (auto it : path)
    {
        cout << it << " ";
    }
    if (path.size() == 0)
    {
        cout << "No path existed";
    }
    return 0;
}