#include <stdio.h>
#include <string>
using namespace std;

struct Node
{
    Node *left = nullptr;
    Node *right = nullptr;

    int index = 0;
};

int N, T;
const int MAX_N = 1e7;
Node *nodes[MAX_N];

void print_bin_tree(Node *node, string prefix = "", bool isLeft = false)
{
    if (node)
    {
        printf("%s", prefix.c_str());
        printf(isLeft ? "├──" : "└──");
        printf("%i\n", node->index);

        prefix += ( isLeft ? "│   " : "    " );

        print_bin_tree(node->left, prefix, true);
        print_bin_tree(node->right, prefix);
    }
}

void invert_bin_tree()
{
    for (int i = 0; i < N; i++)
    {
        swap(nodes[i]->left, nodes[i]->right);
    }
}

int main()
{
    scanf("%i %i", &N, &T);

    for (int i = 0; i < T; i++)
    {
        nodes[i] = new Node();
        nodes[i]->index = i;
    }

    for (int i = 0; i < N; i++)
    {
        int node_i, left_i, right_i;
        scanf("%i %i %i", &node_i, &left_i, &right_i);

        nodes[node_i]->left = nodes[left_i];
        nodes[node_i]->right = nodes[right_i];
    }

    printf("normal:\n");
    print_bin_tree(nodes[0]);
    printf("\n");

    invert_bin_tree();

    printf("inverted:\n");
    print_bin_tree(nodes[0]);
    printf("\n");
}