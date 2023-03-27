#ifndef PROTOTYPES
#define PROTOTYPES

int _printf(const char *format, ...);
void put_char(char character);
int get_base_length(int decimal, int base);
int get_string_length(char *string);
char *convert_decimal_to_base_string(int decimal, int len, int base, char *str);
char *convert_address_to_string(void *ptr);
void add_null_terminator(char *string, int length);
char *reverse_string(char *string);
char *rotate13_string(char *string);

int *adjust_flags(int *flags, char specifier);
int *assign_flag(int *flags, char flag);

#endif
