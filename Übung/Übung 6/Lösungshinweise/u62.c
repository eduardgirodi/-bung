#include <stdio.h>
#include <stdlib.h>

typedef struct node {
       int value;
        struct node *next;
} node_t;

typedef struct {
        node_t *first;
} list_t;

list_t *create(void) {
        list_t *node;
        node = malloc(sizeof(list_t));
        node->first = NULL;
        return node;
      }

void add(list_t *list, int v) {
        node_t *node;
        node = list->first;
        node = malloc(sizeof(node_t));
        node->value = v;
        node->next = NULL;

        if (!list->first) {
            list->first = node;
            return;
        }

        node_t *tmp = list->first;

        while (tmp->next) tmp = tmp->next;
        tmp->next = node;

    }
int delete(list_t *list, int pos){
	node_t *tmp, *prev;
	tmp = list->first;
	int i;
	for(i=1; i<pos; i++){
		if(tmp){
			prev = tmp;
			tmp = tmp->next;
		}
		else
			return -1;
	}
	prev->next = tmp->next;
	free(tmp);
	return i;
}
int get(list_t *list, int pos){
node_t *tmp;
	tmp = list->first;
	int i;
	for(i=1; i<pos; i++){
		if(tmp->next){
			tmp = tmp->next;
		}
		else
			return -1;
	}
	return tmp->value;	
}

int main() {
        int i;

        list_t *l = create();
        for (i = 1; i <= 7; i++)
            add(l, i*i);
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
