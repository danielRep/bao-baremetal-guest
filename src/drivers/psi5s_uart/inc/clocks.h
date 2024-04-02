#include <stdint.h>

/* XOSC bypass option */
#define CLOCK_XOSC_USE_CRYSTAL       0U
#define CLOCK_XOSC_USE_EXTAL         1U

/* PLL modulation mode */
#define CLOCK_PLL_CENTRE_SPREAD_MODULATION   0U
#define CLOCK_PLL_DOWN_SPREAD_MODULATION     1U

#define CLOCK_FXOSC_CLK_SRC          1U
#define CLOCK_AURORA_REF_CLK_SRC     0U

/* XOSC configurations array */
#define CLOCK_XOSCS_NO    1U
#define CLOCK_XOSC        0U

/* PLL configurations array */
#define CLOCK_PLLS_NO     3U
#define CLOCK_CORE_PLL    0U
#define CLOCK_PERIPH_PLL  1U
#define CLOCK_AURORA_PLL  2U

/* Clock source outputs array */
#define CLOCK_SOURCE_ODIV_NO   11U
#define CLOCK_CORE_PLL_PHI0    0U
#define CLOCK_CORE_PLL_PHI1    1U
#define CLOCK_PERIPH_PLL_PHI0  2U
#define CLOCK_PERIPH_PLL_PHI1  3U
#define CLOCK_PERIPH_PLL_PHI2  4U
#define CLOCK_PERIPH_PLL_PHI3  5U
#define CLOCK_PERIPH_PLL_PHI4  6U
#define CLOCK_PERIPH_PLL_PHI5  7U
#define CLOCK_PERIPH_PLL_PHI6  8U
#define CLOCK_PERIPH_PLL_PHI7  9U
#define CLOCK_AURORA_PLL_PHI0  10U

/* Clock source outputs array */
#define CLOCK_FRAC_DIV_NO      12U
#define CLOCK_CORE_PLL_DFS1    0U
#define CLOCK_CORE_PLL_DFS2    1U
#define CLOCK_CORE_PLL_DFS3    2U
#define CLOCK_CORE_PLL_DFS4    3U
#define CLOCK_CORE_PLL_DFS5    4U
#define CLOCK_CORE_PLL_DFS6    5U
#define CLOCK_PERIPH_PLL_DFS1  6U
#define CLOCK_PERIPH_PLL_DFS2  7U
#define CLOCK_PERIPH_PLL_DFS3  8U
#define CLOCK_PERIPH_PLL_DFS4  9U
#define CLOCK_PERIPH_PLL_DFS5  10U
#define CLOCK_PERIPH_PLL_DFS6  11U

/* Selectors array */
#define CLOCK_SELECTOR_NO      22U
#define CLOCK_CGM0_MUX0        0U
#define CLOCK_CGM0_MUX1        1U
#define CLOCK_CGM0_MUX2        2U
#define CLOCK_CGM0_MUX3        3U
#define CLOCK_CGM0_MUX4        4U
#define CLOCK_CGM0_MUX5        5U
#define CLOCK_CGM0_MUX6        6U
#define CLOCK_CGM0_MUX7        7U
#define CLOCK_CGM0_MUX8        8U
#define CLOCK_CGM0_MUX9        9U
#define CLOCK_CGM0_MUX10       10U
#define CLOCK_CGM0_MUX11       11U
#define CLOCK_CGM0_MUX12       12U
#define CLOCK_CGM0_MUX13       13U
#define CLOCK_CGM0_MUX14       14U
#define CLOCK_CGM0_MUX15       15U
#define CLOCK_CGM0_MUX16       16U
#define CLOCK_CGM2_MUX1        17U
#define CLOCK_CGM2_MUX2        18U
#define CLOCK_CGM2_MUX3        19U
#define CLOCK_CGM2_MUX4        20U
#define CLOCK_MC_ME_AE_MUX     21U

