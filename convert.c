#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void div_Convert(uint32_t n, int base, char* out)
{
	char tempBuffer[50];
	int pos = 0;

	if (n == 0) {
		printf("0\n");
		return;
	}

	while (n > 0)
	{
		int remainder = n % base;
		n = n / base;

		if (remainder < 10)
			tempBuffer[pos++] = '0' + remainder;
		else
			tempBuffer[pos++] = 'A' + (remainder - 10);
	}
	tempBuffer[pos] = '\0';
	out[0] = '\0';
	for (int x = (int)strlen(tempBuffer) - 1; x >= 0; x--)
	{
		char temp[2] = { tempBuffer[x], '\0' };
		strcat_s(out, 50, temp);
	}
}

void sub_Convert(uint32_t n, int base, char* out) {
	char tempBuffer[50];
	int pos = 0;

	if (n == 0) {
		out[0] = '0';
		out[1] = '\0';
		return;
	}

	while (n > 0) {
		int digit = n % base;   
		n = n - digit;          
		n = n / base;           

		if (digit < 10)
			tempBuffer[pos++] = '0' + digit;
		else
			tempBuffer[pos++] = 'A' + (digit - 10);
	}

	for (int i = 0; i < pos; i++)
		out[i] = tempBuffer[pos - i - 1];
	out[pos] = '\0';
}

void print_tables(uint32_t n) {
	char bin[65], oct[65], hex[65];
	printf("\n");
	// Original
	div_Convert(n, 2, bin);
	div_Convert(n, 8, oct);
	div_Convert(n, 16, hex);
	printf("Original: %d Binary=%s Octal=%s Decimal=%u Hex=%s\n", n, bin, oct, n, hex);

	// Left Shift by 3
	uint32_t shifted = n << 3;
	div_Convert(shifted, 2, bin);
	div_Convert(shifted, 8, oct);
	div_Convert(shifted, 16, hex);
	printf("Left Shift by 3: Binary=%s Octal=%s Decimal=%u Hex=%s\n", bin, oct, shifted, hex);

	// AND with 0xFF
	uint32_t anded = n & 0xFF;
	div_Convert(anded, 2, bin);
	div_Convert(anded, 8, oct);
	div_Convert(anded, 16, hex);
	printf("AND with 0xFF: Binary=%s Octal=%s Decimal=%u Hex=%s\n", bin, oct, anded, hex);
}