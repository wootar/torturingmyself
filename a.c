__asm__(".code16\n");
__asm__("jmpl $0x0000, $main\n");

void printString(const char* pStr) {
 	while(*pStr) {
  		__asm__ __volatile__ (
    		"int $0x10" : : "a"(0x0e00 | *pStr), "b"(0x0007)
  		);
  		++pStr;
 	}
}
void write_string( int color, const char *string ) {
	volatile char *video = (volatile char*)0xB8000;
	while( *string != 0 )
	{
		*video++ = *string++;
		*video++ = color;
	}
}

int main() {
	printString("why am i doing this to myself.");
	__builtin_unreachable();
}