/* Dividers array */
#define CLOCK_DIVIDER_NO               33U
#define CLOCK_CGM0_MUX1_DIV0           0U
#define CLOCK_CGM0_MUX10_DIV0          1U
#define CLOCK_CGM0_MUX12_DIV0          2U
#define CLOCK_CGM0_MUX14_DIV0          3U
#define CLOCK_CGM0_MUX15_DIV0          4U
#define CLOCK_CGM0_MUX2_DIV0           5U
#define CLOCK_CGM0_MUX3_DIV0           6U
#define CLOCK_CGM0_MUX4_DIV0           7U
#define CLOCK_CGM0_MUX5_DIV0           8U
#define CLOCK_CGM0_MUX6_DIV0           9U
#define CLOCK_CGM0_MUX9_DIV0           10U
#define CLOCK_CGM2_MUX1_DIV0           11U
#define CLOCK_CGM2_MUX1_DIV1           12U
#define CLOCK_CGM2_MUX1_DIV2           13U
#define CLOCK_CGM2_MUX2_DIV0           14U
#define CLOCK_CGM2_MUX2_DIV1           15U
#define CLOCK_CGM2_MUX2_DIV2           16U
#define CLOCK_CGM2_MUX3_DIV0           17U
#define CLOCK_CGM2_MUX3_DIV1           18U
#define CLOCK_CGM2_MUX3_DIV2           19U
#define CLOCK_CGM2_MUX3_DIV3           20U
#define CLOCK_CGM2_MUX3_DIV4           21U
#define CLOCK_CGM2_MUX3_DIV5           22U
#define CLOCK_CGM2_MUX3_DIV6           23U
#define CLOCK_CGM2_MUX3_DIV7           24U
#define CLOCK_CGM2_MUX4_DIV0           25U
#define CLOCK_CGM2_MUX4_DIV1           26U
#define CLOCK_CGM2_MUX4_DIV2           27U
#define CLOCK_CGM2_MUX4_DIV3           28U
#define CLOCK_CGM2_MUX4_DIV4           29U
#define CLOCK_CGM2_MUX4_DIV5           30U
#define CLOCK_CGM2_MUX4_DIV6           31U
#define CLOCK_CGM2_MUX4_DIV7           32U

/* External clocks */
#define CLOCK_EXTERNAL_NO              6U
#define CLOCK_GMAC_EXT_REF             0U
#define CLOCK_GMAC_EXT_RX_REF          1U
#define CLOCK_GMAC_EXT_TX_REF          2U
#define CLOCK_FTM0_EXT                 3U
#define CLOCK_FTM1_EXT                 4U
#define CLOCK_AURORA_EXT_REF           5U

/* CORE_PLL - Peripheral instance base addresses */
/** Peripheral CORE_PLL base address */
#define CORE_PLL_BASE                  (0x40038000u)
/** Peripheral CORE_PLL base pointer */
#define CORE_PLL                       ((CORE_PLL_Type *)CORE_PLL_BASE)

/* PERIPH_PLL - Peripheral instance base addresses */
/** Peripheral PERIPH_PLL base address */
#define PERIPH_PLL_BASE                (0x4003C000u)
/** Peripheral PERIPH_PLL base pointer */
#define PERIPH_PLL                     ((PERIPH_PLL_Type *)PERIPH_PLL_BASE)

/** Peripheral PERIPH_DFS base address */
#define PERIPH_DFS_BASE                (0x40058000u)
/** Peripheral PERIPH_DFS base pointer */
#define PERIPH_DFS                     ((DFS_Type *)PERIPH_DFS_BASE)

/* FXOSC - Peripheral instance base addresses */
/** Peripheral FXOSC base address */
#define FXOSC_BASE                     (0x40050000u)
/** Peripheral FXOSC base pointer */
#define FXOSC                          ((FXOSC_Type *)FXOSC_BASE)

/* CTL - Control */
#define DFS_CTL_DFS_RESET_MASK         (0x2U)
#define DFS_PORTS_MASK                 ((1U<<6U) - 1U)

#define DFS_PORTSR_PORTSTAT_MASK                 (0x3FU)
#define DFS_PORTSR_PORTSTAT_SHIFT                (0U)

/* DFS - Peripheral instance base addresses */
/** Peripheral CORE_DFS base address */
#define CORE_DFS_BASE                  (0x40054000u)
/** Peripheral CORE_DFS base pointer */
#define CORE_DFS                       ((DFS_Type *)CORE_DFS_BASE)

/* MC_ME_AE - Peripheral instance base addresses */
/** Peripheral MC_ME_AE base address */
#define MC_ME_AE_BASE                            (0x55638000u)
/** Peripheral MC_ME_AE base pointer */
#define MC_ME_AE                                 ((MC_ME_AE_Type *)MC_ME_AE_BASE)

