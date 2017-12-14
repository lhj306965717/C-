#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<memory.h>
//#include<malloc.h>

// 单链表

typedef struct Node
{
	char str[30]; // 节点值
	struct Node *next; // 下一个节点
} Node;

static Node* first = NULL;
static Node* end = NULL; // 单链表的尾节点

/*添加节点*/
static void addNode(char *s)
{
	Node *node = (Node *)malloc(sizeof(struct Node));

	//memset(node.str, 0, 30);

	strcpy(node->str, s);

	if (first == NULL)
	{
		first = node; // 让第一个节点指向头节点
		end = first; // 第一个节点既是头结点也是尾节点
	}
	else
	{
		end->next = node;
		end = node;
	}

	node->next = NULL; // 给最后的尾部节点设置为NULL

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
		printf("插入链表的位置错误...");
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

	while (tempNode != NULL)
	{
		printf("%s, ", tempNode->str);
		tempNode = tempNode->next;
	}
	printf("\n------------------\n");
}

// 其实一般是没有这个删除节点方式的，有的只是删除第某个节点
static void deleteNode(char *s)
{
	Node *temp = first;
	while (temp != NULL)
	{
		Node * tempNode = NULL;// 这个临时变量不能少

		if (temp == first) // 如果是第一个节点
		{
			if (strcmp(temp->str, s) == 0)
			{
				tempNode = temp->next;
				first = tempNode;
				temp->next = NULL;
				free(temp);
				break; // 只删除一次，如果还有相同值的节点，并没有被删除
			}
		}
		
		if (temp->next != NULL)
		{
			if (strcmp(temp->next->str, s) == 0)
			{
				tempNode = temp->next->next;
				temp->next->next = NULL;
				free(temp->next);
				temp->next = tempNode; // 切换节点
				break;// 只删除一次，如果还有相同值的节点，并没有被删除
			}
			else
			{
				tempNode = temp->next;
			}
		}

		temp = tempNode;
	}
}

// 两个函数重复了，虽然类型不一样，但是都会转换为 int 类型
//void deleteNode(int index)
//{
//	// 迭代节点，然后删除节点
//}

static void updateNode(char *source, char *des)
{
	//迭代节点，判断节点值，然后更新节点值
}

int main(void)
{
	addNode("liao");
	addNode("hong");
	addNode("jie");

	insertNode("哈哈", 1);
	prinfNode();

	insertNode("廖红杰", 1);
	prinfNode();

	deleteNode("哈哈");
	prinfNode();

	return 0;
}