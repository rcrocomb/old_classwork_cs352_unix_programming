# 1 "arraylist.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "arraylist.c"
# 1 "/usr/include/string.h" 1 3 4
# 26 "/usr/include/string.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 295 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 296 "/usr/include/features.h" 2 3 4
# 318 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4
# 319 "/usr/include/features.h" 2 3 4
# 27 "/usr/include/string.h" 2 3 4






# 1 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 1 3 4
# 213 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 3 4
typedef unsigned int size_t;
# 34 "/usr/include/string.h" 2 3 4




extern void *memcpy (void *__restrict __dest,
                     __const void *__restrict __src, size_t __n) ;


extern void *memmove (void *__dest, __const void *__src, size_t __n)
     ;






extern void *memccpy (void *__restrict __dest, __const void *__restrict __src,
                      int __c, size_t __n)
     ;





extern void *memset (void *__s, int __c, size_t __n) ;


extern int memcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__pure__));


extern void *memchr (__const void *__s, int __c, size_t __n)
      __attribute__ ((__pure__));

# 80 "/usr/include/string.h" 3 4


extern char *strcpy (char *__restrict __dest, __const char *__restrict __src)
     ;

extern char *strncpy (char *__restrict __dest,
                      __const char *__restrict __src, size_t __n) ;


extern char *strcat (char *__restrict __dest, __const char *__restrict __src)
     ;

extern char *strncat (char *__restrict __dest, __const char *__restrict __src,
                      size_t __n) ;


extern int strcmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__pure__));

extern int strncmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__pure__));


extern int strcoll (__const char *__s1, __const char *__s2)
     __attribute__ ((__pure__));

extern size_t strxfrm (char *__restrict __dest,
                       __const char *__restrict __src, size_t __n) ;

# 126 "/usr/include/string.h" 3 4
extern char *strdup (__const char *__s) __attribute__ ((__malloc__));
# 160 "/usr/include/string.h" 3 4


extern char *strchr (__const char *__s, int __c) __attribute__ ((__pure__));

extern char *strrchr (__const char *__s, int __c) __attribute__ ((__pure__));











extern size_t strcspn (__const char *__s, __const char *__reject)
     __attribute__ ((__pure__));


extern size_t strspn (__const char *__s, __const char *__accept)
     __attribute__ ((__pure__));

extern char *strpbrk (__const char *__s, __const char *__accept)
     __attribute__ ((__pure__));

extern char *strstr (__const char *__haystack, __const char *__needle)
     __attribute__ ((__pure__));



extern char *strtok (char *__restrict __s, __const char *__restrict __delim)
     ;




extern char *__strtok_r (char *__restrict __s,
                         __const char *__restrict __delim,
                         char **__restrict __save_ptr) ;

extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim,
                       char **__restrict __save_ptr) ;
# 228 "/usr/include/string.h" 3 4


extern size_t strlen (__const char *__s) __attribute__ ((__pure__));

# 241 "/usr/include/string.h" 3 4


extern char *strerror (int __errnum) ;




extern char *strerror_r (int __errnum, char *__buf, size_t __buflen) ;




extern void __bzero (void *__s, size_t __n) ;



extern void bcopy (__const void *__src, void *__dest, size_t __n) ;


extern void bzero (void *__s, size_t __n) ;


extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__pure__));


extern char *index (__const char *__s, int __c) __attribute__ ((__pure__));


extern char *rindex (__const char *__s, int __c) __attribute__ ((__pure__));



extern int ffs (int __i) __attribute__ ((__const__));
# 287 "/usr/include/string.h" 3 4
extern int strcasecmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__pure__));


extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__pure__));
# 309 "/usr/include/string.h" 3 4
extern char *strsep (char **__restrict __stringp,
                     __const char *__restrict __delim) ;
# 379 "/usr/include/string.h" 3 4

# 2 "arraylist.c" 2
# 1 "/usr/include/stdlib.h" 1 3 4
# 33 "/usr/include/stdlib.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 1 3 4
# 325 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 3 4
typedef long int wchar_t;
# 34 "/usr/include/stdlib.h" 2 3 4


# 93 "/usr/include/stdlib.h" 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;



# 137 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) ;




extern double atof (__const char *__nptr) __attribute__ ((__pure__));

extern int atoi (__const char *__nptr) __attribute__ ((__pure__));

extern long int atol (__const char *__nptr) __attribute__ ((__pure__));





__extension__ extern long long int atoll (__const char *__nptr)
     __attribute__ ((__pure__));





extern double strtod (__const char *__restrict __nptr,
                      char **__restrict __endptr) ;

# 174 "/usr/include/stdlib.h" 3 4


extern long int strtol (__const char *__restrict __nptr,
                        char **__restrict __endptr, int __base) ;

