 /* bo2-8.c ˳���ʾ�����Ա�(�洢�ṹ��c2-1.h����)����չ����(10��) */
 #include"bo2-1.c"
 void InsertAscend(SqList *L,ElemType e)
 { /* ��ʼ���������ǽ������е�˳�����Ա�L�Ѵ��� */
   /* �����������L�а��ǽ�������µ�����Ԫ��e��L�ĳ��ȼ�1 */
   ElemType *newbase,*p;
   int k;
   if((*L).length>=(*L).listsize) /* ��ǰ�洢�ռ�����,���ӷ��� */
   {
     newbase=(ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
     if(!newbase)
       exit(OVERFLOW); /* �洢����ʧ�� */
     (*L).elem=newbase; /* �»�ַ */
     (*L).listsize+=LISTINCREMENT; /* ���Ӵ洢���� */
   }
   p=(*L).elem;
   for(k=1;k<=(*L).length;k++)
     if(e>*p)
       p++;
     else
       break;
   ListInsert(L,k,e); /* ������bo2-1.c�� */
 }

 void InsertDescend(SqList *L,ElemType e)
 { /* ��ʼ�����������������е�˳�����Ա�L�Ѵ��� */
   /* �����������L�а�����������µ�����Ԫ��e��L�ĳ��ȼ�1 */
   ElemType *newbase,*p;
   int k;
   if((*L).length>=(*L).listsize) /* ��ǰ�洢�ռ�����,���ӷ��� */
   {
     newbase=(ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
     if(!newbase)
       exit(OVERFLOW); /* �洢����ʧ�� */
     (*L).elem=newbase; /* �»�ַ */
     (*L).listsize+=LISTINCREMENT; /* ���Ӵ洢���� */
   }
   p=(*L).elem;
   for(k=1;k<=(*L).length;k++)
     if(e<*p)
       p++;
     else
       break;
   ListInsert(L,k,e); /* ������bo2-1.c�� */
 }

 Status HeadInsert(SqList *L,ElemType e)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L��ͷ�������µ�����Ԫ��e��L�ĳ��ȼ�1 */
   ElemType *p,*q,*newbase;
   if((*L).length>=(*L).listsize)
   {
     newbase=(ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
     if(!newbase)
       exit(OVERFLOW);
     (*L).elem=newbase;
     (*L).listsize+=LISTINCREMENT;
   }
   q=(*L).elem;
   for(p=(*L).elem+(*L).length-1;p>=q;--p)
     *(p+1)=*p;
   *q=e;
   (*L).length++;
   return OK;
 }

 Status EndInsert(SqList *L,ElemType e)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L��β�������µ�����Ԫ��e��L�ĳ��ȼ�1 */
   ElemType *q,*newbase;
   if((*L).length>=(*L).listsize) /* ��ǰ�洢�ռ�����,���ӷ��� */
   {
     newbase=(ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
     if(!newbase)
       exit(OVERFLOW); /* �洢����ʧ�� */
     (*L).elem=newbase; /* �»�ַ */
     (*L).listsize+=LISTINCREMENT; /* ���Ӵ洢���� */
   }
   q=(*L).elem+(*L).length; /* qΪ����λ�� */
   *q=e;
   (*L).length++;
   return OK;
 }

 Status DeleteFirst(SqList *L,ElemType *e)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ����в�����1��Ԫ�� */
   /* ���������ɾ��L�ĵ�һ������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
   ElemType *p,*q;
   if(ListEmpty(*L)) /* �ձ��޷�ɾ�� */
     return ERROR;
   p=(*L).elem; /* pָ���һ��Ԫ�� */
   *e=*p;
   q=(*L).elem+(*L).length-1; /* qָ�����һ��Ԫ�� */
   for(++p;p<=q;++p)
     *(p-1)=*p; /* �ӵ�2��Ԫ��������Ԫ����ǰ�ƶ�һ��λ�� */
   (*L).length--; /* ��ǰ���ȼ�1 */
   return OK;
 }

 Status DeleteTail(SqList *L,ElemType *e)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ����в�����1��Ԫ�� */
   /* ���������ɾ��L�����һ������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
   ElemType *p;
   if(!(*L).length) /* �ձ� */
     return ERROR;
   p=(*L).elem+(*L).length-1; /* ���һ������Ԫ�ص�λ�� */
   *e=*p; /* ��ɾ��Ԫ�ص�ֵ����e */
   (*L).length--; /* ������1 */
   return OK;
 }

 Status DeleteElem(SqList *L,ElemType e)
 { /* ɾ������ֵΪe��Ԫ�أ�������TRUE�����޴�Ԫ�أ��򷵻�FALSE */
   int i=0,j;
   while(i<(*L).length&&e!=*((*L).elem+i))
     i++;
   if(i==(*L).length) /* û�ҵ� */
     return FALSE;
   else
   {
     for(j=i;j<(*L).length;j++)
       *((*L).elem+j)=*((*L).elem+j+1); /* �����Ԫ������ǰ�� */
     (*L).length--; /* ��ǰ���ȼ�1 */
     return TRUE;
   }
 }

 Status ReplaceElem(SqList L,int i,ElemType e)
 { /* ��eȡ����L�е�i��Ԫ�ص�ֵ */
   if(i<1||i>L.length) /* iֵ���Ϸ� */
     exit(ERROR);
   *(L.elem+i-1)=e;
   return OK;
 }

 Status CreatAscend(SqList *L,int n)
 { /* ���ǽ�����n��Ԫ�ص����Ա� */
   int i,j;
   ElemType e;
   InitList(L);
   printf("������%d��Ԫ��:\n",n);
   scanf("%d",&e);
   ListInsert(L,1,e); /* �ڿձ��в����1��Ԫ�� */
   for(i=1;i<n;i++)
   {
     scanf("%d",&e);
     for(j=0;j<(*L).length;j++)
       if(e<=*((*L).elem+j))
         break;
     ListInsert(L,j+1,e); /* ���ڱ��� */
   }
   return TRUE;
 }

 Status CreatDescend(SqList *L,int n)
 { /* ����������n��Ԫ�ص����Ա� */
   int i,j;
   ElemType e;
   InitList(L);
   printf("������%d��Ԫ��:\n",n);
   scanf("%d",&e);
   ListInsert(L,1,e); /* �ڿձ��в����1��Ԫ�� */
   for(i=1;i<n;i++)
   {
     scanf("%d",&e);
     for(j=0;j<(*L).length;j++)
       if(e>=*((*L).elem+j))
         break;
     ListInsert(L,j+1,e); /* ���ڱ��� */
   }
   return TRUE;
 }