#include <stdio.h>
#include <stdlib.h>

#include "dtree.h"

dtree_node_h dtree_node_create(const char *name, )
{
	dtree_node_h node = NULL;

	node = (_dtree_node)calloc(0, sizeof(struct _dtree_node));
	RETM_IF(node == NULL, NULL, "Failed to alloc memory");



	return node;
}

int dnode_get_name_max_len(void)
{
	return DNODE_NAME_LEN;
}
