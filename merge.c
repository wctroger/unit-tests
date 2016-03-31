#include "swap.c"

List* sortedMerge(List* a, List* b);
void split(List* source, List** front, List** back);

void mergeSort(List** headRef)
{
    List* head = *headRef;
    List* a;
    List* b;

    if((head == NULL) || (head->next == NULL))
	return;

    split(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}

void split(List* source, List** front, List** back)
{
    List* fast;
    List* slow;
    if(source == NULL || source->next == NULL)
    {
	*front = source;
	*back = NULL;
    }
    else
    {
	slow = source;
	fast = source->next;
	while(fast != NULL)
	{
	    fast = fast->next;
	    if(fast != NULL)
	    {
		slow = slow->next;
		fast = fast->next;
	    }
	}

	*front = source;
	*back = slow->next;
	slow->next = NULL;
    }
}

List* sortedMerge(List* a, List* b)
{
    List* result = NULL;
    if(a == NULL)
	return(b);
    else if(b == NULL)
	return(a);

/*    if(a->value <= b->value)
    {
	result = a;
	result->next = sortedMerge(a->next, b);
    }
    else
    {
	result = b;
	result->next = sortedMerge(a, b->next);
    }*/
    if(a->value > b->value)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return(result);
}
