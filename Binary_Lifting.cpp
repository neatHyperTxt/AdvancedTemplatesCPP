class TreeAncestor {
    vector<vector<int>> up; // int up[N][20];
    int LOG = 20;
public:
    TreeAncestor(int n, vector<int>& parent) {
        up = vector<vector<int>>(n, vector<int>(LOG,-1));
        // up[v][j] is 2^j -th ancestor of node v
        for(int i = 0 ; i < n ; i++) up[i][0] = parent[i];
        for(int j = 1 ; j < LOG ; j++){
            for(int i = 0 ; i < n ; i++){
                if(up[i][j-1]!=-1)
                up[i][j] = up[up[i][j-1]][j-1];
            } 
        }
    }
    int getKthAncestor(int node, int k) {
        for(int j = 0 ; j < LOG ; j++) {
            if( (1<<j) & k){
                node = up[node][j];
                if(node==-1)return -1;
            }
        }
        return node;
    }
};
