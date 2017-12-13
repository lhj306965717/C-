#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<memory.h>
//#include<malloc.h>

// ������

typedef struct Node
{
	char str[30]; // �ڵ�ֵ
	struct Node *next; // ��һ���ڵ�
} Node;

static Node* first = NULL;
static Node* end = NULL; // �������β�ڵ�

/*��ӽڵ�*/
static void addNode(char *s)
{
	Node *node = (Node *)malloc(sizeof(struct Node));

	//memset(node.str, 0, 30);

	strcpy(node->str, s);

	if (first == NULL)
	{
		first = node; // �õ�һ���ڵ�ָ��ͷ�ڵ�
		end = first; // ��һ���ڵ����ͷ���Ҳ��β�ڵ�
	}
	else
	{
		end->next = node;
		end = node;
	}

	node->next = NULL; // ������β���ڵ�����ΪNULL

	printf("%s  ---  %s\n", end->str, first->str);
}

static void insertNode(char *s, int index)
{
	Node *temp = first;

	for(int i=0; i<index; i++)
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
		printf("���������λ�ô���...");
	}
	else
	{
		Node *node = (Node *)malloc(sizeof(struct Node));
		strcpy(node->str, s);

		Node *tempNode = temp->next;
		temp->next = node;
		node->next = tempNode;
	}
	
}

static void prinfNode()
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

static void deleteNode(char *s)
{
	// �����ڵ㣬Ȼ���жϽڵ�ֵ��ͬ��ɾ��
}

// ���������ظ��ˣ���Ȼ���Ͳ�һ�������Ƕ���ת��Ϊ int ����
//void deleteNode(int index)
//{
//	// �����ڵ㣬Ȼ��ɾ���ڵ�
//}

static void updateNode(char *source, char *des)
{
	//�����ڵ㣬�жϽڵ�ֵ��Ȼ����½ڵ�ֵ
}

int main_1(void)
{
	addNode("liao");
	addNode("hong");
	addNode("jie");

	insertNode("����", 1);
	prinfNode();
	insertNode("�κ��", 1);
	prinfNode();

	return 0;
}