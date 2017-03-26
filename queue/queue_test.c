#include <stdio.h>

#define QUEUE_SIZE   5 //队列最大容量 -1

typedef struct
{
	int aData[QUEUE_SIZE]; //队列元素
	int dwHead;  //队首
	int dwTail;  //队尾
}T_QUEUE, *PT_QUEUE;

//初始化队列
void InitQue(PT_QUEUE ptQue)
{
	memset(ptQue, 0, sizeof(* ptQue));
}

//插入元素
void EnterQue(PT_QUEUE ptQue, int dwElem)
{
	if(IsQueFull(ptQue))
	{
		printf("Elem %d cannot enter Queue %p(Ful)\n", dwElem, ptQue);
		return;
	}
	ptQue->aData[ptQue->dwTail] = dwElem;
	ptQue->dwTail = (ptQue->dwTail+1) % QUEUE_SIZE;
}

//取出元素
int LeaveQue(PT_QUEUE ptQue)
{
	if ( IsQueEmpty(ptQue) )
	{
		printf("Queue %p is Empty!\n", ptQue);
		return -1;
	}
	int dwElem = ptQue->aData[ptQue->dwHead];
	ptQue->dwHead = (ptQue->dwHead+1) % QUEUE_SIZE;
	return dwElem;
}

//从队首至队尾依次显示队中元素值
void DisplayQue(PT_QUEUE ptQue)
{
	if ( IsQueEmpty(ptQue) )
	{
		printf("Queue %p is Empty!\n", ptQue);
		return;
	}
	printf("Queue Element: ");
	int dwIdx = ptQue->dwHead;
	while ( ((dwIdx%QUEUE_SIZE) != ptQue->dwTail) )
	{
		printf("%d, ", ptQue->aData[(dwIdx++) % QUEUE_SIZE]);
	}
	return;
}

int IsQueFull(PT_QUEUE ptQue)
{
	return ((ptQue->dwTail+1)%QUEUE_SIZE == ptQue->dwHead) ? 1 : 0;
}

int IsQueEmpty(PT_QUEUE ptQue)
{
	return (ptQue->dwHead == ptQue->dwTail) ? 1 : 0;
}

//获取循环队列元素数目
int QueDataNum(PT_QUEUE ptQue)
{
	return (ptQue->dwTail - ptQue->dwHead + QUEUE_SIZE) %QUEUE_SIZE;
}

//获取循环队列队首元素
int GetQueHead(PT_QUEUE ptQue)
{
	return ptQue->dwHead;
}

//获取循环队列队尾位置
int GetQueTail(PT_QUEUE ptQue)
{
	return ptQue->dwTail;
}

static T_QUEUE gtQueue;

void QueueTest(void)
{
	InitQue(&gtQueue);
	printf("Enter Queue 1,2,3,4,5...\n");
	EnterQue(&gtQueue, 1);
	EnterQue(&gtQueue, 2);
	EnterQue(&gtQueue, 3);
	EnterQue(&gtQueue, 4);
	EnterQue(&gtQueue, 5);
	printf("Queue Status: Empty(%d), Full(%d)\n", IsQueEmpty(&gtQueue), IsQueFull(&gtQueue));
	printf("Queue Elem Num: %d\n", QueDataNum(&gtQueue));
	printf("Head: %d(%d)\n", GetQueHead(&gtQueue), gtQueue.aData[gtQueue.dwHead]);
	printf("Tail: %d\n", GetQueTail(&gtQueue));

	DisplayQue(&gtQueue);

	printf("\nLeave Queue...\n");
	printf("Leave %d\n", LeaveQue(&gtQueue));
	printf("Leave %d\n", LeaveQue(&gtQueue));
	printf("Leave %d\n", LeaveQue(&gtQueue));

	printf("Head: %d(%d)\n", GetQueHead(&gtQueue), gtQueue.aData[gtQueue.dwHead]);
	printf("Tail: %d\n", GetQueTail(&gtQueue));
	DisplayQue(&gtQueue);

	printf("\nEnter Queue 6,7...\n");
	EnterQue(&gtQueue, 6);
	EnterQue(&gtQueue, 7);

	printf("Head: %d(%d)\n", GetQueHead(&gtQueue), gtQueue.aData[gtQueue.dwHead]);
	printf("Tail: %d\n", GetQueTail(&gtQueue));
	DisplayQue(&gtQueue);

	printf("\nLeave Queue...\n");
	printf("Leave %d\n", LeaveQue(&gtQueue));
	printf("Leave %d\n", LeaveQue(&gtQueue));
	printf("Leave %d\n", LeaveQue(&gtQueue));
	
	printf("Head: %d(%d)\n", GetQueHead(&gtQueue), gtQueue.aData[gtQueue.dwHead]);
	printf("Tail: %d\n", GetQueTail(&gtQueue));
	DisplayQue(&gtQueue);
}

int main(int argc, char *argv)
{
	QueueTest();
	return 0;
}

