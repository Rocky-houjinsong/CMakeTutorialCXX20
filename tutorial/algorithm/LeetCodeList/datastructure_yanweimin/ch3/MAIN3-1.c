/* main3-1.c ����bo3-1.cpp�������� */
#include "../ch1/c1.h"
typedef int SElemType; /* ����ջԪ�����ͣ��˾�Ҫ��c3-1.h��ǰ�� */
#include "c3-1.h"
#include "bo3-1.c"

Status visit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

void main()
{
	int j;
	SqStack s;
	SElemType e;
	if (InitStack(&s) == OK)
		for (j = 1; j <= 12; j++)
			Push(&s, j);
	printf("ջ��Ԫ������Ϊ��");
	StackTraverse(s, visit);
	Pop(&s, &e);
	printf("������ջ��Ԫ�� e=%d\n", e);
	printf("ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
	GetTop(s, &e);
	printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", e, StackLength(s));
	ClearStack(&s);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
	DestroyStack(&s);
	printf("����ջ��s.top=%u s.base=%u s.stacksize=%d\n", s.top, s.base, s.stacksize);
}