#include "llec_spu_celloslv2.h"
#include "llec_spu_crt.h"
#include "llec_spu_crtdebug.h"

#include "stuff/sce_spu_ls_parameter.h"



size_t __llec_spu_crt___stack_size;


#ifdef  LLEC_SPU_CRT0DEBUG

vec_uint4    __llec_spu_crt0debug_initial_lr;
vec_uint4    __llec_spu_crt0debug_initial_sp;

vec_ullong2  __llec_spu_crt0debug_initial_r3;
vec_ullong2  __llec_spu_crt0debug_initial_r4;
vec_ullong2  __llec_spu_crt0debug_initial_r5;
vec_ullong2  __llec_spu_crt0debug_initial_r6;

#endif/*LLEC_SPU_CRT0DEBUG*/



extern vec_uint4 __stack[] __attribute__((aligned(16)));

extern unsigned char _end[];

extern void _init(void);

extern int main(
    unsigned long long parameter1,
    unsigned long long parameter2,
    unsigned long long parameter3,
    unsigned long long parameter4
    );

extern void exit(int status) __attribute__((noreturn));

extern void _fini(void);



/* C99 requires _Exit */
void _Exit(int status) __attribute__((noreturn, __weak__, __alias__("_exit")));



void llec_spu_ctr0_c___stack_size(void)
{
    
    volatile register vec_uint4 *sp asm("$sp");

    volatile vec_uint4 *back_chain = &__stack[-2 ];


    __llec_spu_crt___stack_size = (size_t)__stack - (size_t)_end;

    __llec_spu_crt___stack_size += 16;


    unsigned int back_chain___stack_size = (unsigned int)__llec_spu_crt___stack_size - 48;

    if (_cell_spu_ls_param.stck_size != 0)
    {

        back_chain___stack_size = _cell_spu_ls_param.stck_size - 48;

    }


    back_chain[0][1] = back_chain___stack_size;

    sp[0][1] = back_chain___stack_size;

}

extern
void _start(
    unsigned long long r3_parameter1,
    unsigned long long r4_parameter2,
    unsigned long long r5_parameter3,
    unsigned long long r6_parameter4
    );

__attribute__((noreturn))
void _exit(int status)
{

    _fini();


#  if defined (__SPU_THREAD__)

    __celloslv2_spu_exit_thread(status);

#elif defined (__SPU_RAW__   )

    __celloslv2_spu_exit_raw   (status);

#endif


    asm volatile ("stop");

    while(1) { }

}
