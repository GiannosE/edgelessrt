// Copyright (c) Edgeless Systems GmbH.
// Licensed under the MIT License.

#include <openenclave/corelibc/stdio.h>
#include <openenclave/enclave.h>
#include <openenclave/enclave_args.h>
#include <openenclave/internal/trace.h>
#include <stdlib.h>
#include <sys/mount.h>
#include <unistd.h>
#include "emain_t.h"

int main(int argc, char* argv[], char* envp[]);

int emain(void)
{
    oe_printf("running in development mode\n");

    const int argc = oe_get_argc();
    char** const argv = oe_get_argv();
    char** const envp = oe_get_envp();

    if (oe_load_module_host_epoll() != OE_OK ||
        oe_load_module_host_file_system() != OE_OK ||
        oe_load_module_host_resolver() != OE_OK ||
        oe_load_module_host_socket_interface() != OE_OK)
    {
        OE_TRACE_FATAL("oe_load_module_host failed");
        return 1;
    }

    if (mount("/", "/", OE_HOST_FILE_SYSTEM, 0, NULL) != 0)
    {
        OE_TRACE_FATAL("mount OE_HOST_FILE_SYSTEM failed");
        return 1;
    }

    const char* const pwd = getenv("PWD");
    if (!pwd || !*pwd || chdir(pwd) != 0)
        OE_TRACE_ERROR("cannot set pwd");

    oe_printf("invoking main\n");
    return main(argc, argv, envp);
}

oe_args_t oe_get_args(void)
{
    // Get args from host. This is just for testing and not secure:
    // - The host controls commandline arguments and environment variables.
    // These are provided to the application without any checks.
    // - The ocall receives raw pointers. It will not be checked if they really
    // point outside the enclave memory.
    oe_args_t args = {};
    if (get_args_ocall(&args) != OE_OK)
        oe_abort();
    return args;
}
