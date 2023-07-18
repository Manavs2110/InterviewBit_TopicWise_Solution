vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
int n,m;
void dfs(vector<vector<char>>& A,vector<vector<int>>& visit, int i,int j){
    visit[i][j] = 1;
    for(auto ele:dir){
        int x = i+ele[0];
        int y = j+ele[1];
        if(x<0 || x>=n || y<0 || y>=m) continue;
        if(A[x][y] == 'X' || visit[x][y]) continue;
        dfs(A,visit,x,y);
    }
}

void Solution::solve(vector<vector<char> > &A) {
     n = A.size();
     m = A[0].size();
    vector<vector<int>> visit(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || i==n-1 || j == 0 || j == m-1) && A[i][j] == 'O') dfs(A,visit,i,j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visit[i][j]) A[i][j]='X';
        }
    }
    
}
