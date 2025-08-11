# dsa110-casm
Correlation, beamforming, and search code for CASM, modified from DSA-110

Please ignore many of the comments in the code, especially around beamforming in bfCorr - they are not updated for CASM.

### input data formats

**dsaX_bfCorr**: This code expects a somewhat unusual input data format, based on DSA-110. The code reads blocks of complex voltage data of dimensions [NPACKETS_PER_BLOCK, NANTS, NCHAN_PER_PACKET, 2 times, 2 pol, 4-bit complex]. Each byte contains 4 bits of real and imaginary data. From fastest to slowest, the remaining axes are:
 - 2 polarisations
 - 2 time samples
 - Channels
 - Antennas
 - "slow" time samples, i.e., an index that iterates for every second time sample.

Dimensions are hardcoded in dsaX_def.h

This is not necessarily the preferred format. An ideal format to avoid initial transposes and messing with the "fast" time samples would be blocks of [channels, 2 pols, time samples, antennas]. I'm not sure what the CASM packet format is, and how straightforward it would be to create blocks in this format within the packet capture code. A compromise may also be appropriate. 

**dsaX_hella**: This code is essentially expected to replicate a multibeam version of the single-pulse search code heimdall in its input format. The code reads blocks of total-intensity data of dimensions [NBEAMS, GULP, NCHAN]. Each sample must be uint8 intensity data. From fastest to slowest, the axes are:
 - Channels
 - Time samples
 - Beams

To be confusing, the expected number of channels and beams are hardcoded within dsaX_hella, and the number of time samples is in the input config file (see the usage() function accessed via -h).