extern unsigned long int strtoul (__const char *__restrict __nptr,
                                  char **__restrict __endptr, int __base)
     ;




__extension__
extern long long int strtoq (__const char *__restrict __nptr,
                             char **__restrict __endptr, int __base) ;

__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
                                       char **__restrict __endptr, int __base)
     ;





__extension__
extern long long int strtoll (__const char *__restrict __nptr,
                              char **__restrict __endptr, int __base) ;

__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
                                        char **__restrict __endptr, int __base)
     ;

# 264 "/usr/include/stdlib.h" 3 4
extern double __strtod_internal (__const char *__restrict __nptr,
                                 char **__restrict __endptr, int __group)
     ;
extern float __strtof_internal (__const char *__restrict __nptr,
                                char **__restrict __endptr, int __group)
     ;
extern long double __strtold_internal (__const char *__restrict __nptr,
                                       char **__restrict __endptr,
                                       int __group) ;

extern long int __strtol_internal (__const char *__restrict __nptr,
                                   char **__restrict __endptr,
                                   int __base, int __group) ;



extern unsigned long int __strtoul_internal (__const char *__restrict __nptr,
                                             char **__restrict __endptr,
                                             int __base, int __group) ;




__extension__
extern long long int __strtoll_internal (__const char *__restrict __nptr,
                                         char **__restrict __endptr,
                                         int __base, int __group) ;



__extension__
extern unsigned long long int __strtoull_internal (__const char *
                                                   __restrict __nptr,
                                                   char **__restrict __endptr,
                                                   int __base, int __group)
     ;
# 408 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) ;


extern long int a64l (__const char *__s) __attribute__ ((__pure__));




# 1 "/usr/include/sys/types.h" 1 3 4
# 29 "/usr/include/sys/types.h" 3 4


# 1 "/usr/include/bits/types.h" 1 3 4
# 28 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4


# 1 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 1 3 4
# 32 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;




__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;







__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
# 129 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 130 "/usr/include/bits/types.h" 2 3 4






__extension__ typedef unsigned long long int __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef unsigned long long int __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef long long int __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct { int __val[2]; } __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef unsigned long long int __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;

__extension__ typedef int __daddr_t;
__extension__ typedef long int __swblk_t;
__extension__ typedef int __key_t;


__extension__ typedef int __clockid_t;


__extension__ typedef int __timer_t;


__extension__ typedef long int __blksize_t;




__extension__ typedef long int __blkcnt_t;
__extension__ typedef long long int __blkcnt64_t;


__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef unsigned long long int __fsblkcnt64_t;


__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef unsigned long long int __fsfilcnt64_t;

__extension__ typedef int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


__extension__ typedef int __intptr_t;


__extension__ typedef unsigned int __socklen_t;
# 32 "/usr/include/sys/types.h" 2 3 4



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
# 62 "/usr/include/sys/types.h" 3 4
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
# 100 "/usr/include/sys/types.h" 3 4
typedef __pid_t pid_t;




typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 133 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 74 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 134 "/usr/include/sys/types.h" 2 3 4
# 147 "/usr/include/sys/types.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 1 3 4
# 148 "/usr/include/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 191 "/usr/include/sys/types.h" 3 4
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
# 213 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/endian.h" 1 3 4
# 38 "/usr/include/endian.h" 2 3 4
# 214 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/select.h" 1 3 4
# 31 "/usr/include/sys/select.h" 3 4
# 1 "/usr/include/bits/select.h" 1 3 4
# 32 "/usr/include/sys/select.h" 2 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 23 "/usr/include/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 35 "/usr/include/sys/select.h" 2 3 4



typedef __sigset_t sigset_t;





# 1 "/usr/include/time.h" 1 3 4
# 118 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
# 45 "/usr/include/sys/select.h" 2 3 4

# 1 "/usr/include/bits/time.h" 1 3 4
# 69 "/usr/include/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 47 "/usr/include/sys/select.h" 2 3 4


typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 67 "/usr/include/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 99 "/usr/include/sys/select.h" 3 4

# 109 "/usr/include/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
                   fd_set *__restrict __writefds,
                   fd_set *__restrict __exceptfds,
                   struct timeval *__restrict __timeout);
# 128 "/usr/include/sys/select.h" 3 4

# 217 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/sysmacros.h" 1 3 4
# 220 "/usr/include/sys/types.h" 2 3 4
# 231 "/usr/include/sys/types.h" 3 4
typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 266 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/bits/sched.h" 1 3 4
# 83 "/usr/include/bits/sched.h" 3 4
struct __sched_param
  {
    int __sched_priority;
  };
# 24 "/usr/include/bits/pthreadtypes.h" 2 3 4

typedef int __atomic_lock_t;


struct _pthread_fastlock
{
  long int __status;
  __atomic_lock_t __spinlock;

};



