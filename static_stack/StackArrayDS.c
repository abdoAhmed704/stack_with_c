#include "StackArrayDS.h"


static stack_status_t stack_full(stack_ds_t *my_stack)
{

    if (my_stack->stackPointer == MAX_STACK - 1)
        return (STACK_FULL);
    else
        return(STACK_NOT_FULL);
}
static stack_status_t stack_empty(stack_ds_t *my_stack)
{
    if (my_stack->stackPointer == -1)
        return (STACK_EMPTY);
    else
        return (STACK_NOT_FULL);

}



return_status_t stack_init(stack_ds_t *my_stack)
{
    return_status_t ret = R_NOK;
    if (NULL == my_stack)
        ret = R_NOK;
    else
    {
        my_stack->stackPointer = -1;
        ret = R_OK;
    }
    

    return (ret);
}


return_status_t stack_push(stack_ds_t *my_stack, uint32 value){
    return_status_t ret = R_NOK;
    if (stack_full (my_stack) == STACK_FULL || NULL == my_stack)
        ret = R_NOK;
    
    else
    {
        my_stack->stackPointer++;
        my_stack->data[my_stack->stackPointer] = value;
        #ifdef STACK_DEBUG
        printf("Value (%i) is pushed\n", value);
        #endif
        ret = R_OK;
    }
    return ret;
}
return_status_t stack_pop(stack_ds_t *my_stack, uint32 *value)
{
    return_status_t ret = R_NOK;
    if (stack_empty(my_stack) == STACK_EMPTY || NULL == my_stack || NULL == value)
        ret = R_NOK;
    
    else
    {
        *value = my_stack->data[my_stack->stackPointer];
        my_stack->stackPointer--;
        #ifdef STACK_DEBUG
        printf("Value (%i) is poped\n", *value);
        #endif
        ret = R_OK;
    }
    return ret;
}    


return_status_t stack_top(stack_ds_t *my_stack, uint32 *value)
{
    return_status_t ret = R_NOK;
    if (stack_empty(my_stack) == STACK_EMPTY || NULL == my_stack || NULL == value)
        ret = R_NOK;
    
    else
    {
        *value = my_stack->data[my_stack->stackPointer];
        #ifdef STACK_DEBUG
        printf("Value (%i) is in top\n", *value);
        #endif
        ret = R_OK;
    }
    return ret;
}    

return_status_t stack_size(stack_ds_t *my_stack, uint32 *size){
    return_status_t ret = R_NOK;
    if (stack_empty(my_stack) == STACK_EMPTY || NULL == my_stack || NULL == size)
        ret = R_NOK;
    
    else
    {
        *size = my_stack->stackPointer + 1;
        ret = R_OK;
    }
    return ret;
}
return_status_t stack_display(stack_ds_t *my_stack){
    return_status_t ret = R_NOK;
    if (stack_empty(my_stack) == STACK_EMPTY || NULL == my_stack)
        ret = R_NOK;
    
    else
    {
        sint32 count = my_stack->stackPointer;
        while(count >= 0)
        {
            printf("%i) %d\n", count, my_stack->data[count]);
            count--;
        }
        ret = R_OK;
    }
    return ret;
}