/* DVPORT - Divider for Port 0..Divider for Port 5 */
#define DFS_DVPORT_MFN_MASK                      (0x3FU)
#define DFS_DVPORT_MFN_SHIFT                     (0U)
#define DFS_DVPORT_MFN_WIDTH                     (6U)
#define DFS_DVPORT_MFN(x)                        (((uint32_t)(((uint32_t)(x)) << DFS_DVPORT_MFN_SHIFT)) & DFS_DVPORT_MFN_MASK)
#define DFS_DVPORT_MFI_MASK                      (0xFF00U)
#define DFS_DVPORT_MFI_SHIFT                     (8U)
#define DFS_DVPORT_MFI_WIDTH                     (8U)
#define DFS_DVPORT_MFI(x)                        (((uint32_t)(((uint32_t)(x)) << DFS_DVPORT_MFI_SHIFT)) & DFS_DVPORT_MFI_MASK)


/* MCTL - Mode Control */
#define MC_ME_AE_MCTL_KEY_MASK                   (0xFFFFU)
#define MC_ME_AE_MCTL_KEY_SHIFT                  (0U)
#define MC_ME_AE_MCTL_KEY_WIDTH                  (16U)
#define MC_ME_AE_MCTL_KEY(x)                     (((uint32_t)(((uint32_t)(x)) << MC_ME_AE_MCTL_KEY_SHIFT)) & MC_ME_AE_MCTL_KEY_MASK)
#define MC_ME_AE_MCTL_TARGET_MODE_MASK           (0xF0000000U)
#define MC_ME_AE_MCTL_TARGET_MODE_SHIFT          (28U)
#define MC_ME_AE_MCTL_TARGET_MODE_WIDTH          (4U)
#define MC_ME_AE_MCTL_TARGET_MODE(x)             (((uint32_t)(((uint32_t)(x)) << MC_ME_AE_MCTL_TARGET_MODE_SHIFT)) & MC_ME_AE_MCTL_TARGET_MODE_MASK)
#define MC_ME_AE_DRUN_MC_SYSCLK_MASK             (0xFU)
#define MC_ME_AE_GS_S_MTRANS_MASK                (0x8000000U)
#define MC_ME_AE_DRUN_MC_SYSCLK_MASK             (0xFU)
#define MC_ME_AE_DRUN_MC_SYSCLK_SHIFT            (0U)
#define MC_ME_AE_DRUN_MC_SYSCLK(x)               (((uint32_t)(((uint32_t)(x)) << MC_ME_AE_DRUN_MC_SYSCLK_SHIFT)) & MC_ME_AE_DRUN_MC_SYSCLK_MASK)

/* MC_CGM_0 - Peripheral instance base addresses */
/** Peripheral MC_CGM_0 base address */
//#define MC_CGM_0_BASE                            (0x40030000u)
/** Peripheral MC_CGM_0 base pointer */
//#define MC_CGM_0                                 ((MC_CGM_0_Type *)MC_CGM_0_BASE)
/* MC_CGM_2 - Peripheral instance base addresses */
/** Peripheral MC_CGM_2 base address */
//#define MC_CGM_2_BASE                            (0x440C0000u)
/** Peripheral MC_CGM_2 base pointer */
//#define MC_CGM_2                                 ((MC_CGM_2_Type *)MC_CGM_2_BASE)

#define MC_CGM_0_CSS_SWIP_MASK                   (0x10000U)
#define MC_CGM_0_CSC_SELCTL_MASK                 (0x3F000000U)
#define MC_CGM_0_CSC_CLK_SW_MASK                 (0x4U)
#define MC_CGM_0_CSC_SELCTL_MASK                 (0x3F000000U)
#define MC_CGM_0_CSC_SELCTL_SHIFT                (24U)
#define MC_CGM_0_CSC_SELCTL(x)                   (((uint32_t)(((uint32_t)(x)) << MC_CGM_0_CSC_SELCTL_SHIFT)) & MC_CGM_0_CSC_SELCTL_MASK)

#define MC_CGM_0_CSC_CG_MASK                     (0x4U)
#define MC_CGM_0_CSC_FCG_MASK                    (0x8U)

#define MC_CGM_2_CSC_SELCTL_MASK                 (0x3F000000U)
#define MC_CGM_2_CSC_SELCTL_SHIFT                (24U)
#define MC_CGM_2_CSC_SELCTL(x)                   (((uint32_t)(((uint32_t)(x)) << MC_CGM_2_CSC_SELCTL_SHIFT)) & MC_CGM_2_CSC_SELCTL_MASK)

