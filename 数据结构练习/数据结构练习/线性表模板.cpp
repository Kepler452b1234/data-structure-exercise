#include <stdio.h>
#include <stdlib.h>
#include"���Ա�ģ��.h"




//��ʼ��˳���
void InitList(SeqList& L, int InitSize, int Maxsize) {

	//ʹ��malloc��������һƬ�����Ĵ洢�ռ�
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.length = InitSize;
	L.MaxSize = Maxsize;

}

//���Ӷ�̬����ĳ���
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

//����Ԫ�ص�����
bool ListInsert(SeqList& L, int i, int e) {
	//�ж�i�ķ�Χ�Ƿ���Ч,��Ϊ����Ҫ����
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



//ɾ��˳���б��ĳ��Ԫ��
bool ListDelete(SeqList& L, int i, int& e) {
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}