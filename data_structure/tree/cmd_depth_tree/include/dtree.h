#ifndef __DTREE_H__
#define __DTREE_H__

#include "dtree_private.h"
#include "dtree_type.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cpluseplus */

typedef void (*dtree_cmd_cb)(void *data);
typedef struct _dtree_cmd *dtree_cmd_h;
typedef struct _dtree_dir *dtree_dir_h;

struct _dtree_cmd {
	char *name;
	dtree_cmd_cb cb;
	void *data;
	dtree_cmd_h next;
};

struct _dtree_dir {
	char *name;
	dtree_cmd_h child;
};

dtree_cmd_h dtree_create_cmd_node(const char *name,
								dtree_cmd_cb cb,
								void *data);

void dtree_destroy_cmd_node(dtree_cmd_h node);

dtree_dir_h dtree_create_dir_node(const char *name);

void dtree_destroy_dir_node(dtree_dir_h node);


int dnode_get_name_max_len(void);


#ifdef __cplusplus
}
#endif /*__cpluseplus */
#endif /* __DTREE_H__ */