typedef struct _pthread_descr_struct *_pthread_descr;





typedef struct __pthread_attr_s
{
  int __detachstate;
  int __schedpolicy;
  struct __sched_param __schedparam;
  int __inheritsched;
  int __scope;
  size_t __guardsize;
  int __stackaddr_set;
  void *__stackaddr;
  size_t __stacksize;
} pthread_attr_t;





__extension__ typedef long long __pthread_cond_align_t;




typedef struct
{
  struct _pthread_fastlock __c_lock;
  _pthread_descr __c_waiting;
  char __padding[48 - sizeof (struct _pthread_fastlock)
                 - sizeof (_pthread_descr) - sizeof (__pthread_cond_align_t)];
  __pthread_cond_align_t __align;
} pthread_cond_t;



typedef struct
{
  int __dummy;
} pthread_condattr_t;


typedef unsigned int pthread_key_t;





typedef struct
{
  int __m_reserved;
  int __m_count;
  _pthread_descr __m_owner;
  int __m_kind;
  struct _pthread_fastlock __m_lock;
} pthread_mutex_t;



typedef struct
{
  int __mutexkind;
} pthread_mutexattr_t;



typedef int pthread_once_t;
# 152 "/usr/include/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;
# 267 "/usr/include/sys/types.h" 2 3 4



# 417 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) ;


extern void srandom (unsigned int __seed) ;





extern char *initstate (unsigned int __seed, char *__statebuf,
                        size_t __statelen) ;



extern char *setstate (char *__statebuf) ;







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
                     int32_t *__restrict __result) ;

extern int srandom_r (unsigned int __seed, struct random_data *__buf) ;

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
                        size_t __statelen,
                        struct random_data *__restrict __buf) ;

extern int setstate_r (char *__restrict __statebuf,
                       struct random_data *__restrict __buf) ;






extern int rand (void) ;

extern void srand (unsigned int __seed) ;




extern int rand_r (unsigned int *__seed) ;







extern double drand48 (void) ;
extern double erand48 (unsigned short int __xsubi[3]) ;


extern long int lrand48 (void) ;
extern long int nrand48 (unsigned short int __xsubi[3]) ;


extern long int mrand48 (void) ;
extern long int jrand48 (unsigned short int __xsubi[3]) ;


extern void srand48 (long int __seedval) ;
extern unsigned short int *seed48 (unsigned short int __seed16v[3]) ;
extern void lcong48 (unsigned short int __param[7]) ;





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
                      double *__restrict __result) ;
extern int erand48_r (unsigned short int __xsubi[3],
                      struct drand48_data *__restrict __buffer,
                      double *__restrict __result) ;


extern int lrand48_r (struct drand48_data *__restrict __buffer,
                      long int *__restrict __result) ;
extern int nrand48_r (unsigned short int __xsubi[3],
                      struct drand48_data *__restrict __buffer,
                      long int *__restrict __result) ;


extern int mrand48_r (struct drand48_data *__restrict __buffer,
                      long int *__restrict __result) ;
extern int jrand48_r (unsigned short int __xsubi[3],
                      struct drand48_data *__restrict __buffer,
                      long int *__restrict __result) ;


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     ;

extern int seed48_r (unsigned short int __seed16v[3],
                     struct drand48_data *__buffer) ;

extern int lcong48_r (unsigned short int __param[7],
                      struct drand48_data *__buffer) ;









extern void *malloc (size_t __size) __attribute__ ((__malloc__));

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__malloc__));







extern void *realloc (void *__ptr, size_t __size) __attribute__ ((__malloc__));

extern void free (void *__ptr) ;




extern void cfree (void *__ptr) ;



# 1 "/usr/include/alloca.h" 1 3 4
# 25 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 1 3 4
# 26 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size) ;






# 579 "/usr/include/stdlib.h" 2 3 4




extern void *valloc (size_t __size) __attribute__ ((__malloc__));
# 592 "/usr/include/stdlib.h" 3 4


extern void abort (void) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) ;





extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     ;






extern void exit (int __status) __attribute__ ((__noreturn__));

# 624 "/usr/include/stdlib.h" 3 4


extern char *getenv (__const char *__name) ;




extern char *__secure_getenv (__const char *__name) ;





extern int putenv (char *__string) ;





extern int setenv (__const char *__name, __const char *__value, int __replace)
     ;


extern int unsetenv (__const char *__name) ;






extern int clearenv (void) ;
# 663 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) ;
# 674 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template);
# 693 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) ;








extern int system (__const char *__command);

# 720 "/usr/include/stdlib.h" 3 4
extern char *realpath (__const char *__restrict __name,
                       char *__restrict __resolved) ;






typedef int (*__compar_fn_t) (__const void *, __const void *);









