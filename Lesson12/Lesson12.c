#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define true 1 == 1
#define false 1 != 1
typedef int boolean;


//  1.) Написать функцию проверяющую является ли переданное в неё бинарное дерево сбалансированным
//  bool isBalanced(BinTreeIntNode *root).
//  Входные параметры: указатель на вершину дерева
//  Выходные параметры: Bool. True, если сбалансированно; False, если несбалансированно
typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
} TreeIntNode;

TreeIntNode* treeInsert(TreeIntNode* t, int data){
    TreeIntNode* new = (TreeIntNode*) malloc(sizeof (TreeIntNode));
    new->key = data;
    new->left = NULL;
    new->right = NULL;
    TreeIntNode* current = t;
    TreeIntNode* parent = t;

    if(t == NULL){
        t = new;

        return t;
    }
    else{
        while (current->key != data){
            parent = current;

            if(current->key > data){
                current = current->left;
                if(current == NULL){
                    parent->left = new;

                    return t;
                }
            }
            else{
                current = current->right;
                if(current == NULL){
                    parent->right = new;

                    return t;
                }
            }
        }
    }

    return t;
}

void printTree(TreeIntNode* root){
    if(root){
        printf("%d", root->key);

        if(root->left || root->right){
            printf("(");

            if(root->left){
                printTree(root->left);
            }
            else{
                printf("NULL");
            }

            printf(",");

            if(root->right){
                printTree(root->right);
            }
            else{
                printf("NULL");
            }

            printf(")");
        }
    }
}

int checkTreeHeight(TreeIntNode* root){
    if(root == NULL){
        return 0;
    }

    int leftChildHeight = checkTreeHeight(root->left);
    if(leftChildHeight == -1){
        return -1;
    }

    int rightChildHeight = checkTreeHeight(root->right);
    if(rightChildHeight == -1){
        return -1;
    }

    int heightDifference = leftChildHeight - rightChildHeight;

    if(heightDifference < 0){
        heightDifference *= -1;
    }

    if(heightDifference > 1){
        return -1;
    }
    else{
        if(leftChildHeight > rightChildHeight){
            return leftChildHeight + 1;
        }
        else{
            return  rightChildHeight + 1;
        }
    }
}

boolean isBalancedIntTree(TreeIntNode* t){
    if(checkTreeHeight(t) == -1){
        return false;
    }
    else{
        return true;
    }
}

TreeIntNode* balancedTree(int n){
    TreeIntNode* new;
    int x;
    int nL;
    int nR;

    if(n == 0){
        return NULL;
    }
    else{
        x = rand() % 100;
        nL = n / 2;
        nR = n - nL - 1;
        new = (TreeIntNode*) malloc(sizeof (TreeIntNode));
        new->key = x;
        new->left = balancedTree(nL);
        new->right = balancedTree(nR);
    }

    return new;
}

void taskOne(){
    int amount = 6;
    int border = 100;

    TreeIntNode* tree = NULL;
    tree = treeInsert(tree, rand() % border);
    while(amount != 0){
        amount--;
        treeInsert(tree, rand() % border);
    }
    printTree(tree);
    printf("\n");
    printf("Your tree is %s \n", (isBalancedIntTree(tree) ? "true" : "false"));

    TreeIntNode* balanceTree = NULL;

    amount = 7;
    balanceTree = balancedTree(amount);
    printTree(balanceTree);
    printf("\n");
    printf("Your tree is %s \n", (isBalancedIntTree(balanceTree) ? "true" : "false"));
}


//  2.) Написать программу, которая:
//  2.a) Создаст [50] бинарных деревьев по [10000] узлов и заполнит узлы случайными целочисленными значениями;
//  2.b) Используя функцию из п.1 рассчитает, какой процент из созданных деревьев является сбалансированными.
void fillArrTreeInt(TreeIntNode** arr, int sizeArr, int sizeTree){
    for(int i = 0; i < sizeArr; ++i){
        TreeIntNode* new = NULL;
        new = treeInsert(new, rand() % 100000);
        for(int j = 1; j < sizeTree - 1; ++j){
            treeInsert(new, rand() % 100000);
        }

        arr[i] = new;
    }
}

void printArrTreeInt(TreeIntNode** arr, int sizeArr){
    for(int i = 0; i < sizeArr; i++){
        printf("Tree #%d: ", i);
        printTree(arr[i]);
        printf("\n");
    }
}

void percentTreeBalanced(TreeIntNode** arr, int sizeArr){
    int count = 0;

    for(int i = 0; i < sizeArr; ++i){
        if(isBalancedIntTree(arr[i])){
            count++;
        }
    }

    printf("In your array percent of balanced tree: %d%%", (count * 100) / sizeArr);
}

void taskTwo(){
    int amountTree = 50;
    int amountNodes = 10000;
    TreeIntNode* arr[amountTree];
    fillArrTreeInt(arr, amountTree, amountNodes);
    //printArrTreeInt(arr, amountTree);
    percentTreeBalanced(arr, amountTree);
    printf("\n");
}

// 3.) Написать рекурсивную функцию бинарного поиска значения в дереве хранящемся в узлах, а не в массиве.
// BinTreeIntNode* searchNode(BinTreeIntNode *root, int data).
// Входные параметры: указатель на вершину дерева; data - значение, которое нужно найти.
// Выходные параметры: Указатель на вершину дерева в которой содержится значение равное data или NULL
// если такая вершина не обнаружена
void printNode(TreeIntNode* root){
    if(root == NULL){
        printf("Root->key search: NULL\n");
    }
    else{
        printf("Root->key search: %d\n", root->key);
    }
}

TreeIntNode* binSearch(TreeIntNode* root, int data){
    if(root == NULL){
        return NULL;
    }
    if(root->key == data){
        return root;
    }

    TreeIntNode* current = root;
    if(current->key > data){
        current = current->left;
        binSearch(current, data);
    }
    else{
        current = current->right;
        binSearch(current, data);
    }
}

void taskThree(){
    TreeIntNode* binTree = NULL;
    binTree = treeInsert(binTree, 45);
    treeInsert(binTree, 16);
    treeInsert(binTree, 36);
    treeInsert(binTree, 98);
    treeInsert(binTree, 13);
    treeInsert(binTree, 54);
    treeInsert(binTree, 75);
    treeInsert(binTree, 6);
    treeInsert(binTree, 87);
    treeInsert(binTree, 3);

    printTree(binTree);
    printf("\n");

    printNode(binSearch(binTree, 16));
}

int main(const int argc, const char** argv){
    srand(time(NULL));
    taskOne();
    taskTwo();
    taskThree();

    return 0;
}