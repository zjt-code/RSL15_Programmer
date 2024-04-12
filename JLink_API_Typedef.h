#include <windows.h>
#include<libloaderapi.h>
#include<stdio.h>
#include<string.h>
#include<iostream>

#define NVR0_ADDR 0X00080000
#define NVR7_ADDR 0X00080700
#define MNVR_ADDR 0X00080800

#define PARAM_START_ADDR            NVR7_ADDR   //NVR4

// #define PARAM_START_ADDR            0x00080400   //NVR4
// #define RSL15_512_FLASH_START_ADDR  0X00100000
#define RSL15_512_FLASH_START_ADDR  PARAM_START_ADDR



typedef char            (WINAPI * pBoolVoid)(void);
typedef int32_t         (WINAPI * pIntVoid)(void);
typedef char           *(WINAPI * pCharVoid)(void);
typedef void            (WINAPI * pVoidVoid)(void);
typedef void            (WINAPI * pVoidInt)(int32_t);
typedef int             (WINAPI * pIntCharInt)(const char *,int32_t);
typedef void            (WINAPI * pVoidU8)(uint8_t);

typedef int32_t         (WINAPI *pIntCharCharInt)(char *,char *, int32_t);
typedef int32_t         (WINAPI *pIntIntIntVoid)(int32_t,int32_t,void *);
typedef int32_t         (WINAPI *pIntIntIntVoidInt)(int32_t addr, int32_t num, void *pdate, int32_t access);
typedef int32_t         (WINAPI *pIntInt)(int32_t);

