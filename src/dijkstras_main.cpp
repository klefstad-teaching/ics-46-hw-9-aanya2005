#include "dijkstras.h"
// g++ -o dijkstra src/dijkstras_main.cpp src/dijkstras.cpp -std=c++20

// int main() {
//     Graph G;
//     file_to_graph("graph.txt", G);
    
//     int source = 0, destination = 4;
//     vector<int> previous;
//     vector<int> distances = dijkstra_shortest_path(G, source, previous);
    
//     vector<int> path = extract_shortest_path(previous, destination);
//     print_path(path, distances[destination]);
    
//     return 0;
// }

int main(int argc, char *argv[]) {
    string filename = (argc, argv, "src/small.txt");
    // string filename = (argc, argv, "src/medium.txt");
    // string filename = (argc, argv, "src/large.txt");
    // string filename = (argc, argv, "src/largest.txt");
    Graph G;
    file_to_graph(filename, G);
    int source = 0, destination = G.numVertices - 1;  // Example: 0 to last vertex
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    
    vector<int> path = extract_shortest_path(distances, previous, destination);
    print_path(path,distances[destination] );
    return 0;
}