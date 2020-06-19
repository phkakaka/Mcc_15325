/** @file Lookup.c
 *  @ingroup group_lookup
 *
 * @author Steve Deasy
 *
 *
 * @copyright
 **##############################################################################
 **
 **  FILE NAME : lookup.c
 **              Copyright (C) Casco Products Corporation 2011
 **
 **  FUNCTION  : lookup_uxuy - unsigned x, unsigned y
 **              lookup_uxsy - unsigned x, signed y
 **              lookup_sxuy - signed x, unsigned y
 **              lookup_sxsy - signed x, signed y
 **
 **  ABSTRACT
 **
 **      This routine uses a single input word to determine a single
 **      output word. This is the basic function of X (FOX) of the form
 **      yout = f(xin).
 **
 **  Input Parameters:
 **
 **      xin - input x value
 **		num_pairs - number of x,y pairs in the function
 **      xarray -  name of array containing the x values
 **      yarray -  name of array containing the x values
 **
 **  Return Value:
 **
 **      yout - output y
 **
 **  The lookup algorithm:
 **
 **      If xin is less than or equal to the lowest x value in the function fn
 **      then
 **          yout = fn(x lowest)
 **      else if xin is greater than or equal to the highest x value in the
 **      function fn
 **      then
 **          yout = fn(x highest)
 **      else
 **          determine the two xvalues x1 and x2 from fn which bound xin
 **          perform linear interpolation on f(x1) and f(x2) to determine yout:
 **
 **          yout = y1 + (xin - x1) * ((y2-y1)/x2-x1))
 **
 **      endif
 **
 ** 	Notes, limitations and exceptions:
 **
 **	The xarray must be entered in descending order
 **	If xin is greated than the first (highest) x table value, yout will be set to the
 **		first y value.
 **	If xin is less than the last (lowest) x table value, yout will be set to the
 **		last y value.
 **
 **##############################################################################
 **
 **  CONFIDENTIAL - CASCO PRODUCTS CORPORATION
 **
 **  This is a an unpublished work, which is a trade secret, created in
 **  2011. Casco Products Corporation owns all rights to this work and
 **  intends to maintain it in confidence to preserve its trade
 **  secret status. Casco Products Corporation reserves the right to protect
 **  this work as an unpublished copyrighted work in the event of an
 **  inadvertent or deliberate unauthorized publication. Casco Products
 **  Corporation also reserves its rights under the copyright laws to
 **  protect this work as a published work. Those having access to
 **  this work may not copy it, use it or disclose the information
 **  contained in it without the written authorization of Casco Products
 **  Corporation.
 **
 **##############################################################################
 **
 **  MODIFICATION HISTORY
 **
 **      see Code Co-op History
 **##############################################################################
 */
/******************************************************************************/
/****************************** DECLARATIONS **********************************/
/******************************************************************************/

/*-- Includes --*/
#include "Lookup.h"

/**
 * @brief Linear interpolation over unsigned input and output tables
 *
 * This function will take the xin as an input to the unsigned X array
 * and interpolate over the unsigned Y array.  Note that the arrays must
 * be the same size as denoted by num_pairs.
 *
 * @param xin Input value to be interpolated
 * @param num_pairs Length of both xarray and yarray
 * @param xarray Input table for interpolation
 * @param yarray Output table for interpolation
 * @return Interpolated value
 *
 * @ingroup group_lookup
 */
UINT_16 lookup_uxuy(UINT_16 xin, UINT_16 num_pairs,
					const UINT_16 *xarray, const UINT_16 *yarray)
{
	UINT_16 xi, i;
	SINT_32 dx, dy;
	SINT_32 yout;

	if (xin >= xarray[0])
	{
		yout = yarray[0];
	}
	else if (xin <= xarray[num_pairs - 1])
	{
		yout = yarray[num_pairs - 1];
	}
	else
	{
		xi = 0;
		for (i = 1; i <= num_pairs - 1; i++)
		{
			if (xin < xarray[i])
			{
				xi = i;
			}
		}
		xi = xi + 1;
		dx = (SINT_32) xarray[xi - 1] - (SINT_32) xarray[xi];
		if (dx == 0)dx = 1;
		dy = (SINT_32) yarray[xi - 1] - (SINT_32) yarray[xi];
		yout = ((SINT_32) (xin) - (SINT_32) xarray[xi])
			* (SINT_32) dy / (SINT_32) dx + (SINT_32) yarray[xi];
	}

	return (clipu(yout, UINT_16_MIN, UINT_16_MAX));
}