#define MC_CGM_0_DC_DIV_MASK                     (0xFF0000U)
#define MC_CGM_0_DC_DIV_SHIFT                    (16U)
#define MC_CGM_0_DC_DIV_WIDTH                    (8U)
#define MC_CGM_0_DC_DIV(x)                       (((uint32_t)(((uint32_t)(x)) << MC_CGM_0_DC_DIV_SHIFT)) & MC_CGM_0_DC_DIV_MASK)
#define MC_CGM_0_DC_DE_MASK                      (0x80000000U)

#define MC_CGM_2_DC_DIV_MASK                     (0x1FFF0000U)  /* Merged from fields with different position or width, of widths (8, 10, 13), largest definition used */
#define MC_CGM_2_DC_DIV_SHIFT                    (16U)
#define MC_CGM_2_DC_DIV_WIDTH                    (13U)
#define MC_CGM_2_DC_DIV(x)                       (((uint32_t)(((uint32_t)(x)) << MC_CGM_2_DC_DIV_SHIFT)) & MC_CGM_2_DC_DIV_MASK)  /* Merged from fields with different position or width, of widths (8, 10, 13), largest definition used */
#define MC_CGM_2_DC_DE_MASK                      (0x80000000U)

/* PLLCLKMUX - PLL Clock Multiplexer */
#define PERIPH_PLL_PLLCLKMUX_REFCLKSEL_MASK      (0x1U)
#define PERIPH_PLL_PLLCLKMUX_REFCLKSEL_SHIFT     (0U)
#define PERIPH_PLL_PLLCLKMUX_REFCLKSEL(x)        (((uint32_t)(((uint32_t)(x)) << PERIPH_PLL_PLLCLKMUX_REFCLKSEL_SHIFT)) & PERIPH_PLL_PLLCLKMUX_REFCLKSEL_MASK)

/* PLLDV - PLL Divider */
#define PERIPH_PLL_PLLDV_MFI_MASK                (0xFFU)
#define PERIPH_PLL_PLLDV_MFI_SHIFT               (0U)
#define PERIPH_PLL_PLLDV_MFI(x)                  (((uint32_t)(((uint32_t)(x)) << PERIPH_PLL_PLLDV_MFI_SHIFT)) & PERIPH_PLL_PLLDV_MFI_MASK)
#define PERIPH_PLL_PLLDV_RDIV_MASK               (0x7000U)
#define PERIPH_PLL_PLLDV_RDIV_SHIFT              (12U)
#define PERIPH_PLL_PLLDV_RDIV(x)                 (((uint32_t)(((uint32_t)(x)) << PERIPH_PLL_PLLDV_RDIV_SHIFT)) & PERIPH_PLL_PLLDV_RDIV_MASK)

/* PLLFD - PLL Fractional Divider */
#define PERIPH_PLL_PLLFD_MFN_MASK                (0x7FFFU)
#define PERIPH_PLL_PLLFD_MFN_SHIFT               (0U)
#define PERIPH_PLL_PLLFD_MFN(x)                  (((uint32_t)(((uint32_t)(x)) << PERIPH_PLL_PLLFD_MFN_SHIFT)) & PERIPH_PLL_PLLFD_MFN_MASK)
#define PERIPH_PLL_PLLFD_SDMEN_MASK              (0x40000000U)
#define PERIPH_PLL_PLLFD_SDMEN_SHIFT             (30U)
#define PERIPH_PLL_PLLFD_SDMEN(x)                (((uint32_t)(((uint32_t)(x)) << PERIPH_PLL_PLLFD_SDMEN_SHIFT)) & PERIPH_PLL_PLLFD_SDMEN_MASK)

/* PLLCR - PLL Control Register */
#define PERIPH_PLL_PLLCR_PLLPD_MASK              (0x80000000U)
#define PERIPH_PLL_PLLCR_PLLPD_SHIFT             (31U)
#define PERIPH_PLL_PLLCR_PLLPD(x)                (((uint32_t)(((uint32_t)(x)) << PERIPH_PLL_PLLCR_PLLPD_SHIFT)) & PERIPH_PLL_PLLCR_PLLPD_MASK)

