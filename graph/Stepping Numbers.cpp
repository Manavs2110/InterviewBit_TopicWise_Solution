vector<int> Solution::stepnum(int A, int B) {
    vector<int> count;
    if(A==0) count.push_back(0);
    queue<int> q;
    for(int i=1;i<=9;i++){
        q.push(i);
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(t<=B){
            int k = t%10;
            if(k!=0) q.push(t*10+k-1);
            if(k!=9) q.push(t*10+k+1);
            
            if(t>=A) count.push_back(t);
        }
    }
    return count;
}
