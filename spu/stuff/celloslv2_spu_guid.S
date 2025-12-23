


    .file   "celloslv2_spu_guid.S"



    .section ".SpuGUID", "ax", @progbits
	.align 3

#ifdef SCE___SPU_GUID_WEAK

    .weak __SPU_GUID

#else

	.globl __SPU_GUID

#endif

	.type __SPU_GUID, @object
__SPU_GUID:

#ifdef SCE___SPU_GUID_DUMMY

	.long 0
	.long 0
	.long 0
	.long 0

#else

	ila $2, (((__SPU_GUID_VALUE >> 48) & 0xFFFF) << 2) | 0
    ila $2, (((__SPU_GUID_VALUE >> 32) & 0xFFFF) << 2) | 1
    ila $2, (((__SPU_GUID_VALUE >> 16) & 0xFFFF) << 2) | 2
	ila $2, (((__SPU_GUID_VALUE >>  0) & 0xFFFF) << 2) | 3

#endif

	.size __SPU_GUID, . - __SPU_GUID
