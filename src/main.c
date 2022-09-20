#include <stdio.h>
#include "header.h"
#include "adder.h" // Include Header for Functions in Static Library

extern void from_foo(int x);
extern void another_src_file(int x);

int main(int argc, char const *argv[])
{
    printf("Hello\n");
    from_foo(10);
    p();
    another_src_file(200);
    printf("ADD: 1 + 3 = %d\n", add(1, 3));
    return 0;
}
