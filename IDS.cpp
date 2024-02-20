#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Structure to represent a node in the tree
struct Node {
    int data;
    vector<Node*> children;

    Node(int val) : data(val) {}
};

// Depth-Limited Search (DLS) function
Node* dls(Node* root, int target, int depthLimit) {
    stack<pair<Node*, int>> s;
    s.push({root, 0});

    while (!s.empty()) {
        auto current = s.top().first;
        auto depth = s.top().second;
        s.pop();

        cout << "DLS - Visiting Node: " << current->data << " at Depth: " << depth << endl;

        if (current->data == target) {
            cout << "DLS - Target found!" << endl;
            return current;
        }

        // Explore children within depth limit
        if (depth < depthLimit) {
            // Push children to stack in reverse order
            for (int i = current->children.size() - 1; i >= 0; --i) {
                s.push({current->children[i], depth + 1});
            }
        }
    }

    cout << "DLS - Target not found within depth limit." << endl;
    return nullptr;
}

// Depth-First Search (DFS) function
Node* dfs(Node* root, int target) {
    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        auto current = s.top();
        s.pop();

        cout << "DFS - Visiting Node: " << current->data << endl;

        if (current->data == target) {
            cout << "DFS - Target found!" << endl;
            return current;
        }

        // Push children to stack in reverse order
        for (int i = current->children.size() - 1; i >= 0; --i) {
            s.push(current->children[i]);
        }
    }

    cout << "DFS - Target not found." << endl;
    return nullptr;
}

int main() {
    // Input number of nodes, tree structure, target node, and depth limit
    // ...

    // Create nodes and build the tree structure
    // ...

    // Perform Depth-Limited Search (DLS) and display results
    // ...

    // Perform Depth-First Search (DFS) and display results
    // ...

    // Clean up memory
    // ...

    return 0;
}
