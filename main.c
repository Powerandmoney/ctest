#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100 //�洢�ռ��ʼ������
#define LISTINCREMENT 10
/*1.����һ���µ���������List*/
typedef int ElemType;//ElemType���͸���ʵ�����������������Ϊint
typedef int Status;
typedef struct List {
    ElemType *elem;  //ָ�򴢴�ռ��ָ��
    int length;      //���浱ǰʹ�õĳ���
    int listsize;    //���洢��ռ����ĳ���
} List;

Status InitList(List* L) {     //����һ���յ����Ա�

    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (L->elem==NULL){
        return OVERFLOW;
	}
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

int ListLength(List *L) {
    return L->length;
}

Status GetElem(List *L, int i, ElemType *e){//��ȡԪ��
    if (L->length == 0 || i<0 || i> L->length ){
        return ERROR;
    }
    *e = L->elem[i];
    return OK;
}

Status ListInsert(List *L, int i, ElemType *e){//�������
    int k;
    if (L->length == LIST_INIT_SIZE){//˳�����Ա�����
        return ERROR;
    }

    if (i<1 || i> L->length + 1){//��i���ڷ�Χ��ʱ
        return ERROR;
    }
    for (k = L->length - 1; k >= i - 1; k--){
            L->elem[k + 1] = L->elem[k];
    }
	
    L->elem[i - 1] = *e;//����Ԫ�ز���
    L->length++;
    return OK;
}


int main()
{
	int i=1;
	int len = 0;

ElemType* e=(ElemType*)malloc(sizeof(ElemType));
  List* L = (List*)malloc(sizeof(List));
    Status result = InitList(L);
// printf(" init result = %d", result);
	for(i=1;i< L->listsize;i++){
		 L->elem[i]=i;
  }
	GetElem(L,i,e);
//printf("e=%d",e);
	len = ListLength(L);
//printf("len=%d",len);
    ListInsert(L,i,e);
   printf("len=%d",len);
	free(L);
    return 0;
}