/* PLLCLKMUX - PLL Clock Multiplexer */
#define CORE_PLL_PLLCLKMUX_REFCLKSEL_MASK        (0x1U)
#define CORE_PLL_PLLCLKMUX_REFCLKSEL_SHIFT       (0U)
#define CORE_PLL_PLLCLKMUX_REFCLKSEL_WIDTH       (1U)
#define CORE_PLL_PLLCLKMUX_REFCLKSEL(x)          (((uint32_t)(((uint32_t)(x)) << CORE_PLL_PLLCLKMUX_REFCLKSEL_SHIFT)) & CORE_PLL_PLLCLKMUX_REFCLKSEL_MASK)

/* PLLDV - PLL Divider */
#define CORE_PLL_PLLDV_MFI_MASK                  (0xFFU)
#define CORE_PLL_PLLDV_MFI_SHIFT                 (0U)
#define CORE_PLL_PLLDV_MFI_WIDTH                 (8U)
#define CORE_PLL_PLLDV_MFI(x)                    (((uint32_t)(((uint32_t)(x)) << CORE_PLL_PLLDV_MFI_SHIFT)) & CORE_PLL_PLLDV_MFI_MASK)
#define CORE_PLL_PLLDV_RDIV_MASK                 (0x7000U)
#define CORE_PLL_PLLDV_RDIV_SHIFT                (12U)
#define CORE_PLL_PLLDV_RDIV_WIDTH                (3U)
#define CORE_PLL_PLLDV_RDIV(x)                   (((uint32_t)(((uint32_t)(x)) << CORE_PLL_PLLDV_RDIV_SHIFT)) & CORE_PLL_PLLDV_RDIV_MASK)

/* PLLFD - PLL Fractional Divider */
#define CORE_PLL_PLLFD_MFN_MASK                  (0x7FFFU)
#define CORE_PLL_PLLFD_MFN_SHIFT                 (0U)
#define CORE_PLL_PLLFD_MFN_WIDTH                 (15U)
#define CORE_PLL_PLLFD_MFN(x)                    (((uint32_t)(((uint32_t)(x)) << CORE_PLL_PLLFD_MFN_SHIFT)) & CORE_PLL_PLLFD_MFN_MASK)
#define CORE_PLL_PLLFD_SDMEN_MASK                (0x40000000U)
#define CORE_PLL_PLLFD_SDMEN_SHIFT               (30U)
#define CORE_PLL_PLLFD_SDMEN_WIDTH               (1U)
#define CORE_PLL_PLLFD_SDMEN(x)                  (((uint32_t)(((uint32_t)(x)) << CORE_PLL_PLLFD_SDMEN_SHIFT)) & CORE_PLL_PLLFD_SDMEN_MASK)

/* PLLFM - PLL Frequency Modulation */
#define CORE_PLL_PLLFM_STEPNO_MASK               (0x7FFU)
#define CORE_PLL_PLLFM_STEPNO_SHIFT              (0U)
#define CORE_PLL_PLLFM_STEPNO_WIDTH              (11U)
#define CORE_PLL_PLLFM_STEPNO(x)                 (((uint32_t)(((uint32_t)(x)) << CORE_PLL_PLLFM_STEPNO_SHIFT)) & CORE_PLL_PLLFM_STEPNO_MASK)
#define CORE_PLL_PLLFM_STEPSIZE_MASK             (0x3FF0000U)
#define CORE_PLL_PLLFM_STEPSIZE_SHIFT            (16U)
#define CORE_PLL_PLLFM_STEPSIZE_WIDTH            (10U)
#define CORE_PLL_PLLFM_STEPSIZE(x)               (((uint32_t)(((uint32_t)(x)) << CORE_PLL_PLLFM_STEPSIZE_SHIFT)) & CORE_PLL_PLLFM_STEPSIZE_MASK)
#define CORE_PLL_PLLFM_SPREADCTL_MASK            (0x20000000U)
#define CORE_PLL_PLLFM_SPREADCTL_SHIFT           (29U)
#define CORE_PLL_PLLFM_SPREADCTL_WIDTH           (1U)
#define CORE_PLL_PLLFM_SPREADCTL(x)              (((uint32_t)(((uint32_t)(x)) << CORE_PLL_PLLFM_SPREADCTL_SHIFT)) & CORE_PLL_PLLFM_SPREADCTL_MASK)
#define CORE_PLL_PLLFM_SSCGBYP_MASK              (0x40000000U)
#define CORE_PLL_PLLFM_SSCGBYP_SHIFT             (30U)
#define CORE_PLL_PLLFM_SSCGBYP_WIDTH             (1U)
#define CORE_PLL_PLLFM_SSCGBYP(x)                (((uint32_t)(((uint32_t)(x)) << CORE_PLL_PLLFM_SSCGBYP_SHIFT)) & CORE_PLL_PLLFM_SSCGBYP_MASK)

