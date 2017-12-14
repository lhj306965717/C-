#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Node
{
	char str[30]; // 节点值
	struct Node *pre;
	struct Node *next; // 下一个节点
} Node;

Node* first = NULL;
Node* end = NULL; // 单链表的尾节点

// 添加节点
static void addNode(char *des)
{
	Node *node = (Node *)malloc(sizeof(struct Node));
	strcpy(node->str, des);

	if (first == NULL)
	{
		first = node;
		end = first;
		first->pre = NULL;
	}
	else
	{
		end->next = node;
		node->pre = end;

		end = end->next; // 更新节点
	}

	end->next = NULL;
}

// 打印所有节点
static void printfNode()
{
	Node * tempNode = first;

	if (tempNode != NULL)
	{
		while (tempNode != NULL)
		{
			printf("%s, ", tempNode->str);
			tempNode = tempNode->next;
		}
		printf("\n------------------\n");
	}
}

// 删除第某个节点
static void deleteNode(int index)
{
	if (first == NULL)
		return;

	Node *temp = first;

	for (int i = 0; i < index; i++)
	{
		if (temp->next != NULL)
		{
			temp = temp->next;
		}
		else
		{
			break;
		}
	}

	if (temp == NULL)
	{
		printf("删除链表的位置错误...");
	}
	else
	{
		Node *tempNode = temp->pre;

		tempNode->next = temp->next;

		temp->next->pre = tempNode;

		temp->next = NULL;
		temp->pre = NULL;

		free(temp); // 释放这个节点
	}
}


int main_2(void)
{
	addNode("liao");
	addNode("hong");
	addNode("jie");

	printfNode();

	deleteNode(1);

	printfNode();

	return 0;
}