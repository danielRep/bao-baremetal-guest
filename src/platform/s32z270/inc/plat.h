#ifndef PLAT_H
#define PLAT_H

/*	DRAM */
// #define PLAT_MEM_BASE 0x317C0000
// #define PLAT_MEM_SIZE 0x3E000

#define PLAT_MEM_BASE 0x32700000
#define PLAT_MEM_SIZE 0x80000

#define PLAT_GENERIC_TIMER_CNTCTL_BASE (0x76200000)

#define PLAT_GICD_BASE_ADDR (0x47800000)
#define PLAT_GICR_BASE_ADDR (0x47900000)

#define UART_IRQ_ID 244

#endif


/*
			Interrupts

244	LINFlex_0	
245	LINFlex_1	
246	LINFlex_2	       
247	LINFlex_3	       
248	LINFlex_4	       
249	LINFlex_5	      
250	LINFlex_6	       
251	LINFlex_7	        
252	LINFlex_8	         
253	LINFlex_9        
254	LINFlex_10        
255	LINFlex_11    
*/