#include "Graph.h"

int main() {
    Graph g;

    // Add vertices
    g.addVertex("Cardassian Union");
    g.addVertex("Romulan Empire");
    g.addVertex("Borg");
    g.addVertex("United Federation of Planets");
    g.addVertex("Klingon Empire");
    g.addVertex("Bajoran");
    g.addVertex("Tholian Assembly");


    // Add edges with weights
    g.addEdge("Cardassian Union", "Romulan Empire", 42);
    g.addEdge("Cardassian Union", "Bajoran", 14);
    g.addEdge("Romulan Empire", "United Federation of Planets", 53);
    g.addEdge("Romulan Empire", "Borg", 33);
    g.addEdge("United Federation of Planets","Klingon Empire",87);
    g.addEdge("United Federation of Planets","Bajoran",22);
    g.addEdge("Bajoran","Tholian Assembly",80);
    g.addEdge("Tholian Assembly","Borg",10);
    g.addEdge("Klingon Empire","Borg",41);


    //g.printGraph();

    g.DFS();
    g.BFS();

    return 0;
}
