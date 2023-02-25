#ifndef __TREE_H__
#define __TREE_H__

struct node_st {
	struct node_st *left;
	struct node_st *right;
	char data[0];
};

typedef struct {
	struct node_st *root;
	int size;
}btree_t;

typedef int (*cmp_t)(const void *data, const void *key); 

typedef void (*pri_t)(const void *data);

extern int btree_init(btree_t **tree, int size);

extern int btree_add(btree_t *tree, const void *data, cmp_t cmp);

extern int btree_delete(btree_t *tree, const void *key, cmp_t cmp);

extern void btree_mid_traval(const btree_t *tree, pri_t pri);

extern void btree_destroy(btree_t *tree);

#endif

