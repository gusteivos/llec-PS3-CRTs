
#ifndef LLEC_SPU_C_RUN_TIME_DEBUG_H
#define LLEC_SPU_C_RUN_TIME_DEBUG_H

#ifdef  LLEC_SPU_CRT0DEBUG

extern vec_uint4    __llec_spu_crt0debug_initial_lr;
extern vec_uint4    __llec_spu_crt0debug_initial_sp;

extern vec_ullong2  __llec_spu_crt0debug_initial_r3;
extern vec_ullong2  __llec_spu_crt0debug_initial_r4;
extern vec_ullong2  __llec_spu_crt0debug_initial_r5;
extern vec_ullong2  __llec_spu_crt0debug_initial_r6;

#endif/*LLEC_SPU_CRT0DEBUG*/

#endif
