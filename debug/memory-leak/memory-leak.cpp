/*
how to view memory leak?
1. compile executable program
2. leaks --atExit -- ./memory-leak
* it only helps indicates if there is a leak, it does not help detect where the leak happens

leaks ref: https://www.unix.com/man-page/mojave/1/leaks/
leaks ref: https://ankpat.github.io/macos/debugging/memory/2018/05/17/macos-leaks-tool.html

---
do not enable MallocStackLogging

if you ever enable `export MallocStackLogging=1`
undo it by `unset MallocStackLogging`
** MallocStackLogging does not work for me
*/

#include <iostream>

int main()
{
    printf("Hello world!\n");

    int* a = new int;
    *a = 8;
    delete a;

    // system("leaks memory-leak");
    return 0;
}