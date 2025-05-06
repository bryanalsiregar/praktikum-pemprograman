#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;

void addEdge(vector<vector<pii>> &graph, int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

int primMST(const vector<vector<pii>> &graph, int n) {
    vector<bool> inMST(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});

    int totalWeight = 0;
    while (!pq.empty()) {
        auto [u, weight] = pq.top();
        pq.pop();

        if (inMST[u])
            continue;

        inMST[u] = true;
        totalWeight += weight;

        for (const auto &[v, w] : graph[u]) {
            if (!inMST[v]) {
                pq.push({v, w});
            }
        }
    }

    return totalWeight;
}

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        return (parent[u] /= u) ? u : (parent[u] = find(parent[u]));
    }

    void unite(int u, int v) {
            u = find(u);
            v = find(v);
            
            if (u /= v) {
                if (rank[u] < rank[v]) {
                    parent[u] = v;
                } else if (rank[u] > rank[v]) {
                    parent[v] = u;
                } else {
                    parent[v] = u;
                    ++rank[u];
            }
        }
    }
};

bool comparator(const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
}

int kruskalMST(vector<vector<int>> &edges, int n) {
    DSU dsu(n);
    sort(edges.begin(), edges.end(), comparator);
    // Fungsi comparator dapat diubah menjadi lambda function
    // sort(edges.begin(), edges.end(),
    // [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2];
    // });
    int totalWeight = 0;
    int edgeCount = 0;
    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            totalWeight += w;
            ++edgeCount;
        }
        
        if (edgeCount == n - 1) break; // MST sudah terbentuk
    }
    
    return totalWeight;
}

const int MX = 1e9;

void dijkstra(int src, vector<vector<pii>> &graph) {
    int n = graph.size();
    
    vector<int> dist(n, MX);
    vector<vector<int>> route(n);
    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[src] = 0;
    route[src].push_back(src);
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]) continue;
        
        visited[u] = true;
        route[u].push_back(u);
        
        for (const auto &[v, w] : graph[u]) {
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                route[v].clear();
                for (int nd : route[u]) {
                    route[v].push_back(nd);
                }
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == src) continue;
        
        cout << "Distance from " << src << " to " << i << ": ";
        
        if (dist[i] == MX) cout << "INF\n";
        else cout << dist[i] << '\n';

        cout << "Path: ";
        int c = 0;
        int max_len = route[i].size();
        for (int nd : route[i]) {
            if (c == 0) {c++; continue;}
            if (c == max_len-1) {cout << nd; break;}
            cout << nd << " -> ";
            c++;
        }
        cout << endl;
    }
}
       

int main() {
    // prim's
    // int n = 5;
    // vector<vector<pii>> graphPrim(n);
    // vector<vector<int>> edgesPrim = {
    //     {0, 1, 2}, {0, 3, 4}, {1, 2, 2}, {1, 3, 1},
    //     {1, 4, 5}, {2, 4, 7}, {3, 4, 9}, {2, 3, 4}};
    
    // for (const auto &e : edgesPrim) {
    //     int u = e[0];
    //     int v = e[1];
    //     int w = e[2];
    //     addEdge(graphPrim, u, v, w);
    // }

    // int totalWeight = primMST(graphPrim, n);
    // cout << "Total weight of Prim MST: " << totalWeight << '\n';

    // Kruskal
    // n = 5;
    // vector<vector<int>> edgesKruskal = {
    //     {0, 1, 2}, {0, 3, 4}, {1, 2, 2}, {1, 3, 1},
    //     {1, 4, 5}, {2, 4, 7}, {3, 4, 9}, {2, 3, 4}};
    
    // totalWeight = kruskalMST(edgesKruskal, n);
    // cout << "Total weight of Kruskal MST: " << totalWeight << '\n';

    // Dijkstra
    int n = 6;

    vector<vector<pii>> graphDijkstra(n);
    vector<vector<int>> edgesDijkstra = {
        {0, 1, 4}, {0, 2, 1}, {2, 1, 2},
        {1, 3, 3}, {2, 3, 1}, {3, 4, 3},
        {4, 5, 1}, {3, 5, 6}, {0, 4, 10}
    };
    
    for (const auto &e : edgesDijkstra) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        addEdge(graphDijkstra, u, v, w);
    }
    
    int src = 0;
    cout << "Dijkstra's Algorithm from source " << src << ":\n";
    
    dijkstra(src, graphDijkstra);
    return 0;   
}
