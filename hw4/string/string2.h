#ifndef STRING2_H
#define STRING2_H

char *itoa(int num);
char *rem_spaces(char *str);
char *strcat2(char **dest, char *src);
char *strcpy2(char *src);
char *append(char ** dest, char c);
char **split(char *input);

#endif  // STRING2_H
