#include <syscall.h>
#include <stdlib.h>
#include <profan.h>

extern int main(int argc, char **argv);

int entry(int argc, char **argv, char **envp) {
    // init the environ pointer
    init_environ_ptr(envp);

    // we need to call a other entry function
    int exit_code = main(argc, argv);

    // free memory
    profan_cleanup();

    return exit_code;
}
