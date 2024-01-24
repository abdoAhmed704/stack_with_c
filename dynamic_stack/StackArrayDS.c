#include "StackArrayDS.h"

static uint8 StackIsEmpty (Stack_t* stack_obj)
{
    return (stack_obj->ElementCount == 0);
}

static uint8 StackIsFull (Stack_t* stack_obj){
    return (stack_obj->ElementCount == stack_obj->StackMaxSize);
}


/**
  * @brief  This algorithm creates an empty stack by allocating the head
            structure and the array from dynamic memory.
  * @param  (maxSize) Stack maximum number of elements
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to the allocated stack in the heap
  */
Stack_t* CreateStack (uint32 maxSize, StackStatus_t *ret_status)
{
    Stack_t* stack = NULL;
    if (ret_status == NULL)
    {
        *ret_status = STACK_NULL_POINTER;
        stack = NULL;
    }
    else
    {
        stack = (Stack_t*)malloc(sizeof(Stack_t));
        if(!stack)
        {
            *ret_status = STACK_NOK;
            stack = NULL;
        }
        else
        {
            stack->StackMaxSize = maxSize;
            stack->StackTop = -1;
            stack->ElementCount = 0;

            stack->StackArray = (void **)calloc(stack->StackMaxSize, sizeof(void *));
            if (!stack->StackArray)
            {
                free(stack);
                *ret_status = STACK_NOK;
                stack = NULL;
            }
            else
            {
                *ret_status = STACK_OK;
            }
        }
    }
    return (stack);
}

/**
  * @brief  This function releases all memory to the heap.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval NULL
  */
Stack_t* DestroyStack (Stack_t* stack_obj, StackStatus_t *ret_status)
{
    if(!stack_obj || !ret_status)
    {
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        free(stack_obj->StackArray);
        free(stack_obj);
        *ret_status = STACK_OK;
    }
    return (NULL);
}

/**
  * @brief This function pushes an item onto the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (itemPtr) pointer to be inserted
  * @retval Status returned while performing this operation
  */
StackStatus_t PushStack(Stack_t* stack_obj, void* itemPtr)
{
    StackStatus_t ret = STACK_NOK;
    if(!stack_obj || !itemPtr)
    {
        ret = STACK_NULL_POINTER;
        #ifdef DEPUG
            printf("NULL\n");
        #endif
    }
    else
    {
        if (StackIsFull(stack_obj))
        {
            ret = STACK_FULL;

            #ifdef DEPUG
            printf("FULL!!!!!\n");
            #endif
        }
        else
        {
            #ifdef DEPUG
            printf("stack_obj->ElementCount = %i\n", stack_obj->ElementCount);
            #endif

            stack_obj->ElementCount++;

            #ifdef DEPUG
            printf("stack_obj->StackTop = %i\n", stack_obj->StackTop);
            #endif
            
            (stack_obj->StackTop)++;
            stack_obj->StackArray[stack_obj->StackTop] = itemPtr;
            ret = STACK_OK;
        }

    }
    return (ret);
}

/**
  * @brief This function pops the item on the top of the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* PopStack (Stack_t* stack_obj, StackStatus_t *ret_status)
{
    void* value = NULL;
    if(!stack_obj || !ret_status)
    {
        *ret_status = STACK_NULL_POINTER;
        value = NULL;
        #ifdef DEPUG
        printf("NULL\n");
        #endif
    }
    else
    {
        if (StackIsEmpty(stack_obj))
        {
            *ret_status = STACK_EMPTY;
            value = NULL;

            #ifdef DEPUG
            printf("EMPTY IN POPPED\n");
            #endif
        }
        else
        {
            *ret_status = STACK_OK;
            value = stack_obj->StackArray[stack_obj->StackTop];
            (stack_obj->StackTop)--;
            (stack_obj->ElementCount)--;
        }
    }
    return (value);
}

/**
  * @brief  This function retrieves the data from the top of the
            stack without changing the stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void* StackTop (Stack_t* stack_obj, StackStatus_t *ret_status)
{
    void* value = NULL;
    if(!stack_obj || !ret_status)
    {
        *ret_status = STACK_NULL_POINTER;
        value = NULL;
        #ifdef DEPUG
        printf("NULL\n");
        #endif
    }
    else
    {
        if (StackIsEmpty(stack_obj))
        {
            *ret_status = STACK_EMPTY;
            value = NULL;

            #ifdef DEPUG
            printf("EMPTY IN POPPED\n");
            #endif
        }
        else
        {
            *ret_status = STACK_OK;
            value = stack_obj->StackArray[stack_obj->StackTop];
        }
    }
    return (value);
}

/**
  * @brief  Returns number of elements in stack.
  * @param  (stack_obj) pointer to stack head structure
  * @param  (stack_count) number of elements in stack.
  * @retval Status returned while performing this operation
  */
StackStatus_t StackCount (Stack_t* stack_obj, uint32 *stack_count)
{
    StackStatus_t ret_status = STACK_NOK;
    if(!stack_obj || !stack_count)
    {
        ret_status = STACK_NULL_POINTER;

        #ifdef DEPUG
        printf("NULL\n");
        #endif
    }
    else
    {
        *stack_count = stack_obj->ElementCount;
        ret_status = STACK_OK;   
    }
    return ret_status;
    
}
