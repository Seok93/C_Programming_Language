#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode *MakeBTreeNode(void)
{
    BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;

    return nd;
}
BTData GetData(BTreeNode *bt)
{
    return bt->data;
}

void SetData(BTreeNode *bt, BTData data)
{
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
    return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
    if (main->left != NULL)
        DeleteTree(main->left); // 해당 노드의 아래에 있는 노드까지 전부 삭제하지 않으면 메모리 누수가 일어난다.

    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    if (main->right != NULL)
        DeleteTree(main->right);

    main->right = sub;
}

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{ // 전위 선회 함수
    if (bt == NULL)
        return;

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{ // 중위 선회 함수
    if (bt == NULL)
        return;

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{ // 후위 선회 함수
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

void DeleteTree(BTreeNode *bt)
{
    if (bt == NULL)
        return;

    DeleteTree(bt->left);
    DeleteTree(bt->right);
    free(bt);
}
