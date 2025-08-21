#pragma once


#define PI 3.14159265

//random number generator
#define MYRAND_MUL    1103515245UL
#define MYRAND_ADD    12345UL
#define MYRAND_MAX    0x7fffffffUL

#define BUFFER_OFFSET(i) ((void*)(i))

// standart type definition
typedef  unsigned char        ui8;
typedef  unsigned short       ui16;
typedef  unsigned long        ui32;
typedef  unsigned long long   ui64;

typedef  signed char       si8;
typedef  signed short      si16;
typedef  signed long       si32;
typedef  signed long long  si64;