#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include <windows.h>

unsigned long binaryToDecimal(char *binary, int length);
void textToBinary(char *text, int textLength, char *binary, int binaryLength);
void decimalToBinary(int decimal, char *octet);

int main(void)
{
    printf(" ___  ___  ___  _____ _   _   ___  ___ _____ _   _ _   _ \n");
    printf(" |  \\/  | / _ \\|_   _| \\ | |  |  \\/  ||  ___| \\ | | | | |\n");
    printf(" | .  . |/ /_\\ \\ | | |  \\| |  | .  . || |__ |  \\| | | | |\n");
    printf(" | |\\/| ||  _  | | | | . ` |  | |\\/| ||  __|| . ` | | | |\n");
    printf(" | |  | || | | |_| |_| |\\  |  | |  | || |___| |\\  | |_| |\n");
    printf(" \\_|  |_/\\_| |_/\\___/\\_| \\_/  \\_|  |_/\\____/\\_| \\_/\\___/ \n");
    printf(" Binary-Translator v1.0 // Integrated Functions        | ");
    printf("\n ______________________________________________________|\n |");
    printf("\n");
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("|B|i|n|-|t|r|a|n|s|B|E|T|A|\n");
    printf("|by: Harold Edsel Cabaluna|\n");
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    system("COLOR F");
	char text[100];
	char input;
    char *binary;
    int textLength, binaryLength;
    printf(" |\n");
    printf(" |\n");
    printf("[$]--> Bin@Trans~#: ");
    gets(input);
    scanf("%100[^\n]s", text);
	textLength = strlen(text);
    binaryLength = textLength * 9;      // 8 binary digits + 1 space separator
    binary = malloc(binaryLength + 1);  // + 1 null terminator
    if(binary == NULL)
        exit(1);

    textToBinary(text, textLength, binary, binaryLength);
    printf("\nYOUR BINARY:\n\n%s\n", binary);

   free(binary);
   getch();
   return 0;
}

void textToBinary(char *text, int textLength, char *binary, int binaryLength)
{
    char *octet = malloc(9);
    if(octet == NULL)
        exit(1);
    while(*text)
    {
        decimalToBinary(*text, octet);
        while(*octet)
            *binary++ = *octet++;
        *binary++ = ' ';
        ++text;
        octet -= 8;
    }
    *binary = '\0';
    binary -= binaryLength;
    free(octet);
}

void decimalToBinary(int decimal, char *octet)
{
	octet += 8;
	*octet = '\0';
	if(decimal == 0)
	{
		octet -= 8;
		octet = "00000000";
	}
	else
	{
		while(decimal > 0)
		{
			--octet;
			*octet = decimal % 2 + '0';
			decimal = decimal / 2;
		}
	}
    while(strlen(octet) < 8)
    {
        --octet;
        *octet = '0';
    }
}
