#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    /*
    char c = 'A';
    char *str = "Hello, 42!";
    void *ptr = &str;
    int num = -12345;
    unsigned int unum = 12345;
    int hex_num = 255;

    printf("=== Testing ft_printf ===\n\n");

    // Test %c
    printf("printf   -> Char: %c\n", c);
    ft_printf("ft_printf -> Char: %c\n\n", c);

    // Test %s
    printf("printf   -> String: %s\n", str);
    ft_printf("ft_printf -> String: %s\n\n", str);

    // Test %p
    printf("printf   -> Pointer: %p\n", ptr);
    ft_printf("ft_printf -> Pointer: %p\n\n", ptr);

    // Test %d y %i
    printf("printf   -> Decimal (%%d): %d\n", num);
    ft_printf("ft_printf -> Decimal (%%d): %d\n\n", num);

    printf("printf   -> Integer (%%i): %i\n", num);
    ft_printf("ft_printf -> Integer (%%i): %i\n\n", num);

    // Test %u
    printf("printf   -> Unsigned (%%u): %u\n", unum);
    ft_printf("ft_printf -> Unsigned (%%u): %u\n\n", unum);

    // Test %x
    printf("printf   -> Hexadecimal (%%x): %x\n", hex_num);
    ft_printf("ft_printf -> Hexadecimal (%%x): %x\n\n", hex_num);

    // Test %X
    printf("printf   -> Hexadecimal Upper (%%X): %X\n", hex_num);
    ft_printf("ft_printf -> Hexadecimal Upper (%%X): %X\n\n", hex_num);

    // Test %%
    printf("printf   -> Percent: %%\n");
    ft_printf("ft_printf -> Percent: %%\n\n");
    */

    //ft_printf(NULL);
    //ft_printf("%x",-10);
    
    int ret_ft, ret_orig;

	printf("\n=========== SIMPLE CONVERSION CHECKS ===========\n");

	ret_ft = ft_printf("ft_printf: char = [%c]\n", 'A');
	ret_orig = printf("printf:    char = [%c]\n", 'A');

	ret_ft = ft_printf("ft_printf: str  = [%s]\n", "Hola mundo");
	ret_orig = printf("printf:    str  = [%s]\n", "Hola mundo");

	ret_ft = ft_printf("ft_printf: ptr  = [%p]\n", (void *)0x1234);
	ret_orig = printf("printf:    ptr  = [%p]\n", (void *)0x1234);

	ret_ft = ft_printf("ft_printf: int  = [%d]\n", 42);
	ret_orig = printf("printf:    int  = [%d]\n", 42);

	ret_ft = ft_printf("ft_printf: int  = [%i]\n", -42);
	ret_orig = printf("printf:    int  = [%i]\n", -42);

	ret_ft = ft_printf("ft_printf: uint = [%u]\n", 42000);
	ret_orig = printf("printf:    uint = [%u]\n", 42000);

	ret_ft = ft_printf("ft_printf: hex  = [%x]\n", 255);
	ret_orig = printf("printf:    hex  = [%x]\n", 255);

	ret_ft = ft_printf("ft_printf: HEX  = [%X]\n", 255);
	ret_orig = printf("printf:    HEX  = [%X]\n", 255);

	ret_ft = ft_printf("ft_printf: perc = [%%]\n");
	ret_orig = printf("printf:    perc = [%%]\n");

	// -----------------------------------------------

	printf("\n=========== SPECIAL CASES ===========\n");

	ret_ft = ft_printf("ft_printf: zero     = [%d]\n", 0);
	ret_orig = printf("printf:    zero     = [%d]\n", 0);

	ret_ft = ft_printf("ft_printf: INT_MIN  = [%d]\n", INT_MIN);
	ret_orig = printf("printf:    INT_MIN  = [%d]\n", INT_MIN);

	ret_ft = ft_printf("ft_printf: empty str = [%s]\n", "");
	ret_orig = printf("printf:    empty str = [%s]\n", "");

	ret_ft = ft_printf("ft_printf: NULL ptr = [%p]\n", NULL);
	ret_orig = printf("printf:    NULL ptr = [%p]\n", NULL);

	// -----------------------------------------------

	printf("\n=========== MULTIPLE ARGUMENTS ===========\n");

	ret_ft = ft_printf("ft_printf: %s tiene %d años y %u puntos\n", "Alvin", 25, 999);
	ret_orig = printf("printf:    %s tiene %d años y %u puntos\n", "Alvin", 25, 999);

	// -----------------------------------------------

	printf("\n=========== CONVERSIONES EN MEDIO DE TEXTO ===========\n");

	ret_ft = ft_printf("ft_printf: Tu nota es %d/100\n", 85);
	ret_orig = printf("printf:    Tu nota es %d/100\n", 85);

	ret_ft = ft_printf("ft_printf: El número mágico es %x y en decimal es %d\n", 255, 255);
	ret_orig = printf("printf:    El número mágico es %x y en decimal es %d\n", 255, 255);

    return (0);
}
