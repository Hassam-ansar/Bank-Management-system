#include "BankGraph.h"

BankGraph::BankGraph() {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adjMatrix[i][j] = 0;

    // Weights representing distances in KM
    adjMatrix[0][1] = 160; // Rawalpindi to Gujrat
    adjMatrix[1][3] = 50;  // Gujrat to Gujranwala
    adjMatrix[3][4] = 95;  // Gujranwala to Lahore
    adjMatrix[4][5] = 180; // Lahore to Faisalabad
    adjMatrix[4][6] = 170; // Lahore to Sahiwal
    adjMatrix[2][5] = 100; // Sargodha to Faisalabad
    adjMatrix[5][7] = 240; // Faisalabad to Multan
    adjMatrix[6][7] = 170; // Sahiwal to Multan
    adjMatrix[7][8] = 100; // Multan to Bahawalpur
    adjMatrix[7][9] = 95;  // Multan to DG Khan

    // Symmetric matrix for undirected graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (adjMatrix[i][j] > 0) adjMatrix[j][i] = adjMatrix[i][j];
}

void BankGraph::displayDivisions() {
    for (int i = 0; i < V; i++) cout << i + 1 << ". " << divisions[i] << endl;
}

string BankGraph::getCityName(int index) {
    if (index >= 0 && index < V) return divisions[index];
    return "Unknown";
}

int BankGraph::getCityIndex(string cityName) {
    for (int i = 0; i < V; i++) if (divisions[i] == cityName) return i;
    return -1;
}

void BankGraph::findShortestPath(string startCity, string endCity) {
    int src = getCityIndex(startCity);
    int dest = getCityIndex(endCity);

    if (src == -1 || dest == -1) {
        cout << "Invalid branch names entered!" << endl;
        return;
    }

    int dist[V];
    bool visited[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] <= min) { min = dist[v]; u = v; }

        visited[u] = true;
        for (int v = 0; v < V; v++)
            if (!visited[v] && adjMatrix[u][v] && dist[u] != INT_MAX 
                && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
                parent[v] = u;
            }
    }

    cout << "\nShortest Path Distance: " << dist[dest] << " KM" << endl;
    cout << "Route: ";
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v]) path.push_back(v);
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << divisions[path[i]] << (i == 0 ? "" : " -> ");
    }
    cout << endl;
}

