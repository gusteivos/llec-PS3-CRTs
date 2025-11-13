
#ifndef SCE_SPU_LOCAL_STORAGE_PARAMETER_H
#define SCE_SPU_LOCAL_STORAGE_PARAMETER_H

#include <spu_intrinsics.h>



#define SCE_SPU_LS_PARAMETER(_heap_size, _stck_size)    \
__attribute__((aligned(16)))                            \
const                                                   \
union sce_spu_ls_parameter_u _cell_spu_ls_param = {     \
    .heap_size = _heap_size,                            \
    .stck_size = _stck_size,                            \
    .zero0     = 0         ,                            \
    .zero1     = 0                                      \
};



__attribute__((packed, aligned(16)))
union sce_spu_ls_parameter_u
{

    struct {

        unsigned int heap_size;

        unsigned int stck_size;

        unsigned int zero0    ;

        unsigned int zero1    ;

    };

    vec_uint4 hsssz0z1;

};



extern
const
union sce_spu_ls_parameter_u _cell_spu_ls_param;

#endif/*SCE_SPU_LOCAL_STORAGE_PARAMETER_H*/
