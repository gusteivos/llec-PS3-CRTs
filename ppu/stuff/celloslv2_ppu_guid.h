
#ifndef CELLOSLV2_PPU_GUID_H
#define CELLOSLV2_PPU_GUID_H


#define CELLOSLV2PG_NMAGIC 5

#define CELLOSLV2PG_MAGIC0 0
#define CELLOSLV2PG_MAGIC1 1
#define CELLOSLV2PG_MAGIC2 2
#define CELLOSLV2PG_MAGIC3 3
#define CELLOSLV2PG_MAGIC4 4


#define CELLOSLV2_PPU_GUID_MAGIC0 '\x7F'
#define CELLOSLV2_PPU_GUID_MAGIC1 'G'
#define CELLOSLV2_PPU_GUID_MAGIC2 'U'
#define CELLOSLV2_PPU_GUID_MAGIC3 'I'
#define CELLOSLV2_PPU_GUID_MAGIC4 'D'



__attribute__((packed))
struct celloslv2_ppu_guid_s
{

    unsigned char magic[CELLOSLV2PG_NMAGIC]; /* DEL, 'G', 'U', 'I', 'D' */

    unsigned char one;

    unsigned short zero0;

    unsigned char digest[20];

    unsigned int zero1;

};


#endif/*CELLOSLV2_PPU_GUID_H*/
