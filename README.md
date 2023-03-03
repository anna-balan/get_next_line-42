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

### Дескриптор файла - это целое число без знака, с помощью которого процесс обращается к открытому файлу.


Дескриптор  | Описание
------------- | -------------
0    | Стандартный ввод.
1  |  Стандартный вывод.
2 | Стандартный вывод сообщений об ошибках.

 ### Чтение файла

Функция  | Описание
------------- | -------------
read   | Эта функция копирует указанное число байт из открытого файла в заданный буфер. Копирование начинается с текущей позиции указателя в файле. Число байт и буфер указываются в параметрах число-байт и буфер соответственно.
##### Функция read выполняет следующие действия:

1. Проверяет правильность параметра FileDescriptor и наличие у процесса прав на чтение. После этого она обращается к записи таблицы открытых файлов, соответствующей данному дескриптору файла.
2. Устанавливает в файле флаг, указывающий, что выполняется операция чтения. Наличие такого флага гарантирует, что другие процессы не будет обращаться к файлу во время чтения.
3. Преобразует значение указателя в файле и значение параметра число-байт в адрес блока.
4. Копирует содержимое блока в буфер.
5. Копирует содержимое буфера в область памяти, на которую указывает переменная буфер.
6. Сдвигает указатель в файле на число прочитанных байт. Это гарантирует последовательное считывание данных.
7. Вычитает количество прочитанных байт из значения переменной число-байт.
8. Повторяет те же действия до тех пор, пока не будут прочитаны все данные.
9. Возвращает общее количество прочитанных байт.
Операция завершается, если файл пустой, прочитаны все запрошенные данные или произошла ошибка.

read: From the file indicated by the file descriptor fd, the read() function reads cnt bytes of input into the memory area indicated by buf. A successful read() updates the access time for the file.

Syntax in C language 
` size_t read (int fd, void* buf, size_t cnt);  ` <br />
**Parameters:** <br />

fd: file descriptor <br />
buf: buffer to read data from <br />
cnt: length of buffer <br />
<br />
**Returns: How many bytes were actually read** <br />

return Number of bytes read on success<br />
return 0 on reaching end of file<br />
return -1 on error<br />
return -1 on signal interrupt<br />
