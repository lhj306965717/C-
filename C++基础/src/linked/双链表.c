#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Node
{
	char str[30]; // �ڵ�ֵ
	struct Node *pre;
	struct Node *next; // ��һ���ڵ�
} Node;

Node* first = NULL;
Node* end = NULL; // �������β�ڵ�

// ��ӽڵ�
void addNode(char *des)
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

		end = end->next; // ���½ڵ�
	}

	end->next = NULL;
}

// ��ӡ���нڵ�
void printfNode()
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

// ɾ���ڵ�
void deleteNode(int index)
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
		printf("ɾ�������λ�ô���...");
	}
	else
	{
		Node *tempNode = temp->pre;

		tempNode->next = temp->next;

		temp->next->pre = tempNode;

		temp->next = NULL;
		temp->pre = NULL;

		free(temp); // �ͷ�����ڵ�
	}
}


int main(void)
{
	addNode("liao");
	addNode("hong");
	addNode("jie");

	printfNode();

	deleteNode(1);

	printfNode();

	return 0;
}