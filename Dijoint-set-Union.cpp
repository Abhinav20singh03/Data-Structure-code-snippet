class DSU{
    vector<int>size,parent;
    public:
       DSU(int n){
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
       }
       int findupar(int node){
        if(node==parent[node])return node;
        return parent[node]=findupar(parent[node]);
       }
       void unionbysize(int u,int v){
        int ul_u=findupar(u);
        int ul_v=findupar(v);
        if(ul_u==ul_v)return;
        if(size[ul_u]<size[ul_v]){
            parent[ul_u]=ul_v;
            size[ul_v]+=size[ul_u];
        }else{
            parent[ul_v]=ul_u;
            size[ul_u]+=size[ul_v];
        }
       }
};