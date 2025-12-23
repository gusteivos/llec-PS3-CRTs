
#ifndef CELLOSLV2_SPU_LOCAL_STORAGE_PARAMETER_H
#define CELLOSLV2_SPU_LOCAL_STORAGE_PARAMETER_H


#include <spu_intrinsics.h>



#define CELLOSLV2_SPU_LS_PARAMETER(_heap_size, _stack_size) \
const														\
union celloslv2_spu_ls_parameter_u _cell_spu_ls_param = {	\
    .heap_size  = _heap_size ,                              \
    .stack_size = _stack_size,                              \
    .zero0 = 0,                                             \
    .zero1 = 0                                              \
};



__attribute__((packed))
union celloslv2_spu_ls_parameter_u
{

    struct {

        unsigned int heap_size ;

        unsigned int stack_size;

        unsigned int zero0;

        unsigned int zero1;

    };

    vec_uint4 hsssz0z1;

};


#endif/*CELLOSLV2_SPU_LOCAL_STORAGE_PARAMETER_H*/
