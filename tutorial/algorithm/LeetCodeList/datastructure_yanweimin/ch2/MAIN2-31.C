/* main2-31.c ����bo2-3.c��bo2-31.cpp�������� */
#include "../ch1/c1.h"
typedef int ElemType;
#include "c2-3.h"
#include "bo2-3.c" /* ���ַ��������õĺ����ڴ��ļ��� */
#include "bo2-31.c"

void visit(ElemType c)
{
	printf("%d ", c);
}

void main()
{
	int j, k;
	Status i;
	ElemType e, e0;
	SLinkList L;
	InitList(L);
	for (j = 1; j <= 5; j++)
		i = ListInsert(L, 1, j);
	printf("��L�ı�ͷ���β���1��5��L=");
	ListTraverse(L, visit);
	i = ListEmpty(L);
	printf("L�Ƿ��:i=%d(1:�� 0:��)��L�ĳ���=%d\n", i, ListLength(L));
	i = ClearList(L);
	printf("���L��L=");
	ListTraverse(L, visit);
	i = ListEmpty(L);
	printf("L�Ƿ��:i=%d(1:�� 0:��)��L�ĳ���=%d\n", i, ListLength(L));
	for (j = 1; j <= 10; j++)
		ListInsert(L, j, j);
	printf("��L�ı�β���β���1��10��L=");
	ListTraverse(L, visit);
	GetElem(L, 5, &e);
	printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
	for (j = 0; j <= 1; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("ֵΪ%d��Ԫ���ھ�̬�����е�λ��Ϊ%d\n", j, k);
		else
			printf("û��ֵΪ%d��Ԫ��\n", j);
	}
	for (j = 1; j <= 2; j++) /* ����ͷ�������� */
	{
		GetElem(L, j, &e0); /* �ѵ�j�����ݸ���e0 */
		i = PriorElem(L, e0, &e); /* ��e0��ǰ�� */
		if (!i)
			printf("Ԫ��%d��ǰ��\n", e0);
		else
			printf("Ԫ��%d��ǰ��Ϊ��%d\n", e0, e);
	}
	for (j = ListLength(L) - 1; j <= ListLength(L); j++) /* ����������� */
	{
		GetElem(L, j, &e0); /* �ѵ�j�����ݸ���e0 */
		i = NextElem(L, e0, &e); /* ��e0�ĺ�� */
		if (!i)
			printf("Ԫ��%d�޺��\n", e0);
		else
			printf("Ԫ��%d�ĺ��Ϊ��%d\n", e0, e);
	}
	k = ListLength(L); /* kΪ���� */
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(L, j, &e); /* ɾ����j������ */
		if (i)
			printf("ɾ����Ԫ��Ϊ��%d\n", e);
		else
			printf("ɾ����%d������ʧ��\n", j);
	}
	printf("�������L��Ԫ�أ�");
	ListTraverse(L, visit); /* ���ζ�Ԫ�ص���visit()�����Ԫ�ص�ֵ */
}