main:
	gcc -m32 -c -g -Os -march=i686 -ffreestanding -Wall -Werror ./a.c -o test.o
	ld -m elf_i386 -static -Ttest.ld -nostdlib --nmagic -o test.elf test.o
	objcopy -O binary test.elf hdd.img
	rm test.o
	rm test.elf
