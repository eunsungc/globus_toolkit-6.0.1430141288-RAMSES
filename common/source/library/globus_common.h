/* library/globus_common.h.  Generated by configure.  */
/*
 * Copyright 1999-2006 University of Chicago
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file globus_common.h
 * @brief Headers common to all of Globus
 */

#if !defined(GLOBUS_INCLUDE_GLOBUS_COMMON_H)
#define GLOBUS_INCLUDE_GLOBUS_COMMON_H 1

#ifndef EXTERN_C_BEGIN
#    ifdef __cplusplus
#        define EXTERN_C_BEGIN extern "C" {
#        define EXTERN_C_END }
#    else
#        define EXTERN_C_BEGIN
#        define EXTERN_C_END
#    endif
#endif

#ifndef GLOBUS_GLOBAL_DOCUMENT_SET
/**
 * @mainpage Globus Common Libary
 * @copydoc globus_common
 */
#endif

/**
 * @defgroup globus_common Globus Common API
 * @brief Common Data Structures and Functions
 * @section globus_common_containers_sect Container Data Types
 * - @ref globus_list
 * - @ref globus_fifo
 * - @ref globus_handle_table
 * - @ref globus_hashtable
 * - @ref globus_priority_q
 *
 * @section globus_common_runtime_sect Common Runtime Components
 * - @ref globus_thread
 * - @ref globus_callback
 * - @ref globus_memory
 * - @ref globus_module
 *
 * @section globus_common_error_handling_sect Error Handling
 * - @ref globus_error_api
 *
 * @section globus_common_misc_sect Miscellaneous Utilities
 * - @ref globus_uuid
 * - @ref globus_url
 */
#include "globus_common_include.h"
#include "globus_module.h"
#include "globus_url.h"
#include "globus_list.h"
#include "globus_hashtable.h"
#include "globus_fifo.h"
#include "globus_symboltable.h"
#include "globus_object.h"
#include "globus_object_hierarchy.h"
#include "globus_error.h"
#include "globus_error_hierarchy.h"
#include "globus_thread.h"
#include "globus_time.h"
#include "globus_thread_pool.h"
#include "globus_handle_table.h"
#include "globus_callback.h"
#include "globus_logging.h"
#include "globus_memory.h"
#include "globus_print.h"
#include "globus_tilde_expand.h"
#include "globus_libc.h"
#include "globus_priority_q.h"
#include "globus_range_list.h"
#include "globus_debug.h"
#include "globus_args.h"
#include "globus_strptime.h"
#include "globus_thread_common.h"
#include "globus_thread_rw_mutex.h"
#include "globus_thread_rmutex.h"
#include "globus_error_errno.h"
#include "globus_error_generic.h"
#include "globus_extension.h"
#include "globus_uuid.h"
#include "globus_options.h"
#include "globus_states.h"

#ifdef __cplusplus
extern "C" {
#endif

/* most network-related functions (getpeername, getsockname,...) have
   an int* as argument, except AIX which uses size_t*. This will
   masquerade the difference. */
#if defined(__HOS_AIX__)
#define globus_netlen_t size_t
#else
#define globus_netlen_t int
#endif

/*
 * globus_barrier_t
 *
 * A generic barrier structure */
typedef struct globus_barrier_s
{
    globus_mutex_t      mutex;
    globus_cond_t       cond;
    int                 count;
} globus_barrier_t;


/******************************************************************************
			       Define constants
******************************************************************************/

/******************************************************************************
			  Module activation structure
******************************************************************************/
extern globus_module_descriptor_t	globus_i_common_module;

/**
 * @brief Globus Common Module Descriptor
 * @ingroup globus_common
 */
#define GLOBUS_COMMON_MODULE (&globus_i_common_module)


/******************************************************************************
		  		i18n
******************************************************************************/

extern globus_extension_registry_t i18n_registry;
#define I18N_REGISTRY &i18n_registry

char *
globus_common_i18n_get_string_by_key(
    const char *                        locale,
    const char *                        resource_name,
    const char *                        key);

char *
globus_common_i18n_get_string(
    globus_module_descriptor_t *        module,
    const char *                        key);

/******************************************************************************
		   Install path discovery functions
******************************************************************************/

globus_result_t
globus_location (  char **   bufp );

globus_result_t
globus_eval_path( const char * pathstring, char ** bufp);

/* returns value of GLOBUS_LOCATION in the deploy dir config file */
globus_result_t
globus_common_get_attribute_from_config_file( char *   deploy_path,
					      char *   file_location,
					      char *   attribute,
					      char **  value );

#ifdef __cplusplus
}
#endif

#endif /* GLOBUS_INCLUDE_GLOBUS_COMMON_H */