/* PLLCR - PLL Control Register */
#define CORE_PLL_PLLCR_PLLPD_MASK                (0x80000000U)
#define CORE_PLL_PLLCR_PLLPD_SHIFT               (31U)
#define CORE_PLL_PLLCR_PLLPD_WIDTH               (1U)
#define CORE_PLL_PLLCR_PLLPD(x)                  (((uint32_t)(((uint32_t)(x)) << CORE_PLL_PLLCR_PLLPD_SHIFT)) & CORE_PLL_PLLCR_PLLPD_MASK)

/* PLLSR - PLL status register */
#define CORE_PLL_PLLSR_LOCK_MASK                 (0x4U)
#define CORE_PLL_PLLSR_LOCK_SHIFT                (2U)
#define CORE_PLL_PLLSR_LOCK_WIDTH                (1U)
#define CORE_PLL_PLLSR_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << CORE_PLL_PLLSR_LOCK_SHIFT)) & CORE_PLL_PLLSR_LOCK_MASK)

/*! @name PLLSR - PLL status register */
#define PERIPH_PLL_PLLSR_LOCK_MASK               (0x4U)
#define PERIPH_PLL_PLLSR_LOCK_SHIFT              (2U)
#define PERIPH_PLL_PLLSR_LOCK_WIDTH              (1U)
#define PERIPH_PLL_PLLSR_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << PERIPH_PLL_PLLSR_LOCK_SHIFT)) & PERIPH_PLL_PLLSR_LOCK_MASK)

/* FXOSC_STAT - Oscillator Status Register */
#define FXOSC_FXOSC_STAT_OSC_STAT_MASK           (0x80000000U)
#define FXOSC_FXOSC_STAT_OSC_STAT_SHIFT          (31U)
#define FXOSC_FXOSC_STAT_OSC_STAT_WIDTH          (1U)
#define FXOSC_FXOSC_STAT_OSC_STAT(x)             (((uint32_t)(((uint32_t)(x)) << FXOSC_FXOSC_STAT_OSC_STAT_SHIFT)) & FXOSC_FXOSC_STAT_OSC_STAT_MASK)

/* FXOSC_CTRL - FXOSC Control Register */
#define FXOSC_FXOSC_CTRL_OSCON_MASK              (0x1U)
#define FXOSC_FXOSC_CTRL_OSCON_SHIFT             (0U)
#define FXOSC_FXOSC_CTRL_OSCON_WIDTH             (1U)
#define FXOSC_FXOSC_CTRL_OSCON(x)                (((uint32_t)(((uint32_t)(x)) << FXOSC_FXOSC_CTRL_OSCON_SHIFT)) & FXOSC_FXOSC_CTRL_OSCON_MASK)
#define FXOSC_FXOSC_CTRL_GM_SEL_MASK             (0xF0U)
#define FXOSC_FXOSC_CTRL_GM_SEL_SHIFT            (4U)
#define FXOSC_FXOSC_CTRL_GM_SEL_WIDTH            (4U)
#define FXOSC_FXOSC_CTRL_GM_SEL(x)               (((uint32_t)(((uint32_t)(x)) << FXOSC_FXOSC_CTRL_GM_SEL_SHIFT)) & FXOSC_FXOSC_CTRL_GM_SEL_MASK)
#define FXOSC_FXOSC_CTRL_EOCV_MASK               (0xFF0000U)
#define FXOSC_FXOSC_CTRL_EOCV_SHIFT              (16U)
#define FXOSC_FXOSC_CTRL_EOCV_WIDTH              (8U)
#define FXOSC_FXOSC_CTRL_EOCV(x)                 (((uint32_t)(((uint32_t)(x)) << FXOSC_FXOSC_CTRL_EOCV_SHIFT)) & FXOSC_FXOSC_CTRL_EOCV_MASK)
#define FXOSC_FXOSC_CTRL_COMP_EN_MASK            (0x1000000U)
#define FXOSC_FXOSC_CTRL_COMP_EN_SHIFT           (24U)
#define FXOSC_FXOSC_CTRL_COMP_EN_WIDTH           (1U)
#define FXOSC_FXOSC_CTRL_COMP_EN(x)              (((uint32_t)(((uint32_t)(x)) << FXOSC_FXOSC_CTRL_COMP_EN_SHIFT)) & FXOSC_FXOSC_CTRL_COMP_EN_MASK)
#define FXOSC_FXOSC_CTRL_OSC_BYP_MASK            (0x80000000U)
#define FXOSC_FXOSC_CTRL_OSC_BYP_SHIFT           (31U)
#define FXOSC_FXOSC_CTRL_OSC_BYP_WIDTH           (1U)
#define FXOSC_FXOSC_CTRL_OSC_BYP(x)              (((uint32_t)(((uint32_t)(x)) << FXOSC_FXOSC_CTRL_OSC_BYP_SHIFT)) & FXOSC_FXOSC_CTRL_OSC_BYP_MASK)

