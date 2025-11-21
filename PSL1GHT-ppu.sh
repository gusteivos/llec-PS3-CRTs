
## Set up the environment.
export PS3DEV=/usr/local/ps3dev
export PSL1GHT=$PS3DEV

## Set up the path.
export PATH=$PATH:$PS3DEV/bin
export PATH=$PATH:$PS3DEV/ppu/bin
export PATH=$PATH:$PS3DEV/spu/bin


ppu-gcc -c ppu/llec_ppu_crt0.c -o llec_ppu_crt0.c.o -Ippu/include/
ppu-gcc -c ppu/llec_ppu_crt0.S -o llec_ppu_crt0.S.o -Ippu/include/ -D__ASSEMBLY__ -D__PSL1GHT


ppu-ld -r llec_ppu_crt0.c.o llec_ppu_crt0.S.o PSL1GHT-ppu-crt1.o -o llec-PSL1GHT-ppu-crt0.o


cp llec-PSL1GHT-ppu-crt0.o $PS3DEV/ppu/ppu/lib/lv2-crt0.o
