#include <stdio.h>
#include <stdlib.h>

// Stack
typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) { return stack->top == stack->capacity - 1; }

int isEmpty(Stack* stack) { return stack->top == -1; }

void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }
    Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void deleteNode(Node **head_ref, int key) {
    Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// BST
typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* newBSTNode(int item) {
    BSTNode* temp = (BSTNode*) malloc(sizeof(BSTNode));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

BSTNode* insert(BSTNode* node, int data) {
    if (node == NULL) return newBSTNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

BSTNode* minValueNode(BSTNode* node) {
    BSTNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

BSTNode* deleteNodeBST(BSTNode* root, int data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNodeBST(root->left, data);
    else if (data > root->data)
        root->right = deleteNodeBST(root->right, data);
    else {
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        BSTNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNodeBST(root->right, temp->data);
    }
    return root;
}

int main() {
    int choice, data;
    Stack* stack = createStack(100);
    Node* head = NULL;
    BSTNode* root = NULL;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Insert into Linked List\n");
        printf("4. Delete from Linked List\n");
        printf("5. Insert into BST\n");
        printf("6. Delete from BST\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        int result = scanf("%d", &choice);
        if(result != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Niepoprawny wybor\n");
            continue;
        }

        switch(choice) {
            case 1:
                printf("Enter data to push into Stack: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                data = pop(stack);
                if(data == INT_MIN) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Popped %d from Stack.\n", data);
                }
                break;
            case 3:
                printf("Enter data to insert into Linked List: ");
                scanf("%d", &data);
                if(head == NULL) {
                    head = newNode(data);
                } else {
                    insertAfter(head, data);
                }
                break;
            case 4:
                printf("Enter data to delete from Linked List: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 5:
                printf("Enter data to insert into BST: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 6:
                printf("Enter data to delete from BST: ");
                scanf("%d", &data);
                root = deleteNodeBST(root, data);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}