#ifndef STACK_ARRAY_DS_H
#define STACK_ARRAY_DS_H

#include "plat_form_type.h"

#define MAX_STACK 5
// #define STACK_DEBUG

typedef struct stack_t
{
    sint32 stackPointer;
    uint32 data[MAX_STACK]; 
}stack_ds_t;

typedef enum stack_status{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NOT_FULL
}stack_status_t;


return_status_t stack_init(stack_ds_t *my_stack);
return_status_t stack_push(stack_ds_t *my_stack, uint32 value);
return_status_t stack_pop(stack_ds_t *my_stack, uint32 *value);
return_status_t stack_top(stack_ds_t *my_stack, uint32 *value);
return_status_t stack_size(stack_ds_t *my_stack, uint32 *size);
return_status_t stack_display(stack_ds_t *my_stack);

#endif /*STACK_ARRAY_DS_H*/