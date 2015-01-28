/*  =========================================================================
    hydra - HYDRA wrapper

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of zbroker, the ZeroMQ broker project.           
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
    =========================================================================
*/

#ifndef __hydra_library_H_INCLUDED__
#define __hydra_library_H_INCLUDED__

//  External dependencies
#include <zyre.h>

//  HYDRA version macros for compile-time API detection

#define HYDRA_VERSION_MAJOR 0
#define HYDRA_VERSION_MINOR 1
#define HYDRA_VERSION_PATCH 0

#define HYDRA_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define HYDRA_VERSION \
    HYDRA_MAKE_VERSION(HYDRA_VERSION_MAJOR, HYDRA_VERSION_MINOR, HYDRA_VERSION_PATCH)

#if defined (__WINDOWS__)
#   if defined LIBHYDRA_STATIC
#       define HYDRA_EXPORT
#   elif defined LIBHYDRA_EXPORTS
#       define HYDRA_EXPORT __declspec(dllexport)
#   else
#       define HYDRA_EXPORT __declspec(dllimport)
#   endif
#else
#   define HYDRA_EXPORT
#endif

//  Opaque class structures to allow forward references
typedef struct _hydra_t hydra_t;
#define HYDRA_T_DEFINED
typedef struct _hydra_proto_t hydra_proto_t;
#define HYDRA_PROTO_T_DEFINED
typedef struct _hydra_server_t hydra_server_t;
#define HYDRA_SERVER_T_DEFINED
typedef struct _hydra_client_t hydra_client_t;
#define HYDRA_CLIENT_T_DEFINED
typedef struct _hydra_post_t hydra_post_t;
#define HYDRA_POST_T_DEFINED
typedef struct _hydra_ledger_t hydra_ledger_t;
#define HYDRA_LEDGER_T_DEFINED


//  Public API classes
#include "hydra_proto.h"
#include "hydra_server.h"
#include "hydra_client.h"
#include "hydra_post.h"
#include "hydra_ledger.h"

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
