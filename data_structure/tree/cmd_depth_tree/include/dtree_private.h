#ifndef __DTREE_PRIVATE_H__
#define __DTREE_PRIVATE_H__

#ifdef __cplusplusa
extern "C" {
#endif /*__cpluseplus */

#define DNODE_NAME_LEN 80

typedef (*__node_callback) (void *data)

struct _dtree_node {
	int idx;
	int parent_node;
	char name[DNODE_NAME_LEN];
}

struct _dtree_index_table

#ifdef __cplusplusa
}
#endif /*__cpluseplus */
#endif /* __DEPTH_TREE_PRIVATE_H__ */
