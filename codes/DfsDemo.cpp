#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int self;
    Node *left;
    Node *right;
};

const int TREE_SIZE = 9;
stack<Node *> unvisited;
Node nodes[TREE_SIZE];
Node *current;

int main()
{
    //初始化樹
    for (int i = 0; i < TREE_SIZE; i++) {
        // 本节点的值
        nodes[i].self = i;

        // 左子树
        int child = i * 2 + 1;
        if (child < TREE_SIZE) {
            nodes[i].left = &nodes[child];
        } else {
            nodes[i].left = NULL;
        }
        
        // 右子树
        child++;
        if (child < TREE_SIZE) {
            nodes[i].right = &nodes[child];
        } else {
            nodes[i].right = NULL;
        }
    }

    unvisited.push(&nodes[0]); //先把0放入UNVISITED stack

    // 樹的深度優先搜索在二叉樹的特例下，就是二叉樹的先序遍歷操作（這裡是使用循環實現)
    // 只有UNVISITED不空
    while (!unvisited.empty()) {
        current = (unvisited.top()); //當前應該訪問的
        unvisited.pop();

        // 注意：栈(stack)的特性，后进先出
        if (current->right != NULL) {
            unvisited.push(current->right );
        }

        if (current->left != NULL) {
            unvisited.push(current->left);
        }
        cout << current->self << endl;
    }

    return 0;
}