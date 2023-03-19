
#include "queue.h"

BTNode* BinaryTreeCreate(BTDateType* a, int n, int* pi);
void BinaryTreeDestory(BTNode** proot);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDateType x);
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeLevelOrder(BTNode* root);
int BinaryTreeComplete(BTNode* root);

int main()
{
	BTDateType* a = "ABD##E#H##CF##G##";
	int n = (int)strlen(a);

	int i = 0;

	BTNode* root = BinaryTreeCreate(a, n, &i);

	printf("TreeSize %d\n", BinaryTreeSize(root));

	printf("TreeLeftSize %d\n", BinaryTreeLeafSize(root));

	printf("TreeLevelKsize %d\n", BinaryTreeLevelKSize(root, 4));

	printf("Root6 %p\n", root->left->right);
	printf("Root6 %p\n", BinaryTreeFind(root, 'E'));

	BinaryTreePrevOrder(root);
	printf("\n");

	printf("Complete %d\n", BinaryTreeComplete(root));

	BinaryTreeLevelOrder(root);

	BinaryTreeDestory(&root);
	return 0;
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftheight = TreeHeight(root->left);
	int rightheight = TreeHeight(root->right);

	return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
}

int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* tmp = QueueHead(&q);
		QueuePop(&q);
		if (tmp == NULL)
		{
			break;
		}
		QueuePush(&q, tmp->left);
		QueuePush(&q, tmp->right);

	}
	while (!QueueEmpty(&q))
	{
		BTNode* tmp = QueueHead(&q);
		QueuePop(&q);
		if (tmp != NULL)
		{
			QueueDestroy(&q);
			return false;
			break;
		}
	}

	QueueDestroy(&q);
	return true;
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* tmp = QueueHead(&q);
		QueuePop(&q);
		if (tmp != NULL)
		{
			QueuePush(&q, tmp->left);
			QueuePush(&q, tmp->right);
			printf("%c ", tmp->val);
		}
	}

	QueueDestroy(&q);
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c", root->val);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

BTNode* BinaryTreeFind(BTNode* root, BTDateType x)
{
	if (root == NULL)
		return NULL;

	if (root->val == x)
		return root;

	BTNode* leftfind = BinaryTreeFind(root->left, x);
	if (leftfind != NULL)
		return leftfind;
	BTNode* rightfind = BinaryTreeFind(root->right, x);
	return rightfind != NULL ? rightfind : NULL;
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeSize(BTNode* root)
{
	return root == NULL ?
		0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

void BinaryTreeDestory(BTNode** proot)
{
	if (*proot == NULL)
		return;
	BinaryTreeDestory(&((*proot)->left));
	BinaryTreeDestory(&((*proot)->right));
	free(*proot);
	*proot = NULL;
}

BTNode* BinaryTreeCreate(BTDateType* a, int n, int* pi)
{
	if (*(a + *pi) == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("TreeCreateMallocFail");
		exit(-1);
	}
	root->val = *(a + *pi);
	(*pi)++;
	root->left = BinaryTreeCreate(a, n, pi);
	root->right = BinaryTreeCreate(a, n, pi);

	return root;
}