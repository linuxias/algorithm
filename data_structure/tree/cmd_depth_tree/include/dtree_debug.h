#ifndef __DTREE_DEBUG_H__
#define __DTREE_DEBUG_H__

#include <stdio.h>

#ifdef __cplusplusa
extern "C" {
#endif /*__cpluseplus */

#define RETM_IF(expr, val, msg) do { \
	if (expr) \
	{ \
		printf("%s\n", (msg)); \
		return (val); \
	} \
} while(0)

#define RET_IF(expr, val) do { \
	if (expr) \
	{ \
		return (val); \
	} \
} while(0)

#define RETE_IF(expr, val, msg) do { \
	if (expr) \
	{ \
		printf("%s, errno : %d, errstr : %s\n", msg, errno, strerror(errno)); \
		return (val); \
	} \
} while(0)

#ifdef __cplusplusa
}
#endif /*__cpluseplus */
#endif /* __DTREE_DEBUG_H__ */