extern void *bsearch (__const void *__key, __const void *__base,
                      size_t __nmemb, size_t __size, __compar_fn_t __compar);



extern void qsort (void *__base, size_t __nmemb, size_t __size,
                   __compar_fn_t __compar);



extern int abs (int __x) __attribute__ ((__const__));
extern long int labs (long int __x) __attribute__ ((__const__));












extern div_t div (int __numer, int __denom)
     __attribute__ ((__const__));
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__const__));

# 784 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign) ;




extern char *gcvt (double __value, int __ndigit, char *__buf) ;




extern char *qecvt (long double __value, int __ndigit,
                    int *__restrict __decpt, int *__restrict __sign) ;
extern char *qfcvt (long double __value, int __ndigit,
                    int *__restrict __decpt, int *__restrict __sign) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign, char *__restrict __buf,
                   size_t __len) ;
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign, char *__restrict __buf,
                   size_t __len) ;

extern int qecvt_r (long double __value, int __ndigit,
                    int *__restrict __decpt, int *__restrict __sign,
                    char *__restrict __buf, size_t __len) ;
extern int qfcvt_r (long double __value, int __ndigit,
                    int *__restrict __decpt, int *__restrict __sign,
                    char *__restrict __buf, size_t __len) ;







extern int mblen (__const char *__s, size_t __n) ;


extern int mbtowc (wchar_t *__restrict __pwc,
                   __const char *__restrict __s, size_t __n) ;


extern int wctomb (char *__s, wchar_t __wchar) ;



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
                        __const char *__restrict __s, size_t __n) ;

extern size_t wcstombs (char *__restrict __s,
                        __const wchar_t *__restrict __pwcs, size_t __n)
     ;








extern int rpmatch (__const char *__response) ;
# 916 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem) ;






# 3 "arraylist.c" 2
# 1 "/usr/include/stdio.h" 1 3 4
# 30 "/usr/include/stdio.h" 3 4




# 1 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 1 3 4
# 35 "/usr/include/stdio.h" 2 3 4
# 44 "/usr/include/stdio.h" 3 4


typedef struct _IO_FILE FILE;





# 62 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 72 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 32 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 14 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 1 3 4
# 354 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 3 4
typedef unsigned int wint_t;
# 15 "/usr/include/_G_config.h" 2 3 4
# 24 "/usr/include/_G_config.h" 3 4
# 1 "/usr/include/wchar.h" 1 3 4
# 48 "/usr/include/wchar.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 1 3 4
# 49 "/usr/include/wchar.h" 2 3 4

# 1 "/usr/include/bits/wchar.h" 1 3 4
# 51 "/usr/include/wchar.h" 2 3 4
# 76 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 25 "/usr/include/_G_config.h" 2 3 4

typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 44 "/usr/include/_G_config.h" 3 4
# 1 "/usr/include/gconv.h" 1 3 4
# 28 "/usr/include/gconv.h" 3 4
# 1 "/usr/include/wchar.h" 1 3 4
# 48 "/usr/include/wchar.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 1 3 4
# 49 "/usr/include/wchar.h" 2 3 4
# 29 "/usr/include/gconv.h" 2 3 4


# 1 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stddef.h" 1 3 4
# 32 "/usr/include/gconv.h" 2 3 4





enum
{
  __GCONV_OK = 0,
  __GCONV_NOCONV,
  __GCONV_NODB,
  __GCONV_NOMEM,

  __GCONV_EMPTY_INPUT,
  __GCONV_FULL_OUTPUT,
  __GCONV_ILLEGAL_INPUT,
  __GCONV_INCOMPLETE_INPUT,

  __GCONV_ILLEGAL_DESCRIPTOR,
  __GCONV_INTERNAL_ERROR
};



enum
{
  __GCONV_IS_LAST = 0x0001,
  __GCONV_IGNORE_ERRORS = 0x0002
};



struct __gconv_step;
struct __gconv_step_data;
struct __gconv_loaded_object;
struct __gconv_trans_data;



typedef int (*__gconv_fct) (struct __gconv_step *, struct __gconv_step_data *,
                            __const unsigned char **, __const unsigned char *,
                            unsigned char **, size_t *, int, int);


typedef wint_t (*__gconv_btowc_fct) (struct __gconv_step *, unsigned char);


typedef int (*__gconv_init_fct) (struct __gconv_step *);
typedef void (*__gconv_end_fct) (struct __gconv_step *);



typedef int (*__gconv_trans_fct) (struct __gconv_step *,
                                  struct __gconv_step_data *, void *,
                                  __const unsigned char *,
                                  __const unsigned char **,
                                  __const unsigned char *, unsigned char **,
                                  size_t *);


typedef int (*__gconv_trans_context_fct) (void *, __const unsigned char *,
                                          __const unsigned char *,
                                          unsigned char *, unsigned char *);


