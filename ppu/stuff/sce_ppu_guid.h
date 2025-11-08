
#ifndef SCE_PPU_GUID_H
#define SCE_PPU_GUID_H

#define SCEPG_NMAGIC 5

#define SCEPG_MAGIC0 0
#define SCEPG_MAGIC1 1
#define SCEPG_MAGIC2 2
#define SCEPG_MAGIC3 3
#define SCEPG_MAGIC4 5


#define SCE_PPU_GUID_MAGIC0 '\x7F'
#define SCE_PPU_GUID_MAGIC1 'G'
#define SCE_PPU_GUID_MAGIC2 'U'
#define SCE_PPU_GUID_MAGIC3 'I'
#define SCE_PPU_GUID_MAGIC4 'D'



__attribute__((packed, aligned(8)))
struct sce_ppu_guid_s
{

    unsigned char magic[SCEPG_NMAGIC]; /* DEL, 'G', 'U', 'I', 'D' */

    unsigned char one;

    unsigned short zero0;

    unsigned char digest[20];

    unsigned int zero1;

};

#endif
