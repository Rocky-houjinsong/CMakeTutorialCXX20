/* main2-9.c ����bo2-9.c��������(���������⣬��main2-8.c����) */
#include "../ch1/c1.h"
typedef int ElemType;
#include "c2-2.h" /* �˾��main2-8.c��ͬ */
#include "bo2-2.c" /* �Ӵ˾� */
#include "bo2-9.c" /* �˾��main2-8.c��ͬ */

void visit(ElemType c) /* ListTraverse()���õĺ���(����Ҫһ��) */
{
	printf("%d ", c);
}

void main()
{
	LinkList L; /* �˾��main2-8.c��ͬ */
	ElemType d, e;
	Status i;
	int n;
	printf("���ǽ�����n��Ԫ�ص����Ա�L,������Ԫ�ظ���n: ");
	scanf("%d", &n);
	CreatAscend(&L, n);
	printf("�������L��Ԫ�أ�");
	ListTraverse(L, visit);
	InsertAscend(L, 10); /* ���ǽ������Ԫ��10 */
	printf("���ǽ������Ԫ��10�����Ա�LΪ��");
	ListTraverse(L, visit);
	HeadInsert(L, 12); /* ��L��ͷ������12 */
	EndInsert(L, 9); /* ��L��β������9 */
	printf("��L��ͷ������12��β������9�����Ա�LΪ��");
	ListTraverse(L, visit);
	i = GetFirstElem(L, &e); /* �˾�� */
	printf("��1��Ԫ����: %d\n", e); /* �˾�� */
	printf("������Ҫɾ����Ԫ�ص�ֵ: ");
	scanf("%d", &e);
	i = DeleteElem(L, e);
	if (i)
		printf("�ɹ�ɾ��%d!\n", e);
	else
		printf("������Ԫ��%d!\n", e);
	printf("���Ա�LΪ��");
	ListTraverse(L, visit);
	printf("������Ҫȡ����Ԫ�ص���� Ԫ�ص���ֵ: ");
	scanf("%d%d", &n, &e);
	ReplaceElem(L, n, e);
	printf("���Ա�LΪ��");
	ListTraverse(L, visit);
	DestroyList(&L);
	printf("����L��,�����������½���n��Ԫ�ص����Ա�L,������Ԫ�ظ���n(>2): ");
	scanf("%d", &n);
	CreatDescend(&L, n);
	printf("�������L��Ԫ�أ�");
	ListTraverse(L, visit);
	InsertDescend(L, 10); /* �����������Ԫ��10 */
	printf("�����������Ԫ��10�����Ա�LΪ��");
	ListTraverse(L, visit);
	printf("������Ҫɾ����Ԫ�ص�ֵ: ");
	scanf("%d", &e);
	i = DeleteElem(L, e);
	if (i)
		printf("�ɹ�ɾ��%d!\n", e);
	else
		printf("������Ԫ��%d!\n", e);
	printf("���Ա�LΪ��");
	ListTraverse(L, visit);
	DeleteFirst(L, &e);
	DeleteTail(L, &d);
	printf("ɾ����ͷԪ��%d�ͱ�βԪ��%d��,���Ա�LΪ��", e, d);
	ListTraverse(L, visit);
}