/**
 * @brief Linear interpolation over unsigned input table and signed output table
 *
 * This function will take the xin as an input to the unsigned X array
 * and interpolate over the signed Y array.  Note that the arrays must
 * be the same size as denoted by num_pairs.
 *
 * @param xin Input value to be interpolated
 * @param num_pairs Length of both xarray and yarray
 * @param xarray Input table for interpolation
 * @param yarray Output table for interpolation
 * @return Interpolated value
 *
 * @ingroup group_lookup
 */
SINT_16 lookup_uxsy(UINT_16 xin, UINT_16 num_pairs,
					const UINT_16 *xarray, const SINT_16 *yarray)
{
	UINT_16 xi, i;
	SINT_32 dx, dy;
	SINT_32 yout;

	if (xin >= xarray[0])
	{
		yout = yarray[0];
	}
	else if (xin <= xarray[num_pairs - 1])
	{
		yout = yarray[num_pairs - 1];
	}
	else
	{
		xi = 0;
		for (i = 1; i <= num_pairs - 1; i++)
		{
			if (xin < xarray[i])
			{
				xi = i;
			}
		}
		xi = xi + 1;
		dx = (SINT_32) xarray[xi - 1] - (SINT_32) xarray[xi];
		if (dx == 0)dx = 1;
		dy = (SINT_32) yarray[xi - 1] - (SINT_32) yarray[xi];
		yout = ((SINT_32) (xin) - (SINT_32) xarray[xi])
			* (SINT_32) dy / (SINT_32) dx + (SINT_32) yarray[xi];
	}

	return (clips(yout, SINT_16_MIN, SINT_16_MAX));
}

/**
 * @brief Linear interpolation over signed input table and unsigned output table
 *
 * This function will take the xin as an input to the signed X array
 * and interpolate over the unsigned Y array.  Note that the arrays must
 * be the same size as denoted by num_pairs.
 *
 * @param xin Input value to be interpolated
 * @param num_pairs Length of both xarray and yarray
 * @param xarray Input table for interpolation
 * @param yarray Output table for interpolation
 * @return Interpolated value
 *
 * @ingroup group_lookup
 */
UINT_16 lookup_sxuy(SINT_16 xin, UINT_16 num_pairs,
					const SINT_16 *xarray, const UINT_16 *yarray)
{
	UINT_16 xi, i;
	SINT_32 dx, dy;
	SINT_32 yout;

	if (xin >= xarray[0])
	{
		yout = yarray[0];
	}
	else if (xin <= xarray[num_pairs - 1])
	{
		yout = yarray[num_pairs - 1];
	}
	else
	{
		xi = 0;
		for (i = 1; i <= num_pairs - 1; i++)
		{
			if (xin < xarray[i])
			{
				xi = i;
			}
		}
		xi = xi + 1;
		dx = (SINT_32) xarray[xi - 1] - (SINT_32) xarray[xi];
		if (dx == 0)dx = 1;
		dy = (SINT_32) yarray[xi - 1] - (SINT_32) yarray[xi];
		yout = ((SINT_32) xin - (SINT_32) xarray[xi])
			* (SINT_32) dy / (SINT_32) dx + (SINT_32) yarray[xi];
	}

	return (clipu(yout, UINT_16_MIN, UINT_16_MAX));
}

/**
 * @brief Linear interpolation over signed input and output tables
 *
 * This function will take the xin as an input to the signed X array
 * and interpolate over the signed Y array.  Note that the arrays must
 * be the same size as denoted by num_pairs.
 *
 * @param xin Input value to be interpolated
 * @param num_pairs Length of both xarray and yarray
 * @param xarray Input table for interpolation
 * @param yarray Output table for interpolation
 * @return Interpolated value
 *
 * @ingroup group_lookup
 */
SINT_16 lookup_sxsy(SINT_16 xin, UINT_16 num_pairs,
					const SINT_16 *xarray, const SINT_16 *yarray)
{
	UINT_16 xi, i;
	SINT_32 dx, dy;
	SINT_32 yout;

	if (xin >= xarray[0])
	{
		yout = yarray[0];
	}
	else if (xin <= xarray[num_pairs - 1])
	{
		yout = yarray[num_pairs - 1];
	}
	else
	{
		xi = 0;
		for (i = 1; i <= num_pairs - 1; i++)
		{
			if (xin < xarray[i])
			{
				xi = i;
			}
		}
		xi = xi + 1;
		dx = (SINT_32) xarray[xi - 1] - (SINT_32) xarray[xi];
		if (dx == 0)dx = 1;
		dy = (SINT_32) yarray[xi - 1] - (SINT_32) yarray[xi];
		yout = ((SINT_32) xin - (SINT_32) xarray[xi])
			* (SINT_32) dy / (SINT_32) dx + (SINT_32) yarray[xi];
	}

	return (clips(yout, SINT_16_MIN, SINT_16_MAX));
}
