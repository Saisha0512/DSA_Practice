/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* quadTree(vector<vector<int>> &grid, int a, int b, int n){
        // base case
        if (n == 1){
            return new Node(grid[a][b], true);
        }

        bool same = true;
        int val = grid[a][b];
        for (int i = a; i < a + n; i ++){
            for (int j = b; j < b + n; j ++){
                if (grid[i][j] != val){
                    same = false;
                    break;
                }
            }

            if (!same){
                break;
            }
        }

        if (same){
            Node *new_node = new Node(val, true);
            return new_node;
        }

        int mid = n / 2;
        int r1 = a, r2 = a + mid, c1 = b, c2 = b + mid;

        Node *new_node = new Node(grid[r1][c1], false);
        new_node -> topLeft = quadTree(grid, r1, c1, n / 2);
        new_node -> topRight = quadTree(grid, r1, c2, n / 2);
        new_node -> bottomLeft = quadTree(grid, r2, c1, n / 2);
        new_node -> bottomRight = quadTree(grid, r2, c2, n / 2);

        return new_node;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        
        return quadTree(grid, 0, 0, n);
    }
};