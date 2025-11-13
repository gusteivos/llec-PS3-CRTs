


    .file   "sce_spu_guid.S"



    .section ".SpuGUID", "ax"
    .align 16
	.globl __SPU_GUID
	.type __SPU_GUID, @object
	.size __SPU_GUID, 16
__SPU_GUID:

#ifdef SCE_SPU_GUID_DUMMY

	.long 0
	.long 0
	.long 0
	.long 0

#else

	ila $2, (((__SPU_GUID_VALUE >>  0) & 0xFFFF) << 2) | 0
    ila $2, (((__SPU_GUID_VALUE >> 16) & 0xFFFF) << 2) | 1
    ila $2, (((__SPU_GUID_VALUE >> 32) & 0xFFFF) << 2) | 2
    ila $2, (((__SPU_GUID_VALUE >> 48) & 0xFFFF) << 2) | 3

#endif
