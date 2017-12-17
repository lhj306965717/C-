#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<memory.h>

typedef struct Node
{
	char str[30]; // 节点值
	struct Node *pre; // 上一个节点
	struct Node *next; // 下一个节点
} Node;

Node* first = NULL;
Node* end = NULL;

void addNode(char *s)
{
	Node node;

	//memset(node.str, 0, 30);

	//node.str = (char *)malloc(sizeof(char) * 30);

	strcpy(node.str, s);

	if (first == NULL)
	{
		first = &node; // 让第一个节点指向头节点
		end = first; // 第一个节点既是头结点也是尾节点
	}
	else
	{
		end->next = &node;
	}

	printf("%s  ---  %s\n", node.str, first->str);
}

int main(void)
{
	
	addNode("liao");
	//addNode("hong");
	//addNode("jie");
	printf("%d\n", strlen(first->str));

	printf("%s\n", first->str);

//	printf("%d\n", strlen(first->str));

//	printf("%d\n", strlen(first->str));
	//printf("%s\n", end->str);

	return 0;
}