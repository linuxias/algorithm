#ifndef __DTREE_H__
#define __DTREE_H__

#include "dtree_private.h"

#ifdef __cplusplusa
extern "C" {
#endif /*__cpluseplus */

typedef void (*__node_callback) (void *data) node_cb_t
typedef struct _dtree_node *dtree_node_h


int dnode_get_name_max_len(void);


#ifdef __cplusplusa
}
#endif /*__cpluseplus */
#endif /* __DTREE_H__ */
