#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

typedef struct {
    node_t *first;
} list_t;

list_t *create() {
    list_t *list;
    list = malloc(sizeof(list_t));
    list->first = NULL;
    return list;
}

void add(list_t *list, int i) {
    node_t *new = malloc(sizeof(node_t));
    new->value = i;
    new->next = NULL;

    if(list->first == NULL) {
        list->first = new;
        return;
    }
    
    node_t *tmp = list->first;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}

int delete(list_t *list, int pos) {
    node_t *tmp, *prev;
    int ret;
    if(list->first == NULL) {
        return -1;
    }
    tmp = list->first;
    if(pos==0) {
        ret = tmp->value;
        list->first = tmp->next;
        return ret;
    }
    for(int i=0; i<pos && tmp->next!=NULL; i++) {
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp->next != NULL) {
        prev->next = tmp->next;
    }
    ret = tmp->value;
    free(tmp);
    return ret;
}

int get(list_t *list, int pos) {
    node_t *tmp;
    int ret;
    if(list->first == NULL) {
        return -1;
    }
    tmp = list->first;
    for(int i=0; i<pos && tmp->next!=NULL; i++) {
        tmp = tmp->next;
    }
    ret = tmp->value;
    return ret;
}

int main(int argc, int **argv) {
    int i;
    list_t *l = create();
    for(i = 1; i <= 7; i++) {
        add(l, i*i);
    }
	printf("delete: %d - get: %d\n", delete(l, 2), get(l, 5));
	node_t *node=l->first;
	while(node){
		printf("%p %i\n", node, node->value);
		node = node->next;
	}
	node_t *prev = l->first;
	while(node){
		node = prev ->next;
		free(prev);
	}
	free(l);
    return 0;
}