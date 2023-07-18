int ans;
int dfs(int node,int parent,vector<int> adj[]){
    vector<int> length(2,0);
    for(auto ele:adj[node]){
        if(ele == parent) continue;
        length.push_back(dfs(ele,node,adj));
    }
    sort(length.rbegin(),length.rend());
    ans = max(ans,length[0]+length[1]);
    return length[0]+1;
}

int Solution::solve(vector<int> &A) {
    ans =0;
    int n = A.size();
    vector<int> adj[n+1];
    for(int i=0;i<A.size();i++){
        if(A[i]!=-1){
            adj[A[i]].push_back(i);
        }
    }
    dfs(0,-1,adj);
    return ans;
}
