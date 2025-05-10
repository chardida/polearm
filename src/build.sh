nasm -f bin boot.asm -o boot.bin
gcc -ffreestanding -c kernel.c -o kernel.o
ld -Ttext 0x9000 --oformat binary kernel.o -o kernel.bin
cat boot.bin kernel.bin > os.bin
echo Done!
