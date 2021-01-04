// Copyright (c) Edgeless Systems GmbH.
// Licensed under the MIT License.

/**
 * @file ert_args.h
 */
#pragma once

#include <openenclave/bits/defs.h>

typedef struct _ert_args
{
    int argc; // number of elements in argv
    const char* const* argv;
    int envc; // number of elements in envp
    const char* const* envp;
    int auxc;         // number of key-value-pairs in auxv
    const long* auxv; // -> 2*auxv elements
} ert_args_t;

OE_EXTERNC_BEGIN

/**
 * Provide args for the enclave.
 *
 * This function is not supposed to be called by the application. Instead, the
 * application may implement this function to customize the args that the
 * enclave can access.
 *
 * @return An ert_args_t object. Members may be 0/NULL.
 */
ert_args_t ert_get_args(void);

int ert_get_argc(void);
char** ert_get_argv(void);
char** ert_get_envp(void);

OE_EXTERNC_END
