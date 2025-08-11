#ifndef __DSAX_DEF_H
#define __DSAX_DEF_H

#include "dada_def.h"

// default dada block keys
#define REORDER_BLOCK_KEY 0x0000eada // for reorder program.
#define XGPU_BLOCK_KEY 0x0000fada // for xgpu program. 

// constants
#define PI 3.14159265359
#define CVAC 299792458.0

// config parameters for bfCorr
#define NPACKETS_PER_BLOCK 2048
#define NANTS 256
#define NBASE 32896
#define NCHAN_PER_PACKET 384
#define NBEAMS 512
#define halfFac 4
#define power_cycle 8

// stuff on beam positioning - TBD
#define sep 1.0 // arcmin
#define sep_ns 0.75 // arcmin
#define OVRO_LAT 37.23
#define BEAM_CHBW_MHZ 0.244140625

#endif 

