#include <stdio.h>
#include <stdlib.h>
#include"线性表模板.h"




//初始化顺序表
void InitList(SeqList& L, int InitSize, int Maxsize) {

	//使用malloc函数申请一片连续的存储空间
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.length = InitSize;
	L.MaxSize = Maxsize;

}

//增加动态数组的长度
void IncreaseSize(SeqList& L, int len)
{
	int* p = L.data;
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];

	}
	L.MaxSize = L.MaxSize + len;
	free(p);

}

//插入元素到数组
bool ListInsert(SeqList& L, int i, int e) {
	//判断i的范围是否有效,因为数据要连续
	if (i > L.length || i < 1)
		return false;
	if (i >= L.MaxSize)
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}



//删除顺序列表的某个元素
bool ListDelete(SeqList& L, int i, int& e) {
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}