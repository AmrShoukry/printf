#ifndef PROTOTYPES
#define PROTOTYPES

int _printf(const char *format, ...);
void put_char(char character);
int get_base_length(int decimal, int base);
int get_string_length(char *string);
char *convert_decimal_to_binary_string(int decimal, int length);
char *convert_decimal_to_octal_string(int decimal, int length);
char *convert_deciaml_to_hexa_string(int decimal, int length);
char *convert_address_to_string(void *ptr);
char *reverse_string(char *string);
char *rotate13_string(char *string);

#endif
