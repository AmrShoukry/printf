#ifndef PROTOTYPES
#define PROTOTYPES

int _printf(const char *format, ...);
void put_char(char character);
int get_base_length(int decimal, int base);
int get_string_length(char *string);
char *convert_decimal_to_base_string(int decimal, int len, int base, char *str);
char *convert_address_to_string(void *ptr);
char *convert_char_to_string(char character);
void add_null_terminator(char *string, int length);
char *reverse_string(char *string);
char *rotate13_string(char *string);

void adjust_flags(int *flags, char specifier);
void assign_flag(int *flags, char flag);
void fill_length(char character, int length);

int specifier_s(int *flags, char *string);

int percentage(int *percentage_ptr, char c);

#endif
