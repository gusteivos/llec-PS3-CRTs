
#ifndef LLEC_SPU_CELLOS_LV_2_H
#define LLEC_SPU_CELLOS_LV_2_H

#include <spu_intrinsics.h>
#include <spu_internals.h>
#include <spu_mfcio.h>



#define __CELLOSLV2_SPU_EXIT_THREAD_STOP_IMM 0x102



extern void __celloslv2_spu_exit_thread(int status) __attribute__((noreturn));

extern void __celloslv2_spu_exit_raw   (int status) __attribute__((noreturn));

#endif/*LLEC_SPU_CELLOS_LV_2_H*/
