#include <stdio.h>          
map
void function_1 (void);    
int main (void)
{
    int num_1 = 22;            
    printf("%d\n", num_1);
    function_1();              
    printf("%d\n", num_1);
    return (0);
}

void function_1 (void)     
{
    int num_1 = 55;             
    printf("%d\n", num_1);
    num_1= num_1 + 17 ;
    printf("%d\n", num_1) ;
    return ;
}

