struct dsu {
    // for using this :=> dsu d(n+1);
    vector<int> e;
    dsu(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

class DSU{
    vector<int>size,parent;
public:
    DSU(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }

    int find(int node){
        if(node==parent[node])return node;
        return parent[node]=find(parent[node]);
    }

    void join(int u,int v){
        int parentU=find(u);
        int parentV=find(v);

        if(parentU==parentV)return;
        if(size[u]>size[v])swap(u,v);

        parent[parentU]=parentV;
        size[parentV]+=size[parentU];
    }
    int Size(int node){
        return size[find(node)];
    }

    bool sameSet(int u,int v){
        return find(u)==find(v);
    }

};

