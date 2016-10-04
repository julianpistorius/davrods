/*
 * meta.h
 *
 *  Created on: 27 Sep 2016
 *      Author: billy
 */

#ifndef META_H_
#define META_H_


#include "mod_dav.h"
#include "apr_pools.h"
#include "apr_tables.h"

#include "rodsConnect.h"
#include "rodsGenQuery.h"
#include "miscUtil.h"

#include "config.h"

typedef struct IrodsMetadata
{
	char *im_key_s;
	char *im_value_s;
	char *im_units_s;
} IrodsMetadata;




#ifdef __cplusplus
extern "C"
{
#endif


apr_array_header_t *GetMetadataForCollEntry (const dav_resource *resource_p, const collEnt_t *entry_p);

apr_array_header_t *GetMetadata (rcComm_t *irods_connection_p, const objType_t object_type, const char *id_s, const char *coll_name_s, apr_pool_t *pool_p);


int printGenQI( genQueryInp_t *genQueryInp );


IrodsMetadata *AllocateIrodsMetadata (const char * const key_s, const char * const value_s, const char * const units_s, apr_pool_t *pool_p);



char *DoMetadataSearch (const char * const key_s, const char *value_s, const char * const username_s, const char * const relative_uri_s, apr_pool_t *pool_p, rcComm_t *connection_p, struct apr_bucket_alloc_t *bucket_allocator_p, davrods_dir_conf_t *conf_p, request_rec *req_p);

#ifdef __cplusplus
}
#endif


#endif /* META_H_ */
