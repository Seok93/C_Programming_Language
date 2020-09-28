#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;

BTreeNode *MakeBTreeNode(void);           // 노드 생성
BTData GetData(BTreeNode *bt);            // 노드에 저장된 데이터 반환
void SetData(BTreeNode *bt, BTData data); // 노드에 데이터 삽입

BTreeNode *GetLeftSubTree(BTreeNode *bt);  // 왼쪽 서브 트리 주소값 반환
BTreeNode *GetRightSubTree(BTreeNode *bt); // 오른쪽 서브 트리 주소값 반환

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);  // 왼쪽 서브트리 연결
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub); // 오른쪽 서브트리 연결

typedef void VisitFuncPtr(BTData data); // 함수포인터의 typedef 선언, 함수이름을 그대로 사용하면 된다.

void PreorderTraverse(BTreeNode *bt, void (*action)(BTdata)); // 전위 순회
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);     // 중위 순회
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);   // 후위 순회

void DeleteTree(BTreeNode *bt); // 노드 삭제

#endif