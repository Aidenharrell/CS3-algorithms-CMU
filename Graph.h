#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <algorithm>

class Graph{
private: 
    std::vector<std::string> vertices;
    std::vector<std::list<std::pair<int, int>>> adjList;

    void DFSUtil(int v, std::vector<bool> &visited) const;

    int getVertexIndex(const std::string &name) const;

public :
    Graph() = default;

    void addVertex(const std::string &name);
    void addEdge(const std::string &from, const std::string &to, int weight);

    void printVertices()const;
    void printGraph() const;

    void DFS();
    void BFS();
};
#endif
