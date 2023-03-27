#ifndef PROTOTYPES
#define PROTOTYPES

int _printf(const char *format, ...);
void put_char(char character);
int get_binary_length(int decimal);
int get_octal_length(int decimal);
int get_decimal_length(int decimal);
int get_hexa_length(int decimal);
int get_string_length(char *string);
char *convert_decimal_to_binary(int decimal, int length);
char *convert_decimal_to_octal(int decimal, int length);
char *convert_deciaml_to_hexa(int decimal, int length);
char *convert_address_to_string(void *ptr);
char *reverse_string(char *string);
char *rotate13_string(char *string);

#endif
