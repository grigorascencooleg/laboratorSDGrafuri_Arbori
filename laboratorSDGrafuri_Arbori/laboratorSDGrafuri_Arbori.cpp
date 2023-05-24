#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Graph {
    int numVertices;
    std::vector<std::vector<int>> adjacencyList; 

public:
    Graph(int vertices) : numVertices(vertices) {
        adjacencyList.resize(numVertices);
    }

    void addEdge(int source, int destination) {
        adjacencyList[source].push_back(destination);
        adjacencyList[destination].push_back(source);
    }

    void DFS(int startNode) {
        std::vector<bool> visited(numVertices, false);
        std::stack<int> stack;

        visited[startNode] = true; 
        stack.push(startNode); 

        while (!stack.empty()) {
            int currentNode = stack.top();
            stack.pop();

            std::cout << currentNode << " ";

            for (int neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
    }

    void BFS(int startNode) {
        std::vector<bool> visited(numVertices, false);
        std::queue<int> queue;

        visited[startNode] = true;
        queue.push(startNode);

        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();

            std::cout << currentNode << " ";

            for (int neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int numVertices = 7;
    Graph graph(numVertices);

    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, NULL);
    graph.addEdge(2, 3);
    graph.addEdge(3, NULL);
    graph.addEdge(3, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, NULL);
    graph.addEdge(4, 1);
    graph.addEdge(1, NULL);

    int startNode = 0;

    std::cout << "Parcurgerea in adancime (DFS): ";
    graph.DFS(startNode);
    std::cout << std::endl;

    std::cout << "Parcurgerea in latime (BFS): ";
    graph.BFS(startNode);
    std::cout << std::endl;

    return 0;
}
