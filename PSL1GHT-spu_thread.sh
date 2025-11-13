
## Set up the environment.
export PS3DEV=/usr/local/ps3dev
export PSL1GHT=$PS3DEV

## Set up the path.
export PATH=$PATH:$PS3DEV/bin
export PATH=$PATH:$PS3DEV/ppu/bin
export PATH=$PATH:$PS3DEV/spu/bin


CFLAGS="-D__SPU_THREAD__ -Os"


spu-gcc -c spu/llec_spu_celloslv2.c -o llec_spu_celloslv2.c.o $CFLAGS -Ispu/include/

spu-gcc -c spu/llec_spu_crt0.c -o llec_spu_crt0.c.o $CFLAGS -Ispu/include/
spu-gcc -c spu/llec_spu_crt0.S -o llec_spu_crt0.S.o $CFLAGS -Ispu/include/ -D__ASSEMBLY__ -D__PSL1GHT -D__NEWLIB__


spu-ld -r llec_spu_crt0.c.o llec_spu_crt0.S.o llec_spu_celloslv2.c.o -o llec-PSL1GHT-crt1.o


cp llec-PSL1GHT-crt1.o $PS3DEV/spu/spu/lib/crt1.o
