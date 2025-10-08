#include "Graph.h"


void Graph::addVertex(const std::string &name) {
    vertices.push_back(name);
    adjList.push_back(std::list<std::pair<int,int>>());
}

int Graph::getVertexIndex(const std::string &name) const {
    for (size_t i = 0; i < vertices.size(); i++)
        if (vertices[i] == name) return i;
    return -1; // not found
}

void Graph::addEdge(const std::string &from, const std::string &to, int weight) {
    int u = getVertexIndex(from);
    int v = getVertexIndex(to);

    if (u == -1 || v == -1) {
        std::cout << "Error: One or both vertices not found.\n";
        return;
    }

    // Insert in sorted order by weight
    auto &edges = adjList[u];
    auto it = edges.begin();
    while (it != edges.end() && it->second < weight)
        ++it;
    edges.insert(it, {v, weight});

    // For undirected graph, also add reverse edge:
    auto &revEdges = adjList[v];
    it = revEdges.begin();
    while (it != revEdges.end() && it->second < weight)
         ++it;
    revEdges.insert(it, {u, weight});
}
// For printing vertices 
 void Graph::printVertices() const {
     std::cout << "Vertices:\n";
     for (const auto &v : vertices) std::cout << "- " << v << "\n";
 }

void Graph::printGraph() const {
    std::cout << "Graph adjacency list:\n";
    for (size_t i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << ": ";
        for (auto &edge : adjList[i])
            std::cout << "(" << vertices[edge.first] << ", weight=" << edge.second << ") ";
        std::cout << "\n";
    }
}

// DFS helper
void Graph::DFSUtil(int v, std::vector<bool> &visited) const {
    visited[v] = true;
    std::cout << vertices[v] << " -";

    for (auto &neighbor : adjList[v])
        if (!visited[neighbor.first])
            DFSUtil(neighbor.first, visited);
}

void Graph::DFS() {
    printVertices();
    std::cout << "Enter starting vertex: DFS ";
    std::string startName;
    std::cin >> startName;

    int start = getVertexIndex(startName);
    if (start == -1) {
        std::cout << "Vertex not found.\n";
        return;
    }

    std::vector<bool> visited(vertices.size(), false);
    std::cout << "DFS Traversal: ";
    DFSUtil(start, visited);
    std::cout << "\n";
}

void Graph::BFS() {
    printVertices();
    std::cout << "Enter starting vertex: BFS ";
    std::string startName;
    std::cin >> startName;

    int start = getVertexIndex(startName);
    if (start == -1) {
        std::cout << "Vertex not found.\n";
        return;
    }

    std::vector<bool> visited(vertices.size(), false);
    std::queue<int> q;
    visited[start] = true;
    q.push(start);

    std::cout << "BFS Traversal: ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        std::cout << vertices[v] << " ";

        for (auto &neighbor : adjList[v]) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                q.push(neighbor.first);
            }
        }
    }
    std::cout << "\n";
}
