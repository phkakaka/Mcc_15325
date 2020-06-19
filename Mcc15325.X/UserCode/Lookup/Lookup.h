/************************************************************************
 *FILE: Lookup.h
 *DESCRIPTION: Header file of the Lookup utility (Lookup.c and Clips.c)
 *AUTHOR: J. Hartwig
 *HISTORY: History will be stored in version control system
 ************************************************************************/

#ifndef _LOOKUP_H_
#define _LOOKUP_H_

#include "GlobalDef.h"	/* Casco global constant definitions */
#include "Clips.h"

UINT_16 lookup_uxuy(UINT_16 xin, UINT_16 num_pairs,
		    const UINT_16 *xarray, const UINT_16 *yarray);
SINT_16 lookup_uxsy(UINT_16 xin, UINT_16 num_pairs,
		    const UINT_16 *xarray, const SINT_16 *yarray);
UINT_16 lookup_sxuy(SINT_16 xin, UINT_16 num_pairs,
		    const SINT_16 *xarray, const UINT_16 *yarray);
SINT_16 lookup_sxsy(SINT_16 xin, UINT_16 num_pairs,
		    const SINT_16 *xarray, const SINT_16 *yarray);

#endif