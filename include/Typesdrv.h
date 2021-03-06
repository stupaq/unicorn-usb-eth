#ifndef _TYPESDRV_H_
#define _TYPESDRV_H_
#ifndef _TYPES_H_
#ifndef FAR
#define	FAR
#endif
#ifndef VOID
#define	VOID void
#endif
#ifndef CALLBACK	       
#define	CALLBACK	_stdcall
#endif

#ifndef FALSE
#define	FALSE	0
#endif
#ifndef TRUE
#define	TRUE	1
#endif


typedef unsigned char BYTE, *PBYTE, *PUCHAR, FAR *LPBYTE, BOOL;
typedef unsigned short WORD, *PWORD, FAR *LPWORD;
typedef unsigned long DWORD, *PDWORD, FAR * LPDWORD;
typedef unsigned int UINT;
typedef unsigned long ULONG;
typedef long int LONG;
typedef unsigned long long ULONGLONG;
typedef char *PSTR, FAR *LPSTR;
typedef const char *PCSTR, FAR *LPCSTR;
typedef void *PVOID, FAR *LPVOID;
typedef int BOOLEAN;
#ifndef __cplusplus
typedef int bool_t;
#else
typedef bool bool_t;
#endif




#ifndef MAX
#define MAX(a,b)	(((a)>(b))?(a):(b))
#endif
#ifndef MIN
#define MIN(a,b)	(((a)>(b))?(b):(a))
#endif

#ifndef offsetof
#define offsetof(typ,id) (unsigned)&(((typ*)0)->id)
#endif

#undef ST_STATUS
#undef SUCCESS
#undef FAILURE
enum ST_STATUS { SUCCESS,FAILURE };

#endif
#endif
