#include "llec_ppu_crt.h"
#include "llec_ppu_crtdebug.h"



#ifdef  LLEC_PPU_CRT0DEBUG

unsigned long long __llec_ppu_crt0debug_initial_sp ;
unsigned long long __llec_ppu_crt0debug_initial_toc;

unsigned long long __llec_ppu_crt0debug_initial_r3 ;
unsigned long long __llec_ppu_crt0debug_initial_r4 ;

unsigned long long __llec_ppu_crt0debug_initial_r13;

#endif



extern
void _start(
    unsigned long long r3_argc,
    unsigned long long r4_argv
    );
