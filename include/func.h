/**
 * func.h
 * Global functions declarition
 */

#include "console.h"
#include "tty.h"


/* lib/lib.asm */
PUBLIC void* memocpy(void* pDst, void* pSrc, int iSize);
PUBLIC void memoset(void* p_dst, char ch, int size);
PUBLIC void  print(const char* pszInfo, const int color);
PUBLIC char* strcpy(char* p_dst, char* p_src);
PUBLIC void out_byte(u16 port, u8 value);
PUBLIC u8 in_byte(u16 port);
PUBLIC void disable_irq(int irq);
PUBLIC void enable_irq(int irq);
PUBLIC void disable_int();
PUBLIC void enable_int();

/* lib/stdlib.c */
PUBLIC char* itoa(char * str, int num);
PUBLIC void print_bit(int input, char color);

/* kernel/clock.c */
PUBLIC void clock_handler(int irq);
PUBLIC void mili_delay(int milli_sec);
PUBLIC void delay(int sec);

/* kernel/kernel.asm */
PUBLIC void restart();
PUBLIC void sys_call();

/* kernel/protect.c */
PUBLIC void init_prot();
PUBLIC void init_8259A();
PUBLIC void exception_handler(int vec_no, int err_code, int eip, int cs, int eflags);
PUBLIC void spurious_irq(int irq);  
PUBLIC u32 seg2phys(u16 seg);
PUBLIC void put_irq_handler(int irq, irq_handler handler);

/* kernel/keyboard.c */
PUBLIC void init_keyboard();
PUBLIC void keyboard_handler(int irq);
PUBLIC void keyboard_read(TTY* p_tty);

/* kernel/main.c */
PUBLIC int kernel_main();
PUBLIC void init_clock();
PUBLIC void TestA();
PUBLIC void TestB();

/* kernel/process.c */
PUBLIC int sys_get_ticks();
PUBLIC void schedule();

/* syscall.asm */
PUBLIC int get_ticks();


/* kernel/tty.c */
PUBLIC void task_tty();
PUBLIC void init_tty(TTY* p_tty);
PUBLIC void in_process(TTY* p_tty ,u32 key);

/* kernel/console.c */
PUBLIC void out_char(CONSOLE* p_con, char ch, int color);
PUBLIC int is_current_console(CONSOLE* p_con);
PUBLIC void clear_screen(CONSOLE* p_con);
PUBLIC void init_screen(TTY* p_tty);
PUBLIC void out_char(CONSOLE* p_con, char ch, int color);
PUBLIC void out_string(CONSOLE* p_con, char* str, int color);

