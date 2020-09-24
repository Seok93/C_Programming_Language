#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data);

int main()
{
    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();
    BTreeNode *bt5 = MakeBTreeNode();
    BTreeNode *bt6 = MakeBTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);

    MakeLeftSubTree(bt1, bt2);  // bt2를 bt1의 왼쪽 노드로
    MakeRightSubTree(bt1, bt3); // bt3를 bt1의 오른쪽 노드로
    MakeLeftSubTree(bt2, bt4);  // bt2를 bt4의 왼쪽 노드로
    MakeRightSubTree(bt2, bt5); // bt2를 bt5의 오른쪽 노드로
    MakeRightSubTree(bt3, bt6); // bt3를 bt6의 오른쪽 노드로

    PreorderTraverse(bt1, ShowIntData); // 전위 순회
    printf("\n");
    InorderTraverse(bt1, ShowIntData); // 중위 순회
    printf("\n");
    PostorderTraverse(bt1, ShowIntData); // 후위 순회
    printf("\n");

    return 0;
}

void ShowIntData(int data)
{
    printf("%d ", data);
}