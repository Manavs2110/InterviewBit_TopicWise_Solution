bool dfs(vector<int> adj[],int node,int A,vector<int>& visit){
    visit[node]=1;
    if(node == A) return true;
    bool ans = false;
    for(auto ele:adj[node]){
        if(visit[ele]) continue;
        ans = ans|dfs(adj,ele,A,visit);
    }
    return ans;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A+1];
    for(auto ele:B){
        adj[ele[0]].push_back(ele[1]);
    }
    vector<int> visit(A+1,0);
    return dfs(adj,1,A,visit);
}
