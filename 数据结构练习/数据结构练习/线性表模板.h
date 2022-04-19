#ifndef _Table_H
#define _Table_H

typedef struct {
	int* data;
	int MaxSize;
	int length;

}SeqList;


void InitList(SeqList& L, int InitSize, int Maxsize);
void IncreaseSize(SeqList& L, int len);
bool ListInsert(SeqList& L, int i, int e);
bool ListDelete(SeqList& L, int i, int& e);


#endif // !_Table_H
