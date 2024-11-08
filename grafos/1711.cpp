//Dona Minhoca
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f

//BFS in graph edges to get the minimum cycle lenght
int getMinCycleLenght(vector<vector<pair<int, int>>>& adj, int start) {
    // Inicializa a fila para BFS e um vetor de distâncias
    queue<pair<int, int>> q;  // (vértice atual, pai)
    q.push({start, -1});
    
    unordered_map<int, int> dist;  // Armazena as distâncias dos vértices
    dist[start] = 0;
    
    /*
    unordered_map<int, int> parent; // Para armazenar os pais dos vértices (para reconstruir o caminho)
    parent[start] = -1;
    */

    int minCycleLenght = INF;
    //vector<int> cycle;  // Para armazenar o ciclo mínimo encontrado
    
    while (!q.empty()) {
        int current = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        // Explora todos os vizinhos do vértice atual
        for (pair<int, int> &edge : adj[current]) {
            int neighbor = edge.first;
            int weight = edge.second;

            // Se o vizinho já foi visitado
            if (dist.find(neighbor) != dist.end()) {
                // Verifica se não é o pai do vértice atual (evita ciclos triviais)
                if (neighbor != parent) {
                    // Cálculo do comprimento do ciclo (soma dos pesos)
                    int cycleLenght = dist[current] + weight + dist[neighbor] - dist[start];
                    if (cycleLenght < minCycleLenght) {
                        minCycleLenght = cycleLenght;
                        
                        /*
                        // Reconstruir o ciclo mínimo
                        cycle.clear();
                        int v = current;
                        while (v != start) {
                            cycle.push_back(v);
                            v = parent[v];
                        }
                        cycle.push_back(start);
                        reverse(cycle.begin(), cycle.end());

                        v = neighbor;
                        while (v != current) {
                            cycle.push_back(v);
                            v = parent[v];
                        }
                        cycle.push_back(current);
                        */
                    }
                }
            }
            // Se o vizinho ainda não foi visitado
            else {
                dist[neighbor] = dist[current] + weight;
                //parent[neighbor] = current;
                q.push({neighbor, current});
            }
        }
    }

    return minCycleLenght;
}



int main(){
    int s, t, q;

    while(cin >> s >> t){
        vector<vector<pair<int, int>>> adj(s + 1, vector<pair<int, int>>());

        int a, b, c;
        for(int i = 0; i < t; i++){
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }

        cin >> q;

        int x, m;
        for(int i = 0; i < q; i++){
            cin >> x >> m;
            cout << getMinCycleLenght(adj, x) << "\n";
        }
    }

    return  0;
}