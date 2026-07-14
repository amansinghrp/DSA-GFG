class Solution {
  private:
    vector<vector<int>>dirs = {
        {1, 0},//down
        {0, -1},//left
        {0, 1},//right
        {-1, 0}//up
    };
    
    bool isValid(int row, int col, int &n){
        if(row >=0 && row < n && col >= 0 && col <n){
            return true;
        }
        return false;
    }
    
    void solve(int row, int col, vector<vector<int>>& maze, string &curr, vector<string>& ans, int &n){
        if(row == n-1 && col == n-1){
            ans.push_back(curr);
            return;
        }
        
        maze[row][col] = 0;
        
        for(int i=0; i<4; i++){
            int nrow = row + dirs[i][0];
            int ncol = col + dirs[i][1];
            
            char ch = i == 0 ? 'D' : i == 1 ? 'L' : i == 2 ? 'R' : 'U';
            
            if(isValid(nrow, ncol, n) && maze[nrow][ncol] == 1){
                curr += ch;
                solve(nrow, ncol, maze, curr, ans, n);
                curr.pop_back();
            }
            
        }
        
        maze[row][col] = 1;
    }
    
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        if(maze[0][0] == 0) return {""};
        int n = maze.size();
        vector<string>ans;
        string curr = "";
        solve(0, 0, maze, curr, ans, n);
        return ans;
    }
};