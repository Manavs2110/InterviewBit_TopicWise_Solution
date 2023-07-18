int ans;
void dfs(vector<int>& A, vector<int> adj[],int C,int sum,int node,int parent){
    sum = sum+A[node-1];
    if(sum>C) return ;
    int child = 0;
    for(auto ele:adj[node]){
        if(ele == parent) continue;
        child++;
        dfs(A,adj,C,sum,ele,node);
    }
    if(!child) ans++;
    sum-=A[node-1];
}


int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();
    ans = 0;
    vector<int> adj[n+1];
    for(auto ele:B){
        adj[ele[0]].push_back(ele[1]);
        adj[ele[1]].push_back(ele[0]);
    }
    dfs(A,adj,C,0,1,-1);
    return ans;
}
