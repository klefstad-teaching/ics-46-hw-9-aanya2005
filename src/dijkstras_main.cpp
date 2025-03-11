#include "dijkstras.h"

// struct Node {
//     int vertex, weight;
//     bool operator>(const Node& other) const { return weight > other.weight; }
// };

// vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
//     int n = G.numVertices;
//     vector<int> distance(n, INF);
//     previous.assign(n, -1);
//     priority_queue<Node, vector<Node>, greater<Node>> pq;
    
//     distance[source] = 0;
//     pq.push({source, 0});
    
//     while (!pq.empty()) {
//         Node current = pq.top();
//         pq.pop();
//         int u = current.vertex;
        
//         for (const Edge& neighbor : G[u]) {
//             int v = neighbor.dst;
//             int weight = neighbor.weight;
            
//             if (distance[u] + weight < distance[v]) {
//                 distance[v] = distance[u] + weight;
//                 previous[v] = u;
//                 pq.push({v, distance[v]});
//             }
//         }
//     }
//     return distance;
// }

// vector<int> extract_shortest_path(const vector<int>& previous, int destination) {
//     vector<int> path;
//     for (int v = destination; v != -1; v = previous[v]) {
//         path.push_back(v);
//     }
//     reverse(path.begin(), path.end());
//     return path;
// }

// void print_path(const vector<int>& path, int total) {
//     cout << "Shortest path: ";
//     for (size_t i = 0; i < path.size(); ++i) {
//         cout << path[i] << (i + 1 < path.size() ? " -> " : "\n");
//     }
//     cout << "Total distance: " << total << "\n";
// }

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
    // string filename = get_arg(argc, argv, "src/medium.txt");
    // string filename = get_arg(argc, argv, "src/large.txt");
    // string filename = get_arg(argc, argv, "src/largest.txt");
    Graph G;
    file_to_graph(filename, G);
    int source = 0, destination = G.numVertices - 1;  // Example: 0 to last vertex
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    vector<int> path = extract_shortest_path(distances, previous, destination);
    cout << "Shortest path from " << source << " to " << destination << ": ";
    print_path(path, distances[destination]);

    return 0;
}