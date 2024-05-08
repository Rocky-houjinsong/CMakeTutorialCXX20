/* main2-6.c ����bo2-6.cpp�������� */
#include "../ch1/c1.h"
typedef int ElemType;
#include "c2-5.h"
#include "bo2-6.c"
Status compare(ElemType c1, ElemType c2) /* c1����c2 */
{
	if (c1 == c2)
		return TRUE;
	else
		return FALSE;
}

int cmp(ElemType a, ElemType b)
{ /* ����a<��=��>b,�ֱ𷵻�-1��0��1 */
	if (a == b)
		return 0;
	else
		return (a - b) / abs(a - b);
}

void visit(ElemType c)
{
	printf("%d ", c);
}

void main()
{
	Link p, h;
	LinkList L;
	Status i;
	int j, k;
	i = InitList(&L);
	if (!i) /* ��ʼ���յ����Ա�L���ɹ� */
		exit(FALSE); /* �˳��������� */
	for (j = 1; j <= 2; j++)
	{
		MakeNode(&p, j); /* ������pָ��ֵΪj�Ľ�� */
		InsFirst(&L, L.tail, p); /* ���ڱ�β */
	}
	OrderInsert(&L, 0, cmp); /* ��������������ͷ */
	for (j = 0; j <= 3; j++)
	{
		i = LocateElemP(L, j, &p, cmp);
		if (i)
			printf("��������ֵΪ%d��Ԫ�ء�\n", p->data);
		else
			printf("������û��ֵΪ%d��Ԫ�ء�\n", j);
	}
	printf("���������");
	ListTraverse(L, visit); /* ���L */
	for (j = 1; j <= 4; j++)
	{
		printf("ɾ����ͷ��㣺");
		DelFirst(&L, L.head, &p); /* ɾ��L���׽�㣬����p���� */
		if (p)
			printf("%d\n", GetCurElem(p));
		else
			printf("���գ��޷�ɾ�� p=%u\n", p);
	}
	printf("L�н�����=%d L�Ƿ�� %d(1:�� 0:��)\n", ListLength(L), ListEmpty(L));
	MakeNode(&p, 10);
	p->next = NULL; /* β��� */
	for (j = 4; j >= 1; j--)
	{
		MakeNode(&h, j * 2);
		h->next = p;
		p = h;
	} /* hָ��һ��5����㣬��ֵ������2 4 6 8 10 */
	Append(&L, h); /* �ѽ��h��������������L�����һ�����֮�� */
	OrderInsert(&L, 12, cmp); /* ��������������βͷ */
	OrderInsert(&L, 7, cmp); /* ���������������м� */
	printf("���������");
	ListTraverse(L, visit); /* ���L */
	for (j = 1; j <= 2; j++)
	{
		p = LocateElem(L, j * 5, compare);
		if (p)
			printf("L�д���ֵΪ%d�Ľ�㡣\n", j * 5);
		else
			printf("L�в�����ֵΪ%d�Ľ�㡣\n", j * 5);
	}
	for (j = 1; j <= 2; j++)
	{
		LocatePos(L, j, &p); /* pָ��L�ĵ�j����� */
		h = PriorPos(L, p); /* hָ��p��ǰ�� */
		if (h)
			printf("%d��ǰ����%d��\n", p->data, h->data);
		else
			printf("%dûǰ����\n", p->data);
	}
	k = ListLength(L);
	for (j = k - 1; j <= k; j++)
	{
		LocatePos(L, j, &p); /* pָ��L�ĵ�j����� */
		h = NextPos(p); /* hָ��p�ĺ�� */
		if (h)
			printf("%d�ĺ����%d��\n", p->data, h->data);
		else
			printf("%dû��̡�\n", p->data);
	}
	printf("L�н�����=%d L�Ƿ�� %d(1:�� 0:��)\n", ListLength(L), ListEmpty(L));
	p = GetLast(L); /* pָ�����һ����� */
	SetCurElem(p, 15); /* �����һ������ֵ��Ϊ15 */
	printf("��1��Ԫ��Ϊ%d ���1��Ԫ��Ϊ%d\n", GetCurElem(GetHead(L)->next), GetCurElem(p));
	MakeNode(&h, 10);
	InsBefore(&L, &p, h); /* ��10�嵽β���֮ǰ��pָ���½�� */
	p = p->next; /* p�ָ�Ϊβ��� */
	MakeNode(&h, 20);
	InsAfter(&L, &p, h); /* ��20�嵽β���֮�� */
	k = ListLength(L);
	printf("����ɾ����β��㲢�����ֵ��");
	for (j = 0; j <= k; j++)
	{
		i = Remove(&L, &p);
		if (!i) /* ɾ�����ɹ� */
			printf("ɾ�����ɹ� p=%u\n", p);
		else
			printf("%d ", p->data);
	}
	MakeNode(&p, 29); /* �ؽ�����1�����(29)������ */
	InsFirst(&L, L.head, p);
	DestroyList(&L); /* ������������L */
	printf("������������L֮��: L.head=%u L.tail=%u L.len=%d\n", L.head, L.tail, L.len);
}