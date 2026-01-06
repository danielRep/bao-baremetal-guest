/** 
 * Bao, a Lightweight Static Partitioning Hypervisor 
 *
 * Copyright (c) Bao Project (www.bao-project.org), 2019-
 *
 * Authors:
 *      Jose Martins <jose.martins@bao-project.org>
 *      Sandro Pinto <sandro.pinto@bao-project.org>
 *
 * Bao is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License version 2 as published by the Free
 * Software Foundation, with a special exception exempting guest code from such
 * license. See the COPYING file in the top-level directory for details. 
 *
 */

#include <core.h>
#include <stdlib.h>
#include <stdio.h>
#include <cpu.h>
#include <wfi.h>
#include <timer.h>
#include <pmu.h>

#define SMCC64_BIT              (0x40000000)
#define SMCC32_FID_VND_HYP_SRVC (0x86000000)
#define SMCC64_FID_VND_HYP_SRVC (SMCC32_FID_VND_HYP_SRVC | SMCC64_BIT)

#define BAO_YIELD_HYPCALL_ID  3

void yield() {
    const uint32_t fid = SMCC64_FID_VND_HYP_SRVC | BAO_YIELD_HYPCALL_ID;
    asm volatile(
        "mov r0, %0\n"
        "hvc #0x0EA1\n"
        :
        : "r"(fid)
        : "r0", "memory", "cc");
}

volatile struct {
    uint64_t context_switch_end_cnt;
    uint64_t context_switch_end_pmu;
} *shared_mem = (void*)0x32400000;

void main(void){

    printf("Bao bare-metal context-switch test guest 1 -- test\n");

    while(true) {

        // while(1){
        //     //check timer freq is correct. loop for a 1 mnt (freq=8MHz)
        //     uint64_t start = timer_get();
        //     while((timer_get() - start) < 480000000);
        //     printf("time stamp\n");
        // }

        yield();
        shared_mem->context_switch_end_cnt = (uint64_t)timer_get();
        shared_mem->context_switch_end_pmu = (uint64_t)pmu_cycle_get();
        // printf("[baremetal1] woke up! yielding..\n");
    }
}
