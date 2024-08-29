//Componentes Conexos
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph{
private:    
    int v;
    vector<int>* adj;
    
    void dfs(int u, vector<bool> &visited, vector<int> &conn){
        visited[u] = true;
        conn.push_back(u);

        int n = adj[u].size();
        for(int i = 0; i < n; i++){
            int v = adj[u][i];

            if(!visited[v]){
                dfs(v, visited, conn);
            }
        }
    }
    
public:
    Graph(int _v){
        v = _v;
        adj = new vector<int>[_v];
    }

    ~Graph(){
        delete[] adj;
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void connectedComponents(){
        vector<bool> visited(v, false);
        int connected = 0;

        for(int i = 0; i < v; i++){
            if(!visited[i]){
                vector<int> conn;
                dfs(i, visited, conn);

                sort(conn.begin(), conn.end());

                int n = conn.size();
                for(int j = 0; j < n; j++){
                    cout << char(conn[j] + 97) << ",";
                }
                connected++;
                cout << endl;
            }
        }
        cout << connected << " connected components" << endl;
    }

    void sortAdj(){
        for(int i = 0; i < v; i++){
            sort(adj[i].begin(), adj[i].end());
        }
    }
};

int main(){
    int n, v, e;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v >>  e;
        
        Graph *g = new Graph(v);

        char u, v;
        for(int j = 0; j < e; j++){
            cin >> u >> v;

            int _u = (int)u - 97;
            int _v = (int)v - 97;

            g->addEdge(_u, _v);
        }
        
        cout << "Case #"<< i + 1 <<":" << endl;
        g->connectedComponents();
        cout << endl;
    
        delete g;
    }
}