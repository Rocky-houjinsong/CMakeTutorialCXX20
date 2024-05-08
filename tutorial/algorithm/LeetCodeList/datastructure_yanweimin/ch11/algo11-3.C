/* algo11-3.c ��algo11-2.c�������������ļ�f0,f1,f2�鲢��1������Ĵ��ļ�out */
#include "../ch1/c1.h"
typedef int InfoType; /* ������������������� */
#include "../ch10/c10-1.h" /* ����KeyType��RedType��SqList */
#define k 3 /* k·�鲢 */
#define M 10 /* �����M�����ݻ��� */
#include "bo11-1.c"

void print(RedType t)
{
	printf("(%d,%d)", t.key, t.otherinfo);
}

void main()
{
	RedType r;
	int i, j;
	char fname[k][4], fout[5] = "out", s[3];
	LoserTree ls;
	for (i = 0; i < k; i++)
	{ /* ���δ�f0,f1,f2,��,k���ļ� */
		_itoa(i, s, 10); /* ����k���ļ���f0,f1,f2,�� */
		strcpy(fname[i], "f");
		strcat(fname[i], s);
		fp[i] = fopen(fname[i], "rb"); /* �Զ��ķ�ʽ���ļ�f0,f1,�� */
		printf("�������ļ�f%d�ļ�¼Ϊ:\n", i);
		do
		{
			j = fread(&r, sizeof(RedType), 1, fp[i]); /* ���ν�f0,f1,�������ݶ���r */
			if (j == 1)
				print(r); /* ���r������ */
		} while (j == 1);
		printf("\n");
		rewind(fp[i]); /* ʹfp[i]��ָ�����·���f0,f1,������ʼλ�ã��Ա����¶����ڴ� */
	}
	fp[k] = fopen(fout, "wb"); /* ��д�ķ�ʽ�򿪴��ļ�fout */
	K_Merge(ls, b); /* ���ð�����ls��k������鲢���еļ�¼�鲢������鲢�Σ������ļ�fout */
	for (i = 0; i <= k; i++)
		fclose(fp[i]); /* �ر��ļ�f0,f1,�����ļ�fout */
	fp[k] = fopen(fout, "rb"); /* �Զ��ķ�ʽ���´򿪴��ļ�fout��֤���� */
	printf("�����Ĵ��ļ��ļ�¼Ϊ:\n");
	i = 1;
	do
	{
		j = fread(&r, sizeof(RedType), 1, fp[k]); /* ��fout�����ݶ���r */
		if (j == 1)
			print(r); /* ���r������ */
		if (i++%M == 0)
			printf("\n"); /* ���� */
	} while (j == 1);
	printf("\n");
	fclose(fp[k]); /* �رմ��ļ�fout */
}