typedef int (*__gconv_trans_query_fct) (__const char *, __const char ***,
                                        size_t *);


typedef int (*__gconv_trans_init_fct) (void **, const char *);
typedef void (*__gconv_trans_end_fct) (void *);

struct __gconv_trans_data
{

  __gconv_trans_fct __trans_fct;
  __gconv_trans_context_fct __trans_context_fct;
  __gconv_trans_end_fct __trans_end_fct;
  void *__data;
  struct __gconv_trans_data *__next;
};



struct __gconv_step
{
  struct __gconv_loaded_object *__shlib_handle;
  __const char *__modname;

  int __counter;

  char *__from_name;
  char *__to_name;

  __gconv_fct __fct;
  __gconv_btowc_fct __btowc_fct;
  __gconv_init_fct __init_fct;
  __gconv_end_fct __end_fct;



  int __min_needed_from;
  int __max_needed_from;
  int __min_needed_to;
  int __max_needed_to;


  int __stateful;

  void *__data;
};



struct __gconv_step_data
{
  unsigned char *__outbuf;
  unsigned char *__outbufend;



  int __flags;



  int __invocation_counter;



  int __internal_use;

  __mbstate_t *__statep;
  __mbstate_t __state;



  struct __gconv_trans_data *__trans;
};



typedef struct __gconv_info
{
  size_t __nsteps;
  struct __gconv_step *__steps;
  __extension__ struct __gconv_step_data __data [];
} *__gconv_t;
# 45 "/usr/include/_G_config.h" 2 3 4
typedef union
{
  struct __gconv_info __cd;
  struct
  {
    struct __gconv_info __cd;
    struct __gconv_step_data __data;
  } __combined;
} _G_iconv_t;

typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));
# 33 "/usr/include/libio.h" 2 3 4
# 53 "/usr/include/libio.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stdarg.h" 1 3 4
# 43 "/usr/lib/gcc-lib/i486-linux/3.3.4/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 54 "/usr/include/libio.h" 2 3 4
# 163 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;
# 173 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 196 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 264 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 312 "/usr/include/libio.h" 3 4
  __off64_t _offset;





  void *__pad1;
  void *__pad2;

  int _mode;

  char _unused2[15 * sizeof (int) - 2 * sizeof (void *)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 351 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
                                 size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 403 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *) ;
extern int __uflow (_IO_FILE *) ;
extern int __overflow (_IO_FILE *, int) ;
extern wint_t __wunderflow (_IO_FILE *) ;
extern wint_t __wuflow (_IO_FILE *) ;
extern wint_t __woverflow (_IO_FILE *, wint_t) ;
# 433 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp) ;
extern int _IO_putc (int __c, _IO_FILE *__fp) ;
extern int _IO_feof (_IO_FILE *__fp) ;
extern int _IO_ferror (_IO_FILE *__fp) ;

extern int _IO_peekc_locked (_IO_FILE *__fp) ;





extern void _IO_flockfile (_IO_FILE *) ;
extern void _IO_funlockfile (_IO_FILE *) ;
extern int _IO_ftrylockfile (_IO_FILE *) ;
# 463 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
                        __gnuc_va_list, int *__restrict) ;
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
                         __gnuc_va_list) ;
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t) ;
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t) ;

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int) ;
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int) ;

extern void _IO_free_backup_area (_IO_FILE *) ;
# 73 "/usr/include/stdio.h" 2 3 4
# 86 "/usr/include/stdio.h" 3 4


typedef _G_fpos_t fpos_t;




# 138 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 139 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (__const char *__filename) ;

extern int rename (__const char *__old, __const char *__new) ;









extern FILE *tmpfile (void);
# 178 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) ;





extern char *tmpnam_r (char *__s) ;
# 196 "/usr/include/stdio.h" 3 4
extern char *tempnam (__const char *__dir, __const char *__pfx)
     __attribute__ ((__malloc__));








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 221 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 235 "/usr/include/stdio.h" 3 4






extern FILE *fopen (__const char *__restrict __filename,
                    __const char *__restrict __modes);




extern FILE *freopen (__const char *__restrict __filename,
                      __const char *__restrict __modes,
                      FILE *__restrict __stream);
# 262 "/usr/include/stdio.h" 3 4

# 273 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, __const char *__modes) ;
# 294 "/usr/include/stdio.h" 3 4



extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) ;



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
                    int __modes, size_t __n) ;





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
                       size_t __size) ;


extern void setlinebuf (FILE *__stream) ;








extern int fprintf (FILE *__restrict __stream,
                    __const char *__restrict __format, ...);




extern int printf (__const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
                    __const char *__restrict __format, ...) ;





extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
                     __gnuc_va_list __arg);




extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
                     __gnuc_va_list __arg) ;





