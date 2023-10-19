#include "main.h"
/************************* PRINT CHAR *************************/

/**
 * print_char - this function prints a charater
 * @types: it gives a list of arguments
 * @buffer: The buffer array to handle printing .....
 * @flags:  it  Calculates active flags
 * @width: handles Width
 * @precision: handles precision specification.
 * @size: Size specifiers .
 * Return: Number of characters printed .
 */
int print_char(va_list types, char buffer[],
	int flg, int wth, int prec, int size)
{
	char i = va_arg(types, int);

	return (handle_write_char(i, buffer, flg, wth, prec, size));
}
/************************* PRINT OUT A STRING *************************/
/**
 * print_string - it prints a string .
 * @types: it up list a of arguments
 * @buffer: handles a buffer array to handle print
 * @flags:  it calculates active flags
 * @width: it gets width.
 * @precision: it handles precision specification.
 * @size: it specifies size specifier
 * Return: it returns number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flg, int width, int prec, int size)
{
	int l = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}

	while (str[l] != '\0')
		l++;

	if (prec >= 0 && prec < l)
		l = prec;

	if (width > l)
	{
		if (flg & F_MINUS)
		{
			write(1, &str[0], l);
			for (i = width - l; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - l; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], l);
			return (width);
		}
	}

	return (write(1, str, l));
}
/*************************IT PRINTS A PERCENT SIGN *************************/
/**
 * print_percent - IT prints a percent sign
 * @types: it lists arguments
 * @buffer: buffer array to handle print ...
 * @flags: it cCalculates active flags...
 * @width: gets width.   .
 * @precision: it gets precision specification
 * @size: handles size specifier
 * Return: it prints number of characters printed
 */
int print_percent(va_list types, char buffer[],
	int flg, int width, int prec, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* THIS FUNCTION PRINTs INT *************************/
/**
 * print_int - it prints int
 * @types: it lists a of arguments
 * @buffer: handles buffer array to handle print
 * @flags: it cCalculates active flags .
 * @width:  it getsget width.
 * @precision: it handles precision specification
 * @size: handles size specifier
 * Return: handles no of characters printed
 */
int print_int(va_list types, char buffer[],
	int flg, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int number;

	v = convert_size_number(v, size);

	if (v == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)v;

	if (v < 0)
	{
		number = (unsigned long int)((-1) * v);
		is_negative = 1;
	}

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flg, width, prec, size));
}

/************************* THIS FUNTCION PRINTS BINARY *************************/
/**
 * print_binary - it prints an unsigned number ...
 * @types: it lists arguments
 * @buffer:  handles buffer array to handle print
 * @flags:  it calculates active flags.
 * @width: gets the width.
 * @precision: the precision specification ...
 * @size: gives size specifier
 * Return: prints no of characters printed.
 */
int print_binary(va_list types, char buffer[],
	int flg, int width, int prec, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int cnt;

	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, cnt = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (cnt);
}
