#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    node* fast = head;
    node* slow = head;
    while(fast != NULL) {
        fast = fast->next;
        if(fast == NULL) break;
        fast = fast->next;
        if(fast == NULL) break;
        slow = slow->next;
        if(fast == slow) return 1;
    }
    return 0;
}