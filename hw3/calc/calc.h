#ifndef BIG_NUM_H
#define BIG_NUM_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_DIGITS 250
#define MAX_SIZE (MAX_DIGITS + 1)

#define ERR_OK              0
#define ERR_LENGTH          -1
#define ERR_DIGIT           -2
#define ERR_BOUNDS          -3
#define ERR_INPUT           -4
#define ERR_OPCODE          -5

#define ZERO_VALUE          { 1, '0' }
#define ONE_VALUE           { 1, '1' }


int read_num(unsigned char[]);

int print_num(unsigned char[]);

int op_plus(unsigned char num1[],
            unsigned char num2[],
            unsigned char result[]);

int op_minus(unsigned char num1[],
             unsigned char num2[],
             unsigned char result[]);

int op_mult(unsigned char num1[],
            unsigned char num2[],
            unsigned char result[]);

int op_div(unsigned char num1[],
           unsigned char num2[],
           unsigned char result[]);

int op_fact(unsigned char num1[], unsigned char result[]);

#ifdef __cplusplus
}
#endif

#endif  /* BIG_NUM_H */
