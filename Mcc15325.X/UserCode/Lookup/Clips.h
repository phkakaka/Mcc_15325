/* 
 * File:   Clips.h
 * Author: joshua.hartwig
 *
 * Created on January 15, 2015, 6:04 PM
 */

#ifndef CLIPS_H
#define	CLIPS_H

#include "GlobalDef.h"

UINT_16 clipu(SINT_32 inp, UINT_16 minval, UINT_16 maxval);
SINT_16 clips(SINT_32 inp, SINT_16 minval, SINT_16 maxval);

#endif	/* CLIPS_H */

