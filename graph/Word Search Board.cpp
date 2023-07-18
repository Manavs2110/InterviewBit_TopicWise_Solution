int n,m;
vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

bool dfs(int ind,int i,int j,vector<string>& A,string B){
    if(i<0||i>=n||j<0||j>=m) return false;
    if(B[ind] != A[i][j]) return false;
    if(ind == B.length()-1 && A[i][j] == B[ind]) return true;
    bool ans = false;
    for(auto ele:dir){
        int x = i+ele[0];
        int y = j+ele[1];
        ans|=dfs(ind+1,x,y,A,B);
    }
    return ans;
}

int Solution::exist(vector<string> &A, string B) {
    n = A.size();
    m=A[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == B[0] && dfs(0,i,j,A,B)) return true; 
        }
    }
    return false;
}