extern int snprintf (char *__restrict __s, size_t __maxlen,
                     __const char *__restrict __format, ...)
     __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
                      __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 3, 0)));

# 388 "/usr/include/stdio.h" 3 4





extern int fscanf (FILE *__restrict __stream,
                   __const char *__restrict __format, ...);




extern int scanf (__const char *__restrict __format, ...);

extern int sscanf (__const char *__restrict __s,
                   __const char *__restrict __format, ...) ;

# 430 "/usr/include/stdio.h" 3 4





extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 454 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 465 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);

# 498 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream);






extern char *gets (char *__s);

# 578 "/usr/include/stdio.h" 3 4





extern int fputs (__const char *__restrict __s, FILE *__restrict __stream);





extern int puts (__const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
                     size_t __n, FILE *__restrict __stream);




extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
                      size_t __n, FILE *__restrict __s);

# 631 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream);
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
                               size_t __n, FILE *__restrict __stream);








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream);




extern void rewind (FILE *__stream);

# 686 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, __const fpos_t *__pos);
# 709 "/usr/include/stdio.h" 3 4

# 718 "/usr/include/stdio.h" 3 4


extern void clearerr (FILE *__stream) ;

extern int feof (FILE *__stream) ;

extern int ferror (FILE *__stream) ;




extern void clearerr_unlocked (FILE *__stream) ;
extern int feof_unlocked (FILE *__stream) ;
extern int ferror_unlocked (FILE *__stream) ;








extern void perror (__const char *__s);






# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 27 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern __const char *__const sys_errlist[];
# 748 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) ;




extern int fileno_unlocked (FILE *__stream) ;
# 767 "/usr/include/stdio.h" 3 4
extern FILE *popen (__const char *__command, __const char *__modes);





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) ;
# 807 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) ;



extern int ftrylockfile (FILE *__stream) ;


extern void funlockfile (FILE *__stream) ;
# 831 "/usr/include/stdio.h" 3 4

# 4 "arraylist.c" 2

# 1 "arraylist.h" 1
# 16 "arraylist.h"
# 1 "print_func.h" 1




void print_s (const void *a);
void print_i (const void *a);
void print_d (const void *a);
void print_c (const void *a);


int print_s_c (const void *a);
int print_s_i (const void *a);
int print_s_d (const void *a);
int print_s_s (const void *a);


int print_i_c (const void *a);
int print_i_i (const void *a);
int print_i_d (const void *a);
int print_i_s (const void *a);


int print_d_c (const void *a);
int print_d_i (const void *a);
int print_d_d (const void *a);
int print_d_s (const void *a);


int print_c_c (const void *a);
int print_c_i (const void *a);
int print_c_d (const void *a);
int print_c_s (const void *a);
# 17 "arraylist.h" 2
# 1 "compare_func.h" 1



int compare_char (const void *, const void *);
int compare_int (const void *, const void *);
int compare_double (const void *, const void *);
int compare_string (const void *, const void *);
# 18 "arraylist.h" 2
# 34 "arraylist.h"
typedef struct al *arraylist;

typedef struct node {
    int data_size;
    void *data;
} node;

typedef struct al {
    int size;
    int capacity;
    node **array;
    int (*comp) (const void *, const void *);
    void (*print) (const void *);
} al;


arraylist al_init (int (*comp) (const void *, const void *), void (*print) (const void *));
arraylist al_init_size (int capacity, int (*comp) (const void *, const void *),
                        void (*print) (const void *));


int al_add_at (arraylist list, int index, void *data, int size);
int al_add (arraylist list, void *data, int size);


int al_remove (arraylist list, void *data);
int al_remove_all (arraylist list, void *data);
void *al_remove_at (arraylist list, int index);
int al_remove_range (arraylist list, int begin, int end);


int al_clear (arraylist list);
int al_contains (arraylist, void *data);
int al_ensure_capacity (arraylist list, int capacity);
void *al_get (arraylist list, int index);
int al_indexof (arraylist list, void *data);
int al_isempty (arraylist list);
void *al_set (arraylist list, int index, void *data, int size);
int al_size (arraylist list);
int al_trim (arraylist list);
int al_printlist (arraylist list);
void al_destroy (arraylist *list);
# 6 "arraylist.c" 2
# 66 "arraylist.c"
typedef int (*al_compare_func)(const void *, const void *);
typedef void (*al_print_func)(const void *);






