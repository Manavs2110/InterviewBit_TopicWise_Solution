
int n,m;
vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
void dfs(vector<vector<int>>& water,int i,int j,vector<vector<int>>& A){
    water[i][j]=1;
    for(auto ele:dir){
        int x = i+ele[0];
        int y = j+ele[1];
        // cout<<x<<" "<<y<<endl;
        if(x<0 || x >=n || y<0 || y>=m) continue;
        if(A[i][j]>A[x][y] || water[x][y]) continue;
        
        dfs(water,x,y,A);
    }
}

int Solution::solve(vector<vector<int> > &A) {
    n=A.size();
    m=A[0].size();
    vector<vector<int>> blue(n,vector<int> (m,0)), red(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        dfs(blue,i,0,A);
        dfs(red,i,m-1,A);
    }
    for(int i=0;i<m;i++){
        dfs(blue,0,i,A);
        dfs(red,n-1,i,A);
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(blue[i][j] == 1 && red[i][j]==1) count++;
        }
    }
    return count;
}