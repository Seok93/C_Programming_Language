#include "UsefulHeap.h"

void HeapInit(Heap *ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap *ph)
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIdx(int idx)
{
    return idx / 2;
}

int GetLChildIdx(int idx)
{
    return idx * 2;
}

int GetRChildIdx(int idx)
{
    return GetLChildIdx(idx) + 1;
}

int GetHighPriChildIdx(Heap *ph, int idx)
{
    int LChildIdx = GetLChildIdx(idx);
    int RChildIdx = GetRChildIdx(idx);

    if (LChildIdx > ph->numOfData)
        return 0;
    else if (LChildIdx == ph->numOfData)
        return LChildIdx;
    else
    {
        if (ph->comp(ph->heapArr[LChildIdx], ph->heapArr[RChildIdx]) < 0)
            return RChildIdx;
        else
            return LChildIdx;
    }
}

void HInsert(Heap *ph, HData data)
{
    int idx = ph->numOfData + 1;

    while (idx != 1)
    {
        if (ph->comp(data, ph->heapArr[GetParentIdx(idx)]) > 0)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
            idx = GetParentIdx(idx);
        }
        else
        {
            break;
        }
    }

    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

HData HDelete(Heap *ph)
{
    HData retData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while (childIdx = GetHighPriChildIdx(ph, parentIdx))
    {
        if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;

        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}
