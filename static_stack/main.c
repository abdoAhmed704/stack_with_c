#include <stdio.h>
#include <stdlib.h>
#include "StackArrayDS.h"

stack_ds_t mystack1;
stack_ds_t mystack2;

return_status_t ret;
uint32 value;
uint32 size;

int main()
{
    

    ret = stack_init(&mystack1);
    if (ret == R_NOK)
        printf ("Stack1 didn't define\n");
    else
    {
        ret = stack_push(&mystack1, 66);    
        if (ret == R_NOK)
        printf ("Stack didn't pushed...\n");
        
        ret = stack_push(&mystack1, 636);    
        if (ret == R_NOK)
        printf ("Stack didn't pushed...\n");
        ret = stack_push(&mystack1, 86);    
        if (ret == R_NOK)
        printf ("Stack didn't pushed...\n");
        ret = stack_push(&mystack1, 41);    
        if (ret == R_NOK)
        printf ("Stack didn't pushed...\n");
        ret = stack_push(&mystack1, 82);    
        if (ret == R_NOK)
        printf ("Stack didn't pushed...\n");
        ret = stack_push(&mystack1, 704);    
        if (ret == R_NOK)
        printf ("Stack didn't pushed...\n");
        ret = stack_push(&mystack1, 7004);    
        if (ret == R_NOK)
        printf ("Stack didn't pushed...\n");
        
        ret = stack_pop(&mystack1, &value);    
        if (ret == R_NOK)
            printf ("Stack didn't pushed...\n");
        
        ret = stack_pop(&mystack1, &value);    
        if (ret == R_NOK)
            printf ("Stack didn't pushed...\n");

        ret = stack_push(&mystack1, 704);    
        if (ret == R_NOK)
        printf ("Stack didn't pushed...\n");

        ret = stack_push(&mystack1, 7004);    
        if (ret == R_NOK)
        printf ("Stack didn't pushed...\n");
        ret = stack_pop(&mystack1, &value);   
        ret = stack_pop(&mystack1, &value);   

        ret = stack_top(&mystack1, &value);
        if (ret == R_OK)
        {
            printf("value in top is = %i\n", value);
        }
        else{
            printf("Issus in top\n");
        }

        ret = stack_push(&mystack1, 445);
        if (ret == R_NOK)
        {
            printf("Pushed NOT OKEY\n");
        }
        ret = stack_top(&mystack1, &value);
        if (ret == R_OK)
        {
            printf("value in top is = %i\n", value);
        }
        else{
            printf("Issus in top\n");
        }

        ret = stack_size(&mystack1, &size);
        if (ret == R_OK)
        {
            printf("Stack_Size = %i\n", size);
        }
        else{
            printf("Issus in size\n");
        }
        
        ret = stack_display(&mystack1);
        if (ret == R_NOK)
        {
            printf("Issus in size\n");
        }

        printf("======\n");
        stack_push(&mystack1, 55);
        stack_display(&mystack1);
        stack_pop(&mystack1, &value);
        printf("======\n");
        stack_display(&mystack1);
        printf("the value is %i", value);
        stack_top(&mystack1, &value);
        printf("the value is %i", value);
        stack_top(&mystack1, &value);
        printf("the value is %i", value);
        stack_pop(&mystack1, &value);
        printf("the value is %i\n", value);
        printf("======\n\n");
        stack_display(&mystack1);
        stack_pop(&mystack1, &value);
        printf("the value is %i\n", value);
        printf("======\n");
        stack_display(&mystack1);










    }
    
    printf("\nHI\n");
    return 0;
}