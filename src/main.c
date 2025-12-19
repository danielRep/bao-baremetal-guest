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
#include <uart.h>
#include <pmu.h>
#include <inttypes.h>

#define COL_SIZE        20
#define SAMPLE_FORMAT   "%" XSTR(COL_SIZE) "llu"
#define HEADER_FORMAT   "%" XSTR(COL_SIZE) "s"

#define NUM_WARMUPS     10
#define NUM_SAMPLES  (NUM_WARMUPS + 990)

uint64_t samples[NUM_SAMPLES];
uint64_t pmu_samples[NUM_SAMPLES];

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

    printf("Bao bare-metal context-switch test\n");
    yield(); // allow other guest to get to the loop

    while(1) {
        printf("Press 's' to start...\n");
        while(uart_getchar() != 's');

        size_t i = 0;

        printf("timer pmu\n");

        while(i < NUM_SAMPLES) {
            pmu_reset();
            pmu_start();
            pmu_cycle_enable(true);

            uint64_t context_switch_start_cnt = timer_get();
            uint64_t context_switch_start_pmu = pmu_cycle_get();

            yield();

            samples[i] = shared_mem->context_switch_end_cnt  - context_switch_start_cnt;
            pmu_samples[i] = shared_mem->context_switch_end_pmu  - context_switch_start_pmu;

            printf("%llu %llu\n", samples[i], pmu_samples[i]);
            i++;
        }

        // pmu_reset();
        // pmu_start();
        // pmu_cycle_enable(true);
        // const uint64_t target_cycles = 10*1000000000ULL;
        // while(1){
        //     uint64_t acc = 0;
        //     uint32_t prev = pmu_cycle_get();
            
        //     printf("Tstamp1\n");
        //     while (acc < target_cycles) {
        //         uint32_t now = pmu_cycle_get();
        //         acc += (uint32_t)(now - prev);   // unsigned subtraction handles wrap
        //         prev = now;
        //     }
        //     printf("Tstamp2\n");
        // }

        //check timer freq is correct. loop for a 1 mnt (freq=8MHz)
        // uint64_t start = pmu_cycle_get();
        // while((pmu_cycle_get() - start) < 480000000ull);
        // printf("time stamp\n");
        // pmu_reset();
    }
}
