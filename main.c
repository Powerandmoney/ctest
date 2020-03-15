#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100 //存储空间初始分配量
#define LISTINCREMENT 10
/*1.定义一个新的数据类型List*/
typedef int ElemType;//ElemType类型根据实际情况而定，这里设为int
typedef int Status;
typedef struct List {
    ElemType *elem;  //指向储存空间的指针
    int length;      //保存当前使用的长度
    int listsize;    //保存储存空间最大的长度
} List;

Status InitList(List* L) {     //构造一个空的线性表

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

Status GetElem(List *L, int i, ElemType *e){//获取元素
    if (L->length == 0 || i<0 || i> L->length ){
        return ERROR;
    }
    *e = L->elem[i];
    return OK;
}

Status ListInsert(List *L, int i, ElemType *e){//插入操作
    int k;
    if (L->length == LIST_INIT_SIZE){//顺序线性表已满
        return ERROR;
    }

    if (i<1 || i> L->length + 1){//当i不在范围内时
        return ERROR;
    }
    for (k = L->length - 1; k >= i - 1; k--){
            L->elem[k + 1] = L->elem[k];
    }
	
    L->elem[i - 1] = *e;//将新元素插入
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
