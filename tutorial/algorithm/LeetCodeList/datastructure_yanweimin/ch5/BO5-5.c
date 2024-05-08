 /* bo5-5.c �������ͷβ�����洢(�洢�ṹ��c5-5.h����)�Ļ�������(11��) */
 Status InitGList(GList *L)
 { /* �����յĹ����L */
   *L=NULL;
   return OK;
 }

 void DestroyGList(GList *L) /* �������ͷβ�����洢�����ٲ��� */
 { /* ���ٹ����L */
   GList q1,q2;
   if(*L)
   {
     if((*L)->tag==ATOM)
     {
       free(*L); /* ɾ��ԭ�ӽ�� */
       *L=NULL;
     }
     else /* ɾ������� */
     {
       q1=(*L)->a.ptr.hp;
       q2=(*L)->a.ptr.tp;
       free(*L);
       *L=NULL;
       DestroyGList(&q1);
       DestroyGList(&q2);
     }
   }
 }

 Status CopyGList(GList *T,GList L)
 { /* ����ͷβ�����洢�ṹ,�ɹ����L���Ƶõ������T���㷨5.6 */
   if(!L) /* ���ƿձ� */
     *T=NULL;
   else
   {
     *T=(GList)malloc(sizeof(GLNode)); /* ������� */
     if(!*T)
       exit(OVERFLOW);
     (*T)->tag=L->tag;
     if(L->tag==ATOM)
       (*T)->a.atom=L->a.atom; /* ���Ƶ�ԭ�� */
     else
     {
       CopyGList(&((*T)->a.ptr.hp),L->a.ptr.hp);
       /* ���ƹ����L->ptr.hp��һ������T->ptr.hp */
       CopyGList(&((*T)->a.ptr.tp),L->a.ptr.tp);
       /* ���ƹ����L->ptr.tp��һ������T->ptr.tp */
     }
   }
   return OK;
 }

 int GListLength(GList L)
 { /* ���ع�����ĳ���,��Ԫ�ظ��� */
   int len=0;
   if(!L)
     return 0;
   if(L->tag==ATOM)
     return 1;
   while(L)
   {
     L=L->a.ptr.tp;
     len++;
   }
   return len;
 }

 int GListDepth(GList L)
 { /* ����ͷβ�����洢�ṹ,������L����ȡ��㷨5.5 */
   int max,dep;
   GList pp;
   if(!L)
     return 1; /* �ձ����Ϊ1 */
   if(L->tag==ATOM)
     return 0; /* ԭ�����Ϊ0 */
   for(max=0,pp=L;pp;pp=pp->a.ptr.tp)
   {
     dep=GListDepth(pp->a.ptr.hp); /* ����pp->a.ptr.hpΪͷָ����ӱ���� */
     if(dep>max)
       max=dep;
   }
   return max+1; /* �ǿձ�������Ǹ�Ԫ�ص���ȵ����ֵ��1 */
 }

 Status GListEmpty(GList L)
 { /* �ж�������Ƿ�Ϊ�� */
   if(!L)
     return TRUE;
   else
     return FALSE;
 }

 GList GetHead(GList L)
 { /* ȡ�����L��ͷ */
   GList h,p;
   if(!L)
   {
     printf("�ձ��ޱ�ͷ!\n");
     exit(0);
   }
   p=L->a.ptr.tp;
   L->a.ptr.tp=NULL;
   CopyGList(&h,L);
   L->a.ptr.tp=p;
   return h;
 }

 GList GetTail(GList L)
 { /* ȡ�����L��β */
   GList t;
   if(!L)
   {
     printf("�ձ��ޱ�β!\n");
     exit(0);
   }
   CopyGList(&t,L->a.ptr.tp);
   return t;
 }

 Status InsertFirst_GL(GList *L,GList e)
 { /* ��ʼ����: ��������� */
   /* �������: ����Ԫ��e��Ϊ�����L�ĵ�һԪ��(��ͷ,Ҳ�������ӱ�) */
   GList p=(GList)malloc(sizeof(GLNode));
   if(!p)
     exit(OVERFLOW);
   p->tag=LIST;
   p->a.ptr.hp=e;
   p->a.ptr.tp=*L;
   *L=p;
   return OK;
 }

 Status DeleteFirst_GL(GList *L,GList *e)
 { /* ��ʼ����: �����L���� */
   /* �������: ɾ�������L�ĵ�һԪ��,����e������ֵ */
   GList p;
   *e=(*L)->a.ptr.hp;
   p=*L;
   *L=(*L)->a.ptr.tp;
   free(p);
   return OK;
 }

 void Traverse_GL(GList L,void(*v)(AtomType))
 { /* ���õݹ��㷨���������L */
   if(L) /* L���� */
     if(L->tag==ATOM) /* LΪ��ԭ�� */
       v(L->a.atom);
     else /* LΪ����� */
     {
       Traverse_GL(L->a.ptr.hp,v);
       Traverse_GL(L->a.ptr.tp,v);
     }
 }