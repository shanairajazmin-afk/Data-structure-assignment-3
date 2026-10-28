#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* createNode(char value);
void inorder(struct Node *root);
void preorder(struct Node *root);
void postorder(struct Node *root);
void bfs(struct Node *root);

int main() {
    struct Node *A = createNode('A');
    struct Node *B = createNode('B');
    struct Node *C = createNode('C');
    struct Node *D = createNode('D');
    struct Node *E = createNode('E');
    struct Node *F = createNode('F');
    struct Node *G = createNode('G');
    struct Node *H = createNode('H');
    struct Node *I = createNode('I');

    A->left = B; A->right = C;
    B->left = D; B->right = E;
    C->left = F; C->right = G;
    G->left = H; G->right = I;

    // IN-ORDER: LEFT, ROOT, RIGHT
    printf("Inorder: ");
    inorder(A);

    // PRE-ORDER: ROOT, LEFT, RIGHT
    printf("\nPreorder: ");
    preorder(A);

    // POST-ORDER: LEFT, RIGHT, ROOT
    printf("\nPostorder: ");
    postorder(A);

    // BFS: LEVEL BY LEVEL
    printf("\nBFS: ");
    bfs(A);

    printf("\n");
    return 0;
}

struct Node* createNode(char value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) exit(1);

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// INORDER
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// PREORDER
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// POSTORDER
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

// BFS
void bfs(struct Node *root) {
    if (root == NULL) return;

    struct Node *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node *current = queue[front++];
        printf("%c ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}