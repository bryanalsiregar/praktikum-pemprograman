#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void DFS(int u, vector<bool> &visited, const vector<vector<int>> &adj) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, visited, adj);
        }
    }
}

void BFS(int u, vector<bool> &visited, const vector<vector<int>> &adj) {
    queue<int> q;
    visited[u] = true;
    q.push(u);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int v : adj[node]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void addEdgeMatrix(vector<vector<int>> &adj, int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; 
}

void displayMatrix(const vector<vector<int>> &adj) {
    for (int i = 0; i < adj.size(); i++) {
    for (int j = 0; j < adj[i].size(); j++) {
        cout << adj[i][j] << " ";
    }
    cout << endl;
    }
}

void addEdgeList(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void displayList(const vector<vector<int>> &adj) {
    for (int i = 0; i < adj.size(); i++) {
    cout << i << ": ";
    for (int j : adj[i]) cout << j << " ";
    cout << '\n';
    }
}
   

int main() {
    int n = 4; // jumlah vertex
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0)); // inisialisasi matriks
    // menambahkan edge satu per satu
    addEdgeMatrix(adjMatrix, 0, 1);
    addEdgeMatrix(adjMatrix, 0, 2);
    addEdgeMatrix(adjMatrix, 1, 2);
    addEdgeMatrix(adjMatrix, 2, 3);

    cout << "Adjacency Matrix:\n";
    displayMatrix(adjMatrix);

    n = 4; // jumlah vertex
    vector<vector<int>> adjList(n); // inisialisasi list
    // menambahkan edge satu per satu
    addEdgeList(adjList, 0, 1);
    addEdgeList(adjList, 0, 2);
    addEdgeList(adjList, 1, 2);
    addEdgeList(adjList, 2, 3);

    cout << "Adjacency List:\n";
    displayList(adjList);
   
    return 0;
}