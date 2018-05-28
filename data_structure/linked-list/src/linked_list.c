#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

static SList *_s_list_alloc(void)
{
	SList *list = NULL;

	list = (SList *)calloc(1, sizeof(SList));
	if (list == NULL) {
		ERR("OOM");
		return NULL;
	}

	return list;
}

SList *s_list_append(SList *list, spointer data)
{
	SList *new_list = NULL;
	SList *last = NULL;

	new_list = _s_list_alloc();
	if (new_list == NULL)
	{
		ERR("OOM");
		return NULL;
	}

	new_list->data = data;
	new_list->next = NULL;

	if (list)
	{
		last = s_list_last(list);
		last->next = new_list;
		new_list->pre = last;
		return list;
	}
	else
	{
		new_list->pre = NULL;
		return new_list;
	}
}

void s_list_free(SList *list)
{
	if (list)
	{
		list->next = NULL;
		list->pre = NULL;
		free(list);
	}
}

SList *s_list_remove(SList *list, spointer data)
{
	SList *tmp;

	tmp = list;

	while (tmp)
	{
		if (tmp->data != data)
		{
			tmp = tmp->next;
		}
		else
		{
			list = s_list_remove_link(list, tmp);
			s_list_free(tmp);
			break;
		}
	}

	return list;
}

SList *s_list_remove_link(SList *list, SList *link)
{
	if (link == NULL)
		return list;

	if (link->pre)
	{
		link->pre->next = link->next;
	}
	if (link->next)
	{
		link->next->pre = link->pre;
	}

	if (link == list)
	{
		list = list->next;
	}

	link->pre = NULL;
	link->next = NULL;

	return list;
}

SList *s_list_delete_link(SList *list, SList *link)
{
	if (link == NULL)
		return list;

	list = s_list_remove_link(list, link);
	s_list_free(link);
	link = NULL;

	return list;
}

void s_list_foreach(SList *list, s_func func, void *user_data)
{
	while (list)
	{
		(*func)(list->data, user_data);
		list = list->next;
	}
}

SList *s_list_last(SList *list)
{
	if (list)
	{
		while (list->next)
		{
			list = list->next;
		}
	}
	return list;
}
