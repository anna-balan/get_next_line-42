# get_next_line-42
42 school project 
### Static variables 
*have a property of preserving their value even after they are out of their scope!* Hence, static variables preserve their previous value in their previous scope and are not initialized again in the new scope. 
##### Syntax: 

`static data_type var_name = var_value; `
#### Following are some interesting facts about static variables in C
1) A static int variable remains in memory while the program is running. A normal or auto variable is destroyed when a function call where the variable was declared is over. 
For example, we can use static int to count a number of times a function is called, but an auto variable can’t be used for this purpose.
2) Static variables are allocated memory in data segment, not stack segment. 
3) Static variables (like global variables) are initialized as 0 if not initialized explicitly. For example in the below program, value of x is printed as 0, while value of y is something garbage.
``` c
#include <stdio.h>
int main()
{
    static int x;
    int y;
    printf("%d \n %d", x, y);
}
```
Output
``` c
0 
[some_garbage_value] 
```
4) In C, static variables can only be initialized using constant literals. 
5) Static variables should not be declared inside structure.
