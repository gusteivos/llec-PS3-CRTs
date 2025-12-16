
#ifndef LLEC_PPU_C_RUN_TIME_H
#define LLEC_PPU_C_RUN_TIME_H


#ifdef  __ASSEMBLY__


#include <ppc-asm.h>



#define li32(r, value)  	 	 \
    lis r, value@h				;\
    ori r, r	  , value@l

#define li64(r, value)           \
    li      r,    value@higher  ;\
    oris    r, r, value@highest ;\
    sldi    r, r, 32            ;\
    oris    r, r, value@h       ;\
    ori     r, r, value@l        \


#else


#ifndef __LP32__

extern unsigned long long __llec_ppu_crt0__TOC__tocbase;

#endif


#endif


#endif/*LLEC_PPU_C_RUN_TIME_H*/
