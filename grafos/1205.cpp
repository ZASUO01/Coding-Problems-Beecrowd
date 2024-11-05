//Cerco a Leningrado
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

#define INF 0x3f3f3f3f

class Graph{
private:
    int v;
    vector<pair<int, int>> *adj;

public:
    Graph(int _v);
    ~Graph();
    void addEdge(int u, int v);
    void setStarter(int starter);
    void setWeights(vector<int> & weights);
    vector<int> getShortestPaths();
};

//Graph constructor. Initialize adjacency list
Graph::Graph(int _v){
    v = _v;
    adj = new vector<pair<int, int>>[_v + 1];
}

//Graph destructor. Free adjacency list
Graph::~Graph(){
    delete[] adj;
}

//Add undirected edge to the graph
void Graph::addEdge(int u, int v){
    adj[u].push_back({v, 0});
    adj[v].push_back({u, 0});
}

//Set the starter vertice and link it to the vertice 0
void Graph::setStarter(int starter){
    adj[0].push_back({starter, 0});
}

//Set the weights of the edges using a given weight array
void Graph::setWeights(vector<int> &weights){
    for(int i = 0; i <= v; i++){
        int size = adj[i].size();
        for(int j = 0; j < size; j++){
            int dest = adj[i][j].first;
            adj[i][j].second = weights[dest];
        }
    }
}

//it returns the shortest path from a source to all the other destinations (Dijkstra)
vector<int> Graph::getShortestPaths(){
    //Create a priority queue of vertices
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //create the distances vector
    vector<int> dist(v + 1, INF);


    //insert the first vertice and initialize its distance as 0
    pq.push({0, 0});
    dist[0] = 0;

    while(!pq.empty()){
        //get the vertice with lower weight
        int u = pq.top().second;
        pq.pop();

        //iterate through edges of the current vertice
        for(auto &edge : adj[u]){
            int v = edge.first;
            int vWeight = edge.second;

            //if a short path is found then update it
            if(dist[v] > dist[u] + vWeight){
                dist[v] = dist[u] + vWeight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main(){
    int n, m, k, a, start, destiny;
    double p;

    while(cin >> n >> m >> k >> p){
        Graph *g = new Graph(n);

        int u, v;
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            g->addEdge(u, v);
        }

        cin >> a;
        vector<int> weights(n + 1, 0);

        int soldierPos;
        for(int i = 0; i < a; i++){
            cin >> soldierPos;
            weights[soldierPos]++;
        }

        cin >> start >> destiny;
        g->setStarter(start);
        g->setWeights(weights);

        vector<int> dists = g->getShortestPaths();

        int soldiersNum = dists[destiny]; 
        double prob;

        if(soldiersNum > k){
            prob = 0.000;
        }else{
            prob = pow(p, soldiersNum);
        }

        printf("%.3f\n", prob);

        delete g;
    }

    return  0;
}