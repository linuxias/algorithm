#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dtree.h"
#include "dtree_debug.h"

static int __get_name_len(const char *name)
{
	int len;

	len = strlen(name);

	return len > DNODE_NAME_LEN_MAX ? DNODE_NAME_LEN_MAX : len;
}


dtree_cmd_h dtree_create_cmd_node(const char *name,
								dtree_cmd_cb cb,
								void *data)
{
	dtree_cmd_h node = NULL;
	int name_len = 0;

	RETM_IF(name == NULL, NULL, "INVALID PARAMETER");
	RETM_IF(cb == NULL, NULL, "INVALID PARAMETER");

	node = (dtree_cmd_h)calloc(0, sizeof(struct _dtree_cmd));
	RETM_IF(node == NULL, NULL, "OOM");

	name_len = __get_name_len(name);
	node->name = strndup(name, name_len);

	node->cb = cb;
	node->data = data;

	return node;
}

void dtree_destroy_cmd_node(dtree_cmd_h node)
{
	if (node)
	{
		if (node->name)
		{
			free(node->name);
		}
		free(node);
	}
}

dtree_dir_h dtree_dir_node_create(const char *name)
{
	dtree_dir_h node = NULL;
	int name_len = 0;

	RETM_IF(name == NULL, NULL, "INVALID PARAMETER");

	node= (dtree_dir_h)calloc(0, sizeof(struct _dtree_cmd));
	RETM_IF(node == NULL, NULL, "OOM");

	name_len = __get_name_len(name);
	node->name = strndup(name, name_len);

	return 0;
}

void dtree_dir_destroy(dtree_dir_h node)
{
	dtree_cmd_h cur = NULL;
	dtree_cmd_h next = NULL;
	if (node)
	{
		if (node->name)
		{
			free(node->name);
		}
		if (node->child)
		{
			cur = next = node->child;
			while(next)
			{
				next = cur->next;
				dtree_destroy_cmd_node(cur);
			}
		}
		free(node);
	}
}

int dnode_get_name_max_len(void)
{
	return DNODE_NAME_LEN_MAX;
}
