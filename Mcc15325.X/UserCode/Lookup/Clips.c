/** @file Clips.c
 *  @ingroup group_lookup
 *
 * @author Steve Deasy
 *
 *
 * @copyright 
 **##############################################################################
 **
 **  FILE NAME : clips.c
 **              Copyright (C) Ford Motor Company 1995
 **
 **  FUNCTION(s) : clipu
 **                clips
 **
 **  ABSTRACT
 **
 **      The clip function returns the input value "inp" clipped between
 **      the minimum value "minval" abd the maximum value "maxval".
 **
 **      Input Parameters:
 **
 **              input = SINT_32 input value to be clipped
 **              minval = low limit of clip range, UINT_16 for clipu,
 **                       SINT_16 for clips
 **              maxval = high limit of clip range, UINT_16 for clipu,
 **                       SINT_16 for clips
 **
 **      Returns:
 **
 **              retval = input clipped between minval and maxval, UINT_16 for
 **                       clipu, SINT_16 for clips
 **
 **
 **##############################################################################
 **
 **  CONFIDENTIAL - FORD MOTOR COMPANY
 **
 **  This is a an unpublished work, which is a trade secret, created in
 **  1995. Ford Motor Company owns all rights to this work and
 **  intends to maintain it in confidence to preserve its trade
 **  secret status. Ford Motor Company reserves the right to protect
 **  this work as an unpublished copyrighted work in the event of an
 **  inadvertent or deliberate unauthorized publication. Ford Motor
 **  Company also reserves its rights under the copyright laws to
 **  protect this work as a published work. Those having access to
 **  this work may not copy it, use it or disclose the information
 **  contained in it without the written authorization of Ford Motor
 **  Company.
 **
 **##############################################################################
 **
 **  MODIFICATION HISTORY
 **
 **	See CMS and/or Clearcase history.
 **/
/******************************************************************************/
/****************************** DECLARATIONS **********************************/
/******************************************************************************/

/*-- Includes --*/
#include "GlobalDef.h"	/* Casco global constant definitions */
#include "Clips.h"

/**
 * @brief Generic function to clip a signed 32 to an unsigned 16 range
 *
 * @param inp Input value to be clipped
 * @param minval Bottom of clip range
 * @param maxval Top of clip range
 * @return Unsigned clipped value
 *
 * @ingroup group_lookup
 */
UINT_16 clipu(SINT_32 inp, UINT_16 minval, UINT_16 maxval)
{
    UINT_16 retval;

    if (inp < (SINT_32) minval)
    {
	retval = minval;
    }
    else if (inp > (SINT_32) maxval)
    {
	retval = maxval;
    }
    else
    {
	retval = (UINT_16) inp;
    }

    return (retval);
}

/**
 * @brief Generic function to clip a signed 32 to an signed 16 range
 *
 * @param inp Input value to be clipped
 * @param minval Bottom of clip range
 * @param maxval Top of clip range
 * @return Signed clipped value
 *
 * @ingroup group_lookup
 */
SINT_16 clips(SINT_32 inp, SINT_16 minval, SINT_16 maxval)
{
    SINT_16 retval;

    if (inp < (SINT_32) minval)
    {
	retval = minval;
    }
    else if (inp > (SINT_32) maxval)
    {
	retval = maxval;
    }
    else
    {
	retval = (SINT_16) inp;
    }

    return (retval);
}

