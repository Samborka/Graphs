#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class PropriedadesDoGrafo {
public:
    PropriedadesDoGrafo(vector<vector<int>>& G) : graph(G) {
        V = G.size();
    }

    int diametro() {
        int maxExcentricidade = 0;
        for (int v = 0; v < V; ++v) {
            maxExcentricidade = max(maxExcentricidade, getMaxExcentricidade(v));
        }
        return maxExcentricidade;
    }

    int raio() {
        int minExcentricidade = INT_MAX;
        for (int v = 0; v < V; ++v) {
            minExcentricidade = min(minExcentricidade, getMaxExcentricidade(v));
        }
        return minExcentricidade;
    }

    vector<int> centro() {
        int raioGrafo = raio();
        vector<int> centros;
        for (int v = 0; v < V; ++v) {
            if (getMaxExcentricidade(v) == raioGrafo) {
                centros.push_back(v);
            }
        }
        return centros;
    }

private:
    vector<vector<int>>& graph;
    int V;

    int getMaxExcentricidade(int s) {
        vector<bool> visited(V, false);
        vector<int> excentricidade(V, -1);
        queue<int> q;

        visited[s] = true;
        excentricidade[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    excentricidade[v] = excentricidade[u] + 1;
                    q.push(v);
                }
            }
        }

        int maxExcentricidade = 0;
        for (int e : excentricidade) {
            maxExcentricidade = max(maxExcentricidade, e);
        }
        return maxExcentricidade;
    }
};

int main() {
    // Definindo um grafo com 10 vértices e 15 arestas
    vector<vector<int>> grafo = {
        {1, 2},
        {0, 3, 4},
        {0, 5, 6},
        {1, 7},
        {1, 8},
        {2},
        {2, 9},
        {3},
        {4},
        {6}
    };

    PropriedadesDoGrafo propriedades(grafo);
    cout << "Diâmetro: " << propriedades.diametro() << endl;
    cout << "Raio: " << propriedades.raio() << endl;

    cout << "Centro(s): ";
    vector<int> centros = propriedades.centro();
    for (int centro : centros) {
        cout << centro << " ";
    }
    cout << endl;

    return 0;
}