/* FXOSC - Peripheral instance base addresses */
/** Peripheral FXOSC base address */
#define FXOSC_BASE                               (0x40050000u)
/** Peripheral FXOSC base pointer */
#define FXOSC                                    ((FXOSC_Type *)FXOSC_BASE)

/** FXOSC - Register Layout Typedef */
typedef struct {
    uint32_t FXOSC_CTRL;                             /**< FXOSC Control Register, offset: 0x0 */
    uint32_t FXOSC_STAT;                             /**< Oscillator Status Register, offset: 0x4 */
} FXOSC_Type, *FXOSC_MemMapPtr;


/*
 * CGM Clock Source XOSC configuration structure. Implements clock_xosc_config_t_Class
 */
typedef struct
{
    uint32_t                  freq;               /*!< External oscillator frequency. */
    uint8_t                   enable;             /*!< Enable xosc. */
    uint16_t                  startupDelay;       /*!< Startup stabilization time. */
    uint8_t                   bypassOption;       /*!< XOSC bypass option */
    uint8_t                   transConductance;   /*!< Crystal overdrive protection */

} clock_xosc_config_t;

/*
 * CGM Clock Source PLLDIG configuration structure. Implements clock_pll_config_t_Class
 */
typedef struct
{
    uint8_t                    enable;                         /*!< Enable pll. */
    uint8_t                    bypass;                         /*!< Bypass pll. */
    uint8_t                    inputReference;                 /*!< Input reference. */
    uint8_t                    predivider;                     /*!< Input clock predivider. (PREDIV) */
    uint16_t                   numeratorFracLoopDiv;           /*!< Numerator of fractional loop division factor (MFN) */
    uint8_t                    mulFactorDiv;                   /*!< Multiplication factor divider (MFD) */
    uint8_t                    modulation;                     /*!< Enable/disable modulation */
    uint8_t                    modulationType;                 /*!< Modulation type */
    uint16_t                   modulationPeriod;               /*!< Stepsize - modulation period */
    uint16_t                   incrementStep;                  /*!< Stepno  - step no */
    uint8_t                    sigmaDelta;                     /*!< Sigma Delta Modulation Enable */
    uint8_t                    ditherControl;                  /*!< Dither control enable */
    uint8_t                    ditherControlValue;             /*!< Dither control value */
} clock_pll_config_t;

/*
 * Clock DFS configuration structure. Implements clock_fracDiv_config_t_Class
 */
typedef struct
{
    uint16_t                    value1;                         /*!< Dfs value1 */
    uint16_t                    value2;                         /*!< Dfs value2 */
} clock_fracDiv_config_t;

/*
 * Clock configuration structure. Implements clock_user_config_t_Class
 */
typedef struct
{
	clock_xosc_config_t            xoscConfig[CLOCK_XOSCS_NO];        /* XOSC configuration */
    clock_pll_config_t             pllConfig[CLOCK_PLLS_NO];          /* PLL configuration */
    uint32_t                       clkoDiv[CLOCK_SOURCE_ODIV_NO];     /* Clock source output divider */
    clock_fracDiv_config_t         fracDiv[CLOCK_FRAC_DIV_NO];        /* Fractional divider configuration */
    uint8_t                        selectors[CLOCK_SELECTOR_NO];      /* Selectors */
    uint16_t                       dividers[CLOCK_DIVIDER_NO];        /* Dividers */
    uint32_t                       extClks[CLOCK_EXTERNAL_NO];        /* External clocks */
    
} clock_user_config_t;

void CLOCK_DRV_Init(clock_user_config_t const * config);
