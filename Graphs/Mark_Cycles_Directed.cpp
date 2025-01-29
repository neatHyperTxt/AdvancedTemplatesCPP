vector<int>vis(n,false),pathVis(n,false),cycle(n,false);
            auto f = [&](int node,auto &&self)->bool{
                vis[node] = true;
                pathVis[node] = true;
                for(auto i:adj[node]){
                    if(!vis[i]){
                        bool x = self(i,self);
                        return cycle[i] = true;
                    }
                    else if(pathVis[i]){
                        return cycle[i] = true;
                    }
                }
                pathVis[node] = false;
                return false;
            };
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    f(i,f);
                }
            }
