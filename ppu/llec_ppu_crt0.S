#include "llec_ppu_crt.h"



	.file	"llec_ppu_crt0.S"



#ifdef __PSL1GHT

    .extern ._initialize
	.type ._initialize, @function

#else

	.extern ._initialize_libc
	.type ._initialize_libc, @function

	.extern .main
	.type .main, @function

	.extern .exit
	.type .exit, @function

#endif



	.section ".text", "ax", @progbits
    .globl ._start
	.type ._start, @function
._start:

#ifdef LLEC_PPU_CRT0DEBUG

	li64   (r14, __llec_ppu_crt0debug_initial_sp );
    std     sp , 0(r14)

    li64   (r15, __llec_ppu_crt0debug_initial_toc);
    std     toc, 0(r15)

    li64   (r16, __llec_ppu_crt0debug_initial_r3 );
    std     r3 , 0(r16)

    li64   (r17, __llec_ppu_crt0debug_initial_r4 );
    std     r4 , 0(r17)

    li64   (r18, __llec_ppu_crt0debug_initial_r13);
    std     r13, 0(r18)

#endif


#ifndef __LP32__

    li32   (r14, LLEC_PPU_CRT_BADDA1A0);
	cmpw 	r14, toc
	bne+	.L_start_.opd_is_fixed

    li64   (r15, __llec_ppu_crt0__TOC__tocbase);
	ld 		toc , 0(r15)

.L_start_.opd_is_fixed:

#endif


	stdu 	sp , -112(sp)
 	li      r16, 0
    std     r16, 0(sp)


#ifdef __PSL1GHT

	bl		._initialize

#else

	mr 		r30, r3
	mr 		r31, r4

	bl 		._initialize_libc

	mr 		r3 , r30
	mr 		r4 , r31


	bl 		.main
	nop

	bl 		.exit

#endif

	nop



.L_start_hang:
	b .L_start_hang

	.size ._start, . - ._start



#ifndef __LP32__

	.section ".rodata", "a"
	.align 2
	.globl __llec_ppu_crt0__TOC__tocbase
	.type __llec_ppu_crt0__TOC__tocbase, @object
	.size __llec_ppu_crt0__TOC__tocbase, 8
__llec_ppu_crt0__TOC__tocbase:
    .quad .TOC.@tocbase


    .section ".opd", "aw"
	.align 3
	.globl _start
	.size _start, 24
_start:
	.long ._start
	.long LLEC_PPU_CRT_BADDA1A0

    .quad 0
	.quad 0

#else

    .section ".opd", "aw"
	.align 2
	.globl _start
_start:
	.long ._start
	.long .TOC.@tocbase32

#endif
