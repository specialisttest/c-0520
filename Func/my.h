#ifndef _MY_H_
#define _MY_H_

#define HELLO_STR "Hello"

void say_hello();
void say_hello_w_name(const char* name);
void say_hello_w_name_age(const char* name, int age);

//double my_average(int a, int b);
double my_average(int, int);

double averagem(int m_size, int m[]);
double averagen(int n, ...);

double mediana(int n, ...);

double bank_round(double);

int factorial(int);

#endif