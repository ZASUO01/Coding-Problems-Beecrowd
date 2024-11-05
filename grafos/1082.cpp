//Componentes Conexos
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph{
private:    
    int v;
    vector<int> *adj;

    void dfs(int u, vector<bool> &visited, vector<int> &conn);

public:
    Graph(int _v);
    ~Graph();
    void addEdge(int u, int v);
    void printConnectedComponents();
};

//Graph constructor. Initialize adjacency list
Graph::Graph(int _v){
    v = _v;
    adj = new vector<int>[_v];
}

//Graph destructor. Free adjacency list
Graph::~Graph(){
    delete[] adj;
}

//Add undirected edge to the graph
void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//DFS starting from a vertex u to get the connected components of the undirected graph
void Graph::dfs(int u, vector<bool> &visited, vector<int> &conn){
    //mark the vertex as visited and add it to the component
    visited[u] = true;
    conn.push_back(u);

    //iterate through adjacency list
    int n = adj[u].size();
    for(int i = 0; i < n; i++){
        int v = adj[u][i];
        
        //if neighbour is not visited yet then call DFS from it
        if(!visited[v]){
            dfs(v, visited, conn);
        }
    }
}

//It prints each of connected componnets of the undirected graph
void Graph::printConnectedComponents(){
    vector<bool> visited(v, false);
    int connected = 0;

    //iterate through all graph vertices
    for(int i = 0; i < v; i++){
        
        //if the vertex is not visited yet then it belongs to a new component
        if(!visited[i]){
            
            //DFS to get the connected component
            vector<int> conn;
            dfs(i, visited, conn);

            //output vector sorted and printed
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
        g->printConnectedComponents();
        cout << endl;
    
        delete g;
    }
}