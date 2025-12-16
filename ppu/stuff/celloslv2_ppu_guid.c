#include "celloslv2_ppu_guid.h"



__attribute__((
    section(".PpuGUID"),
#ifdef  CELLOSLV2___PPU_GUID_WEAK
    __weak__
#endif
))
const
struct celloslv2_ppu_guid_s __PPU_GUID =
{

    .magic  = {
        CELLOSLV2_PPU_GUID_MAGIC0,
        CELLOSLV2_PPU_GUID_MAGIC1,
        CELLOSLV2_PPU_GUID_MAGIC2,
        CELLOSLV2_PPU_GUID_MAGIC3,
        CELLOSLV2_PPU_GUID_MAGIC4
    },

    .one    = 1,

    .zero0  = 0,

    .digest = {
#ifdef  CELLOSLV2___PPU_GUID_DUMMY
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#else
        __PPU_GUID_VALUE
#endif
    },

    .zero1  = 0

};