static int shift (arraylist list, int index);
static int remove_hole (arraylist list, int);
static int grow (arraylist list);
static node *make_node (void *data, int size);
static int free_node (arraylist list, int index);
static void *getdata (arraylist list, int index);
static int getdata_size (arraylist list, int index);
static node *getnode (arraylist list, int index);
# 99 "arraylist.c"
int
shift(arraylist list, int index)
{
    unsigned int i = 0;


    do { do { if(!(list)) return -10; } while(0); do { if((index)< 0 || (index) > (list)->size)return -9; } while(0); } while(0);


    if ( list->capacity == list->size )
    {
        (void)grow(list);
    }


    for ( i = list->size; i > index; --i)
    {
        list->array[i] = list->array[i - 1];
    }


    return 1;
}
# 136 "arraylist.c"
int
remove_hole (arraylist list, int index)
{

    do { do { if(!(list)) return -10; } while(0); do { if((index)< 0 || (index) > (list)->size)return -9; } while(0); } while(0);

    if (list->array[index])
    {

        (void)free_node (list, index);
        list->array[index] = ((void *)0);
    }


    memmove(list->array + index,
            list->array + index + 1,
            (list->capacity - index - 1) * sizeof(node *));

    return 1;
}
# 164 "arraylist.c"
int
grow (arraylist list)
{
    const int new_capacity = 2 * list->size;
    node **new_array;


    do { if(!(list)) return -10; } while(0);

    new_array = (node **)malloc(new_capacity * sizeof(node *));
    if(!new_array) do{printf("%s @ %d: Memory allocation failed!\n", __FUNCTION__, 174); exit(-1);}while(0);


    memcpy(new_array, list->array, list->size * sizeof(node *));


    do { if((list->array)) free((list->array)); (list->array) = ((void *)0); } while(0);
    list->array = new_array;


    list->capacity = new_capacity;

    return 1;
}
# 197 "arraylist.c"
node *
make_node (void *data, int size)
{
    node *n = ((void *)0);
    n = (node *) malloc (sizeof (node));

    n->data = (void *)malloc (size);

    memcpy (n->data, data, size);

    n->data_size = size;

    return n;
}

# 258 "arraylist.c"
int
free_node (arraylist list, int index)
{
    do { do { if(!(list)) return -10; } while(0); do { if((index)< 0 || (index) > (list)->size)return -9; } while(0); } while(0);
    node *n = getnode (list, index);

    if (n)
    {
        do { if((n->data)) free((n->data)); (n->data) = ((void *)0); } while(0);
    }

    do { if((n)) free((n)); (n) = ((void *)0); } while(0);
    return 1;
}






void *
getdata (arraylist list, int index)
{

    do { if( !(list) || ((index) < 0 || (index) > (list)->size)) return ((void *)0); } while(0);


    node *n = getnode (list, index);


    if (!n)
    {
        return ((void *)0);
    }


    return n->data;
}





int
getdata_size (arraylist list, int index)
{

    do { do { if(!(list)) return -10; } while(0); do { if((index)< 0 || (index) > (list)->size)return -9; } while(0); } while(0);







    node *n = getnode (list, index);


    if (!n)
    {
        return 0;
    }


    return n->data_size;
}
# 333 "arraylist.c"
node *
getnode (arraylist list, int index)
{
    do { if( !(list) || ((index) < 0 || (index) > (list)->size)) return ((void *)0); } while(0);

    return list->array[index];
}






arraylist
al_init
(
    al_compare_func compare,
    al_print_func print
)
{
    return al_init_size(10, compare, print);
}

arraylist
al_init_size
(
    int capacity,
    al_compare_func compare,
    al_print_func print
)
{
    arraylist list = (arraylist)malloc(sizeof(al));
    if(!list) do{printf("%s @ %d: Memory allocation failed!\n", __FUNCTION__, 365); exit(-1);}while(0);

    list->size = 0;
    list->comp = compare;
    list->print = print;

    list->capacity = capacity;
    list->array = (node **)malloc(capacity * sizeof(node *));
    if(!list->array) do{printf("%s @ %d: Memory allocation failed!\n", __FUNCTION__, 373); exit(-1);}while(0);

    return list;
}

int
al_add_at
(
    arraylist list,
    int index,
    void *data,
    int size
)
{

    do { do { if(!(list)) return -10; } while(0); do { if((index)< 0 || (index) > (list)->size)return -9; } while(0); } while(0);

    if (shift(list, index) != 1)
    {
        return 0;
    }

    list->array[index] = make_node(data, size);
    if ( !(list->array[index]) )
    {
        return 0;
    }

    ++list->size;

    return 1;
}

int
al_add
(
    arraylist list,
    void *data,
    int size
)
{
    return al_add_at(list, list->size, data, size);
}


int
al_remove
(
    arraylist list,
    void *data
)
{
    int ret = 0;
    node **iterator = list->array;

    while ((iterator - list->array) < list->size)
    {
        if ( list->comp( (*iterator)->data, data) == 0)
        {
            ret = free_node(list, iterator - list->array)
                 && remove_hole(list, iterator - list->array);

            ret = ret ? 1 : 0;
            --list->size;
            break;
        }
        ++iterator;
    }
    return ret;
}

