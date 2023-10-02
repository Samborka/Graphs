#include <iostream>
#include <vector>

using namespace std;

class PowerSystem {
public:
    PowerSystem(int E, int L) : numStations(E), numLines(L) {
        adj.assign(E, vector<int>());
        visited.assign(E, false);
    }

    void addConnection(int X, int Y) {
        adj[X - 1].push_back(Y - 1);
        adj[Y - 1].push_back(X - 1);
    }

    bool isNormal() {
        for (int i = 0; i < numStations; ++i) {
            for (int j = i + 1; j < numStations; ++j) {
                fill(visited.begin(), visited.end(), false);
                if (!dfs(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    int numStations;
    int numLines;
    vector<vector<int>> adj; // Lista de adjacência
    vector<bool> visited;

    bool dfs(int u, int target) {
        if (u == target) {
            return true;
        }

        visited[u] = true;

        for (int v : adj[u]) {
            if (!visited[v]) {
                if (dfs(v, target)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    int E, L;
    int caseNumber = 1;

    while (true) {
        cin >> E >> L;

        if (E == 0 && L == 0) {
            break;
        }

        PowerSystem system(E, L);

        for (int i = 0; i < L; ++i) {
            int X, Y;
            cin >> X >> Y;
            system.addConnection(X, Y);
        }

        cout << "Teste " << caseNumber << endl;
        cout << (system.isNormal() ? "normal" : "falha") << endl;
        cout << endl;
        caseNumber++;
    }

    return 0;
}
