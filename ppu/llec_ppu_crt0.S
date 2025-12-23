#include "llec_ppu_crt.h"



	.file	"llec_ppu_crt0.S"



#if   defined (__PSL1GHT)

    .extern ._initialize
	.type ._initialize, @function

#elif defined (__LLEC__ )

	.extern .__initialize_gloss
	.type .__initialize_gloss, @function

	.extern .__initialize_c
	.type .__initialize_c, @function

	.extern .main
	.type .main, @function

	.extern .exit
	.type .exit, @function

#elif defined (__SCE__  )

    .extern ._initialize
	.type ._initialize, @function

#endif



#ifndef __LP32__

	.section ".rodata", "a"
	.align 2
	.globl __llec_ppu_crt0__TOC__tocbase
	.type __llec_ppu_crt0__TOC__tocbase, @object
	.size __llec_ppu_crt0__TOC__tocbase, 8
__llec_ppu_crt0__TOC__tocbase:
    .quad .TOC.@tocbase


    .section ".opd", "aw"

#ifdef  __PSL1GHT__OPD

	.align 3
	.globl __psl1ght__opd__start
	.size __psl1ght__opd__start, 24
__psl1ght__opd__start:
	.quad ._start
	.quad .TOC.@tocbase
	.quad 0

	.section ".rodata", "a"

#endif

	.align 3
	.globl _start
	.size _start, 24
_start:
	.long ._start
	.long 0

    .quad 0
	.quad 0

#else

    .section ".opd", "aw"
	.align 2
	.globl _start
	.size _start, 8
_start:
	.long ._start
	.long .TOC.@tocbase32

#endif



	.section ".text", "ax", @progbits
	.align 2
    .globl ._start
	.type ._start, @function
._start:

#ifdef  LLEC_PPU_CRT0DEBUG

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

    li64   (r15, __llec_ppu_crt0__TOC__tocbase);
	ld 		toc , 0(r15)

#endif


	stdu 	sp , -112(sp)
 	li      r16, 0
    std     r16, 0(sp)


#if   defined (__PSL1GHT)

	bl		._initialize

#elif defined (__LLEC__ )

	mr 		r30, r3
	mr 		r31, r4

	bl .__initialize_gloss
	nop

	bl .__initialize_c
	nop

	mr 		r3 , r30
	mr 		r4 , r31


	bl 		.main
	nop

	bl 		.exit

#elif defined (__SCE__  )

	# Maybe __SCE__ needs something special.

	bl		._initialize

#endif

	nop



.L_start_hang:
	b .L_start_hang

	.size ._start, . - ._start
