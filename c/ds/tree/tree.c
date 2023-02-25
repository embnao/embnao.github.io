#include <stdlib.h>
#include <string.h>
#include "tree.h"

int btree_init(btree_t **tree, int size)
{
	btree_t *mytree = malloc(sizeof(btree_t));
	if (NULL == mytree)
		return -1;
	mytree->root = NULL;
	mytree->size = size;

	*tree = mytree;

	return 0;
}

static void __insert(struct node_st **root, struct node_st *new, cmp_t cmp)
{
	int ret;

	if (*root == NULL) {
		*root = new;
		return;
	}
	
	ret = cmp((*root)->data, new->data);
	if (ret <= 0)
		__insert(&(*root)->right, new, cmp);
	else
		__insert(&(*root)->left, new, cmp);
}

int btree_add(btree_t *tree, const void *data, cmp_t cmp)
{
	struct node_st *new_node;

	new_node = malloc(sizeof(struct node_st) + tree->size);
	if (NULL == new_node)
		return -1;
	memcpy(new_node->data, data, tree->size);
	new_node->left = new_node->right = NULL;
	__insert(&tree->root, new_node, cmp);

	return 0;
}

static void __mid_traval(const struct node_st *root, pri_t pri)
{
	if (root == NULL)
		return;
	__mid_traval(root->left, pri);
	pri(root->data);
	__mid_traval(root->right, pri);
}

void btree_mid_traval(const btree_t *tree, pri_t pri)
{
	__mid_traval(tree->root, pri);	
}

static void __destroy(struct node_st **root)
{
	if (*root == NULL)
		return;
	__destroy(&(*root)->left);
	__destroy(&(*root)->right);
	free(*root);
	*root = NULL;
}

void btree_destroy(btree_t *tree)
{
	__destroy(&tree->root);	

	free(tree);
	tree = NULL;
}

static struct node_st **__search(struct node_st **root, const void *key, cmp_t cmp) 
{
	int ret;

	if (*root == NULL)
		return NULL;
	if ((ret = cmp((*root)->data, key)) == 0)
		return root; 
	if (ret > 0) {
		return __search(&(*root)->left, key, cmp);
	} else
		return __search(&(*root)->right, key, cmp);
}

// 最大节点
struct struct node_st *__find_max(struct node_st *root)
{
	if (root == NULL)
		return NULL;
	if (root->right == NULL)
		return root;
	return __find_max(root->right);
}

static void __delete(struct node_st **root)
{
	struct node_st *l, *r, *del;

	del = *root;
	r = del->right;
	l = del->left;

	if (l != NULL) {
		// 左子树为新跟
		*root = l;
		if (r) {
			// r放到以l为根这棵树上的最大结点的右子树上
			__find_max(l)->right = r;
		}
	} else
		*root = r;

	del->left = NULL;
	del->right = NULL;
	free(del);
	del = NULL;

}

int btree_delete(btree_t *tree, const void *key, cmp_t cmp)
{
	struct node_st **ret;		

	ret = __search(&tree->root, key, cmp);
	if (ret == NULL)
		return -1;
	__delete(ret);

	return 0;
}




