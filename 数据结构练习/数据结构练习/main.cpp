#include <stdio.h>
#include <stdlib.h>
#include"线性表模板.h"





//综合应用题1
int Promblem1(SeqList& L)
{
	int LDataMin = L.data[0];
	int LDataMinPos = 1;

	if (L.length == 0)
	{
		printf("线性表为空\n");
		return 0;
	}
	else
	{
		
		for (int i = 0; i < L.length; i++)
		{
			if (LDataMin > L.data[i])
			{
				LDataMin = L.data[i];
				LDataMinPos = i + 1;
			}
		}
		ListDelete(L, LDataMinPos, LDataMin);
		ListInsert(L, LDataMinPos, L.data[L.length - 1]);

		return LDataMin;
	}
		
}

void Promblem2(SeqList& L)
{
	int t;
	for (int i = 0; i < L.length/2; i++)
	{
		t = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];
		L.data[L.length - 1-i]=t;

	}

}

void Promblem3(SeqList& L,int x) 
{
	int e = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == x)
		{
			ListDelete(L, x, e);
		}
	}

}


SeqList Problem7(SeqList L1, SeqList L2) {
	SeqList L3;
	L3.length = L1.length + L2.length;
	InitList(L3, L1.length + L2.length, L1.length + L2.length + 10);
	for (int i = 0; i < L1.length; i++)
	{

		L3.data[i] = L1.data[i];
	}
	for (int i = 0; i < L2.length; i++)
	{
		L3.data[L1.length + i] = L2.data[i];
	}

	return L3;
}




int main()
{
	//声明一个顺序表
	SeqList L;
	//初始化一个顺序表
	InitList(L, 10, 20);

	for (int i = 0; i <L.length; i=i+2)
	{
		L.data[i] =i+1;
		L.data[i + 1] = i + 1;
		printf("L.data[%d]=%d\n", i, L.data[i]);
	}

	Promblem3(L,4);
	


	for (int i = 0; i < L.length; i++)
	{
		printf("L.data[%d]=%d\n", i, L.data[i]);
	}

	printf("L.length=%d\n", L.length);

	

}


