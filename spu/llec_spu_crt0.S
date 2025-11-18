#include "llec_spu_crt.h"



    .file   "llec_spu_crt0.S"



    .extern llec_spu_ctr0_c___stack_size
    .type llec_spu_ctr0_c___stack_size, @function


    .extern _init
    .type _init, @function

    .extern main
    .type main, @function

    .extern exit
    .type exit, @function



#ifdef __NEWLIB__
    .comm __ea_local_store, 16, 16
#endif



	.section ".text", "ax", @progbits
    .global _start
    .type _start, @function
_start:

#ifdef  LLEC_SPU_CRT0DEBUG

	stqr	$0 , __llec_spu_crt0debug_initial_lr
	stqr	$sp, __llec_spu_crt0debug_initial_sp

	stqr	$3 , __llec_spu_crt0debug_initial_r3
	stqr	$4 , __llec_spu_crt0debug_initial_r4
	stqr	$5 , __llec_spu_crt0debug_initial_r5
	stqr	$6 , __llec_spu_crt0debug_initial_r6

#endif/*LLEC_SPU_CRT0DEBUG*/


    hbrr _init, 0


    il      $2 , 0                  #   r2 = 0
    ila     $sp, __stack            #   sp = &__stack

	stqd    $2 , 0($sp)             #   __stack[0] = r2

	stqd    $sp, -32($sp)           #   __stack[-2] = __stack
	ai      $sp, $sp     , -32      #   sp = &__stack[-2]

#
#   +--------------------------+
#   | NULL Back Chain pointer. |    0
#   +--------------------------+    &__stack[  0 ] (0x3fff0)
#   | LR reserved space.       |    unknown
#   +--------------------------+    &__stack[ -1 ] (0x3ffe0)
#   | Back Chain pointer.      |    0x3fff0
#   +--------------------------+    &__stack[ -2 ] (0x3ffd0)
#


    ori     $93, $3  , 0
    shlqbyi $94, $4  , 0
    ori     $95, $5  , 0
    shlqbyi $96, $6  , 0


    brsl    $0 , llec_spu_ctr0_c___stack_size



	brsl    $0 , _init

    ori     $3 , $93 , 0
    shlqbyi $4 , $94 , 0
    ori     $5 , $95 , 0
    shlqbyi $6 , $96 , 0


	brsl	$0, main
	brsl	$0, exit


    stop

	.size _start, . - _start



#if defined (__SPU_THREAD__) || \
    defined (__SPU_RAW__   )

    .section ".rodata", "a", @progbits
	.weak _cell_spu_ls_param
	.align 16
	.type _cell_spu_ls_param, @object
	.size _cell_spu_ls_param, 16
_cell_spu_ls_param:
	.long 0                         #   heap_size
	.long 0                         #   stck_size
	.long 0                         #   zero0
	.long 0                         #   zero1

#endif
