/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            type.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef _MUTEOS_TYPE_H_
#define _MUTEOS_TYPE_H_

#include "const.h"

typedef unsigned long long  u64;
typedef unsigned int        u32;
typedef unsigned short      u16;
typedef unsigned char       u8;

typedef void  (*int_handler)  ();
typedef void  (*irq_handler)  (int irq);
typedef void  (*task_f)       ();
typedef void* system_call;
typedef char* va_list;

/* 存储段描述符/系统段描述符 */
typedef struct s_descriptor     /* 共 8 个字节 */
{
    u16 limit_low;              /* Limit */
    u16 base_low;               /* Base */
    u8  base_mid;               /* Base */
    u8  attr1;                  /* P(1) DPL(2) DT(1) TYPE(4) */
    u8  limit_high_attr2;       /* G(1) D(1) 0(1) AVL(1) LimitHigh(4) */
    u8  base_high;              /* Base */
} DESCRIPTOR;

/* 门描述符 */
typedef struct s_gate   /* 8 Bytes */
{
    u16 offset_low;     /* Offset Low */
    u16 selector;       /* Selector */
    u8  dcount;         /* Param */
    u8  attr;           /* P(1) DPL(2) DT(1) TYPE(4) */
    u16 offset_high;    /* Offset High */
} GATE;

/* TSS */
typedef struct s_tss {
    u32 backlink;
    u32 esp0;   /* stack pointer to use during interrupt */
    u32 ss0;    /*   "   segment  "  "    "        "     */
    u32 esp1;
    u32 ss1;
    u32 esp2;
    u32 ss2;
    u32 cr3;
    u32 eip;
    u32 flags;
    u32 eax;
    u32 ecx;
    u32 edx;
    u32 ebx;
    u32 esp;
    u32 ebp;
    u32 esi;
    u32 edi;
    u32 es;
    u32 cs;
    u32 ss;
    u32 ds;
    u32 fs;
    u32 gs;
    u32 ldt;
    u16 trap;
    u16 iobase; /* I/O位图基址大于或等于TSS段界限，就表示没有I/O许可位图 */
} TSS;



#endif /* _MUTEOS_TYPE_H_ */
