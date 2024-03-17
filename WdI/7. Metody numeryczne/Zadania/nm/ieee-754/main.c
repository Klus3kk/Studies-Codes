#define _CRT_SECURE_NO_WARNINGS

/* tested VSC 2015, GCC 6.4 */

#include <stdio.h>
#include <math.h>
union {
	float floatValue;
	unsigned char floatBytes[sizeof(float)];
	/* double doubleValue;
	   unsigned char doubleBytes[sizeof(double)]; */
} fpConverter;
char floatChars[4 * 8 + 1]; /* sizeof(float) * bits_in_byte + NUL */
int main() {
    int Power = 0;
	for (int i = 0;i < sizeof(floatChars) - 1;++i)
		floatChars[i] = '0';
	printf("Enter number:");
	if (scanf("%f", &fpConverter.floatValue) != 1) {
		printf("\nWrong number\n");
		return -1;
	}
	printf("================================\n");
	for (int i = sizeof(float) - 1;i >= 0;--i)
		printf("0x%02X ", fpConverter.floatBytes[i]);
	printf("\n================================\n");
    /* Sign = 0, Exp = 0, Man = 0 -> +0,
	   Sign = 1, Exp = 0, Man = 0 -> -0,
	   Sign = 0, Exp = FF, Man = 0 -> +infinity,
	   Sign = 1, Exp = FF, Man = 0 -> -infinity,
	   Sign = ?, Exp = FF, Man = * -> NaN */
	if ( (fpConverter.floatBytes[3]==0xFF) && (fpConverter.floatBytes[2] == 0x80) && (fpConverter.floatBytes[1] == 0x00) && (fpConverter.floatBytes[0] == 0x00)) { 
		printf("-Infinity\n");
		return -1;
	}
	else if ((fpConverter.floatBytes[3]==0x7F) && (fpConverter.floatBytes[2] == 0x80) && (fpConverter.floatBytes[1] == 0x00) && (fpConverter.floatBytes[0] == 0x00)) {
		printf("+Infinity\n");
		return -1;
	}
	printf("%g\n", fpConverter.floatValue);
	if(fpConverter.floatValue == 0.0f) {
		printf("\nZERO\n");
		return 0;
	}
	printf("========= sign =================\n");
	{
		if (fpConverter.floatValue < 0.0f) {
			fpConverter.floatValue = -fpConverter.floatValue;
			floatChars[0] = '1';
			printf("1\n");
		}
		printf("0\n");
	}
	printf("======== number so far =========\n%s\n\n", floatChars);
	printf("=========== power ==============\n");
	{
		float Temp = fpConverter.floatValue;
		int Offset;
		while (Temp >= 2.0f) {
			Power++;
			Temp /= 2.0f;
			printf("[%d,%15f]\n", Power, Temp);
		}
		while (Temp < 1.0f) {
			Power--;
			Temp *= 2.0f;
			printf("[%d,%15f]\n", Power, Temp);
		}
		Temp -= 1.0f;
		/* float power = 8 bits */
		printf("Exp = %d\n", Power);
		Power += 127;
		printf("Exp + 127 = %d\n", Power);
		{
			int Temp = Power;
			Offset = 8;
			while (Temp > 0) {
				floatChars[Offset--] = '0' + (Temp % 2);
				Temp /= 2;
			}
		}
		printf("======== number so far =========\n%s\n\n", floatChars);
		printf("============== remainder ================\n");
		Offset = 9;
		while (fmod(Temp, 1.0f) > 0.0f) {
			printf("%12f x 2 =", Temp);
			Temp *= 2.0f;
			printf("%12f\t", Temp);
			if (Temp >= 1.0f) {
				Temp -= 1.0f;
				printf("| 1\n");
				floatChars[Offset++] = '1';
			} else {
				printf("| 0\n");
				floatChars[Offset++] = '0';
			}
		}
		printf("\n");
	}
	printf("============ number ============\n%s\n\n", floatChars);
	{
		for (int i = 0;i < 8;++i) {
			if (i % 2 == 0)
				printf("0x");
			int num = (floatChars[i * 4] - '0') * 8;
			num += (floatChars[i * 4 + 1] - '0') * 4;
			num += (floatChars[i * 4 + 2] - '0') * 2;
			num += (floatChars[i * 4 + 3] - '0');
			if (num < 10)
				printf("%c",num + '0');
			else
				printf("%c", (num - 10) + 'A');
			if (i % 2 == 1)
				printf("%c", ' ');
		}
	}
	printf("\n---------------------------------\n");
	return 0;
}
