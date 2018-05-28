#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define ERR(msg) do { \
		printf("%s", msg); \
} while (0);

typedef const void *spointer;
typedef struct _SList SList;

typedef void (*s_func) (spointer data, void *user_data);

struct _SList {
	SList *pre;
	SList *next;
	spointer data;
};

SList *s_list_append(SList *list, spointer data);

void s_list_free(SList *list);

SList *s_list_remove(SList *list, spointer data);

SList *s_list_remove_link(SList *list, SList *link);

SList *s_list_delete_link(SList *list, SList *link);

void s_list_foreach(SList *list, s_func func, void *user_data);

SList *s_list_last(SList *list);

#endif /* __LINKED_LIST_H__ */

