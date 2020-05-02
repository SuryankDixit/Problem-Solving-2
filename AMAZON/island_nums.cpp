/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
       if(grid.empty()||grid.size()==0) return 0;
				
        int rows=grid.size(),cols=grid[0].size();
        int count=0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    myDFS(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void myDFS(vector<vector<char>>& grid,int x, int y){
        int rows=grid.size();
        int cols=grid[0].size();
        
        if(x<0||y<0||x>=rows||y>=cols||grid[x][y]=='2'||grid[x][y]=='0')
             return;
        if(grid[x][y]=='1') grid[x][y]='2';
        
        myDFS(grid,x+1,y);
        myDFS(grid,x,y+1);
        myDFS(grid,x-1,y);
        myDFS(grid,x,y-1);
    }
};
