#include "sce_ppu_guid.h"



__attribute__((section(".PpuGUID"), aligned(8), used))
const
struct sce_ppu_guid_s __PPU_GUID =
{

    .magic  = {
        SCEPG_MAGIC0,
        SCEPG_MAGIC1,
        SCEPG_MAGIC2,
        SCEPG_MAGIC3,
        SCEPG_MAGIC4
    },

    .one    = 1,

    .zero0  = 0,

    .digest = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },

    .zero1  = 0

};
