#include "llec_spu_celloslv2.h"



#  if defined (__SPU_THREAD__)

__attribute__((noreturn))
void __celloslv2_spu_exit_thread(int status)
{

    spu_write_out_mbox(status);

    spu_stop(__CELLOSLV2_SPU_EXIT_THREAD_STOP_IMM);


    asm volatile ("stop");

    while(1) { }

}

#elif defined (__SPU_RAW__   )

__attribute__((noreturn))
void __celloslv2_spu_exit_raw   (int status)
{

    register volatile vec_uint4 *sp asm("$sp");


    vec_uint4 stop_0x2000 = spu_splats((unsigned int)0x2000       );

    vec_uint4 stop_status = spu_splats((unsigned int)status & 0xff);

    stop_0x2000 |= stop_status;

    sp[1] = stop_0x2000;

    spu_sync();

    asm volatile (
        "bi %0\n"
        :
        : "r"(&sp[1])
        );


    asm volatile ("stop");

    while(1) { }

}

#endif
