#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "adder.h" // Include Header for Functions in Static Library

#include "GLFW/glfw3.h" // Include GLFW Header

extern void from_foo(int x);
extern void another_src_file(int x);

int main(int argc, char const *argv[])
{
    printf("Hello\n");
    from_foo(10);
    p();
    another_src_file(200);
    printf("ADD: 1 + 3 = %d\n", add(1, 3));


    // GLFW Stuff
    GLFWwindow* window;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}