int
al_remove_all
(
    arraylist list,
    void *data
)
{
    int ret = 0;
    do { if(!(list)) return -10; } while(0);

    while( (ret = al_remove(list, data)) );
    return ret ? 1 : 0;
}

void *
al_remove_at
(
    arraylist list,
    int index
)
{
    void * copy = ((void *)0);
    void * data = ((void *)0);
    int data_size = getdata_size(list, index);
    do { if( !(list) || ((index) < 0 || (index) > (list)->size)) return ((void *)0); } while(0);

    data = getdata(list, index);
    if (data)
    {
        copy = (char *)malloc( data_size );
        if(!copy) do{printf("%s @ %d: Memory allocation failed!\n", __FUNCTION__, 474); exit(-1);}while(0);
        memcpy(copy, data, data_size);
        (void)free_node(list, index);
    }
    return data;
}

int
al_remove_range
(
    arraylist list,
    int begin,
    int end
)
{
    int i = begin;
    int ret = 1;

    do { do { if(!(list)) return -10; } while(0); do { if((begin)< 0 || (begin) > (list)->size)return -9; } while(0); } while(0);
    do { if((end)< 0 || (end) > (list)->size)return -9; } while(0);

    if ( end < begin )
    {
        return -9;
    }

    for ( ; (i < end) && ret; ++i)
    {
        ret = ret && al_remove_at(list,i);
    }
    return ret ? 1 : 0;
}





int
al_clear
(
    arraylist list
)
{
    return al_remove_range(list, 0, list->size) ? 0 : -2;
}







int
al_contains
(
    arraylist list,
    void *data
)
{
    int ret = 0;
    unsigned int i = 0;

    do { if(!(list)) return -10; } while(0);

    if ( data )
    {
        for ( ; (i < list->size) && !ret; ++i)
        {
            if ( list->comp( (list->array[i])->data, data) == 0)
            {
                ret = 1;
            }
        }
    }
    return ret;
}

int
al_ensure_capacity
(
    arraylist list,
    int capacity
)
{
    int ret = 1;
    do { if(!(list)) return -10; } while(0);

    while ( (list->capacity < capacity) && ret)
    {
        ret = grow(list);
    }
    return ret ? 0 : -2;
}

void *
al_get
(
    arraylist list,
    int index
)
{
    do { if( !(list) || ((index) < 0 || (index) > (list)->size)) return ((void *)0); } while(0);

    return getdata(list, index);
}

int
al_indexof
(
    arraylist list,
    void *data
)
{
    unsigned int i = 0;

    do { if(!(list)) return -10; } while(0);


    for ( i = 0 ; i < list->size; ++i)
    {
        if ( list->comp((list->array[i])->data, data) == 0)
        {
            break;
        }
    }


    return (i == list->size) ? -2 : i;
}

int
al_isempty
(
    arraylist list
)
{
    do { if(!(list)) return -10; } while(0);

    return (list->size == 0) ? 1 : 0;
}





void *
al_set
(
    arraylist list,
    int index,
    void *data,
    int size
)
{
    node *old_node = ((void *)0);

    do { if( !(list) || ((index) < 0 || (index) > (list)->size)) return ((void *)0); } while(0);


    old_node = getnode(list, index);
    if ( old_node )
    {

        old_node = make_node(old_node->data, old_node->data_size);
    }



    (void) free_node(list, index);
    list->array[index] = make_node(data, size);


    return old_node;
}

int
al_size
(
    arraylist list
)
{
    do { if(!(list)) return -10; } while(0);
    return list->size;
}

int
al_trim
(
    arraylist list
)
{
    node **new_array = ((void *)0);

    do { if(!(list)) return -10; } while(0);

    new_array = (node **)malloc(list->size * sizeof(node *));
    if(!new_array) do{printf("%s @ %d: Memory allocation failed!\n", __FUNCTION__, 670); exit(-1);}while(0);


    memcpy(new_array, list->array, list->size * sizeof(node *));
    list->capacity = list->size;

    return 0;
}





int
al_printlist
(
    arraylist list
)
{
    unsigned int i = 0;

    do { if(!(list)) return -10; } while(0);

    for( i = 0; i < list->size ; ++i)
    {
        list->print( (list->array[i])->data);
    }

    return 0;
}

void
al_destroy
(
    arraylist *list
)
{
    unsigned int i = 0;

    if (!list || !(*list))
    {
        return;
    }


    for( ; i < (*list)->size; ++i)
    {
        do { if(((*list)->array[i])) free(((*list)->array[i])); ((*list)->array[i]) = ((void *)0); } while(0);
    }


    do { if(((*list)->array)) free(((*list)->array)); ((*list)->array) = ((void *)0); } while(0);


    do { if((*list)) free((*list)); (*list) = ((void *)0); } while(0);
}
