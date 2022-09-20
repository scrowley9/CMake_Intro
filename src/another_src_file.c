#include <stdio.h>

extern void another_src_file(int x){
    printf("Hi from \"another_src_file\" - %d\n", x);
}
