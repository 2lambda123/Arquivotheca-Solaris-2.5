/*
 * Copyright (c) 1991, by Sun Microsystems, Inc.
 */

#ifndef	_SYS_SYSIOERR_H
#define	_SYS_SYSIOERR_H

#pragma ident	"@(#)sysioerr.h	1.7	95/08/31 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Sbus error interrupt priorities
 */
#define	SBUS_UE_PIL		12
#define	SBUS_CE_PIL		11
#define	SBUS_ERR_PIL		12
#define	SBUS_THERMAL_PIL	9

/*
 * SBus error register offsets and INOs
 */
#define	SYSIO_CSR_OFFSET	0x0010
#define	SBUS_ECC_CR_OFFSET	0x0020
#define	SBUS_UE_AFSR_OFFSET	0x0030
#define	SBUS_UE_AFAR_OFFSET	0x0038
#define	SBUS_CE_AFSR_OFFSET	0x0040
#define	SBUS_CE_AFAR_OFFSET	0x0048
#define	SBUS_CSR_OFFSET		0x2000
#define	SBUS_ERR_AFSR_OFFSET	0x2010
#define	SBUS_ERR_AFAR_OFFSET	0x2018
#define	SBUS_UE_CLR_OFFSET	0x3870
#define	SBUS_CE_CLR_OFFSET	0x3878
#define	SBUS_ERR_CLR_OFFSET	0x3880
#define	SBUS_UE_INO		0x0034
#define	SBUS_CE_INO		0x0035
#define	SBUS_ERR_INO		0x0036

/*
 * SBus map register offsets
 */
#define	SBUS_SLOT0_MAP_OFFSET	0x2C00
#define	SBUS_SLOT1_MAP_OFFSET	0x2C08
#define	SBUS_SLOT2_MAP_OFFSET	0x2C10
#define	SBUS_SLOT3_MAP_OFFSET	0x2C18
#define	SBUS_SCSI_MAP_OFFSET	0x3000
#define	SBUS_ENET_MAP_OFFSET	0x3008
#define	SBUS_PARA_MAP_OFFSET	0x3010
#define	SBUS_AUDIO_MAP_OFFSET	0x3018
#define	SBUS_POWER_MAP_OFFSET	0x3020
#define	SBUS_K_M_S_MAP_OFFSET	0x3028
#define	SBUS_FLOPPY_MAP_OFFSET	0x3030
#define	SBUS_THERMAL_MAP_OFFSET	0x3038
#define	SBUS_KEYBD_MAP_OFFSET	0x3040
#define	SBUS_MOUSE_MAP_OFFSET	0x3048
#define	SBUS_SERIAL_MAP_OFFSET	0x3050
#define	SBUS_CLK0_MAP_OFFSET	0x3060
#define	SBUS_CLK1_MAP_OFFSET	0x3068
#define	SBUS_UE_MAP_OFFSET	0x3070
#define	SBUS_CE_MAP_OFFSET	0x3078
#define	SBUS_ERR_MAP_OFFSET	0x3080
#define	SBUS_WAKEUP_MAP_OFFSET	0x3088
#define	SBUS_GRAPHIC_MAP_OFFSET	0x3090
#define	SBUS_UPA1_MAP_OFFSET	0x3098
#define	SBUS_UPA2_MAP_OFFSET	0x8000

#define	SBUS_MAP_REGISTERS	24

/*
 * Bits of Sun5 SYSIO Control/Status Register
 */
#define	SYSIO_IMPL	0xF000000000000000ULL /* implementation number */
#define	SYSIO_VER	0x0F00000000000000ULL /* revision number */
#define	SYSIO_MID	0x00F8000000000000ULL /* UPA mid for SYSIO */
#define	SYSIO_INTGN	0x0007C00000000000ULL /* interrupt group number */
#define	SYSIO_APCKEN	0x0000000000000008ULL /* address parity check enable */
#define	SYSIO_APERR	0x0000000000000004ULL /* system address parity error */
#define	SYSIO_IAP	0x0000000000000002ULL /* invert UPA address parity */
#define	SYSIO_MODE	0x0000000000000001ULL /* speed of SYSIO clock */

/*
 * Bits of Sun5 SBus ECC Control Register
 */
#define	SECR_ECC_EN	0x8000000000000000ULL /* enable ECC checking */
#define	SECR_UE_INTEN	0x4000000000000000ULL /* enable UE_INT interrupt */
#define	SECR_CE_INTEN	0x2000000000000000ULL /* enable CE_INT interrupt */

/*
 * Bits of Sun5 SBus UE Asynchronous Fault Status Register
 */
#define	SB_UE_AFSR_P_PIO 0x8000000000000000ULL /* primary UE, PIO access */
#define	SB_UE_AFSR_P_DRD 0x4000000000000000ULL /* primary UE, DVMA read */
#define	SB_UE_AFSR_P_DWR 0x2000000000000000ULL /* primary UE, DVMA write */
#define	SB_UE_AFSR_P	 0xE000000000000000ULL /* primary UE */
#define	SB_UE_AFSR_S_PIO 0x1000000000000000ULL /* secondary UE, PIO access */
#define	SB_UE_AFSR_S_DRD 0x0800000000000000ULL /* secondary UE, DVMA read */
#define	SB_UE_AFSR_S_DWR 0x0400000000000000ULL /* secondary UE, DVMA write */
#define	SB_UE_AFSR_S	 0x1C00000000000000ULL /* secondary UE */
#define	SB_UE_AFSR_OFF   0x0000E00000000000ULL /* offset of dword w/pri. UE */
#define	SB_UE_AFSR_SIZE  0x00001C0000000000ULL /* 2**size of bad transfer */
#define	SB_UE_AFSR_MID   0x000003E000000000ULL /* master ID for pri. error */
#define	SB_UE_AFSR_ISAP	 0x0000001000000000ULL /* system parity error */

/*
 * Shifts for SBus Sysio UE Asynchronous Fault Status Register
 */
#define	SB_UE_DW_SHIFT		(45)
#define	SB_UE_SIZE_SHIFT	(42)
#define	SB_UE_MID_SHIFT		(41)

/*
 * Bits of Fusion Desktop SBus UE Asynchronous Fault Address Register
 */
#define	SB_UE_AFAR_PA	0x000001FFFFFFFFFF    /* PA<40:0>: physical address */

/*
 * Bits of Sun5 SBus CE Asynchronous Fault Status Register
 */
#define	SB_CE_AFSR_P_PIO 0x8000000000000000ULL /* primary CE, PIO access */
#define	SB_CE_AFSR_P_DRD 0x4000000000000000ULL /* primary CE, DVMA read */
#define	SB_CE_AFSR_P_DWR 0x2000000000000000ULL /* primary CE, DVMA write */
#define	SB_CE_AFSR_P	 0xE000000000000000ULL /* primary CE */
#define	SB_CE_AFSR_S_PIO 0x1000000000000000ULL /* secondary CE, PIO access */
#define	SB_CE_AFSR_S_DRD 0x0800000000000000ULL /* secondary CE, DVMA read */
#define	SB_CE_AFSR_S_DWR 0x0400000000000000ULL /* secondary CE, DVMA write */
#define	SB_CE_AFSR_S	 0x1C00000000000000ULL /* secondary CE */
#define	SB_CE_AFSR_SYND  0x00FF000000000000ULL /* CE syndrome bits */
#define	SB_CE_AFSR_OFF   0x0000E00000000000ULL /* offset of dword w/pri. CE */
#define	SB_CE_AFSR_SIZE	 0x00001C0000000000ULL /* 2**size of failed transfer */
#define	SB_CE_AFSR_MID	 0x000003E000000000ULL /* master ID for primary error */

/*
 * Shifts for Sun5 SBus CE Asynchronous Fault Status Register
 */
#define	SB_CE_SYND_SHIFT	(48)
#define	SB_CE_OFFSET_SHIFT	(45)
#define	SB_CE_SIZE_SHIFT	(42)
#define	SB_CE_MID_SHIFT		(41)

/*
 * Bits of Sun5 Fusion Desktop SBus CE Asynchronous Fault Address Register
 * Note: Fusion Desktop does not support E_SYND2.
 */
#define	SB_CE_E_SYND2	0xFF00000000000000ULL /* syndrome of prim. CE */
#define	SB_CE_AFAR_PA	0x000001FFFFFFFFFFULL /* PA<40:0>: physical address */

/*
 * Shift for Sun5 SBus CE Asynchronous Fault Address Register
 */
#define	SB_CE_SYND2_SHIFT	(56)

/*
 * Bits of Sun5 SBus Control and Status Register
 * See Fusion Desktop System Spec. Table 3-63 for details on slots 13-15
 */
#define	SB_CSR_IMPL	 0xF000000000000000ULL /* host adapter impl. number */
#define	SB_CSR_REV	 0x0F00000000000000ULL /* host adapter rev. number */
#define	SB_CSR_DPERR_S14 0x0020000000000000ULL /* SBus slot 14 aka Happy Meal */
#define	SB_CSR_DPERR_S13 0x0010000000000000ULL /* SBus slot 13 aka APC */
#define	SB_CSR_DPERR_S3  0x0008000000000000ULL /* SBus slot 3 DVMA parity err */
#define	SB_CSR_DPERR_S2  0x0004000000000000ULL /* SBus slot 2 DVMA parity err */
#define	SB_CSR_DPERR_S1  0x0002000000000000ULL /* SBus slot 1 DVMA parity err */
#define	SB_CSR_DPERR_S0  0x0001000000000000ULL /* SBus slot 0 DVMA parity err */
#define	SB_CSR_PIO_PERRS 0x00007F0000000000ULL /* SBus parity errors */
#define	SB_CSR_PPERR_S15 0x0000400000000000ULL /* SBus slot 15 aka slavio */
#define	SB_CSR_PPERR_S14 0x0000200000000000ULL /* SBus slot 14 aka Happy Meal */
#define	SB_CSR_PPERR_S13 0x0000100000000000ULL /* SBus slot 13 aka APC */
#define	SB_CSR_PPERR_S3  0x0000080000000000ULL /* SBus slot 3 PIO parity err */
#define	SB_CSR_PPERR_S2  0x0000040000000000ULL /* SBus slot 2 PIO parity err */
#define	SB_CSR_PPERR_S1  0x0000020000000000ULL /* SBus slot 1 PIO parity err */
#define	SB_CSR_PPERR_S0  0x0000010000000000ULL /* SBus slot 0 PIO parity err */
#define	SB_CSR_FAST_SBUS 0x0000000000000400ULL /* shorten PIO access latency */
#define	SB_CSR_WAKEUP_EN 0x0000000000000200ULL /* power-management bit */
#define	SB_CSR_ERRINT_EN 0x0000000000000100ULL /* enable intr. for SBus errs */
#define	SB_CSR_ARBEN_MAC 0x0000000000000020ULL /* enable DVMA for Macio */
#define	SB_CSR_ARBEN_APC 0x0000000000000010ULL /* enable DVMA for APC */
#define	SB_CSR_ARBEN_SLT 0x000000000000000FULL /* enable DVMA for SBus slots */

/*
 * Shifts for Sun5 SBus Control and Status Register
 */
#define	SB_CSR_IMPL_SHIFT	(60)
#define	SB_CSR_REV_SHIFT	(56)
#define	SB_CSR_DVMA_PERR_SHIFT	(48)
#define	SB_CSR_PIO_PERR_SHIFT	(40)

/*
 * Bits of Sun5 SBus Asynchronous Fault Status Register
 */
#define	SB_AFSR_P_ERRS	0xE000000000000000ULL /* primary errors */
#define	SB_AFSR_P_LE	0x8000000000000000ULL /* primary LATE_ERR */
#define	SB_AFSR_P_TO	0x4000000000000000ULL /* primary SBus TIMEOUT */
#define	SB_AFSR_P_BERR	0x2000000000000000ULL /* primary SBus ERR ack */
#define	SB_AFSR_S_ERRS	0x1C00000000000000ULL /* secondary errors */
#define	SB_AFSR_S_LE	0x1000000000000000ULL /* secondary LATE_ERR */
#define	SB_AFSR_S_TO	0x0800000000000000ULL /* secondary SBus TIMEOUT */
#define	SB_AFSR_S_BERR	0x0400000000000000ULL /* secondary SBus ERR ack */
#define	SB_AFSR_RD	0x0000800000000000ULL /* primary error was READ op. */
#define	SB_AFSR_SIZE	0x00001C0000000000ULL /* 2**size of failed transfer */
#define	SB_AFSR_MID	0x000003E000000000ULL /* master ID for primary error */

/*
 * Shifts for Sun5 SBus Asynchronous Fault Status Register
 */
#define	SB_AFSR_SIZE_SHIFT	(42)
#define	SB_AFSR_MID_SHIFT	(37)

/*
 * Bits of Fusion Desktop SBus Asynchronous Fault Address Register
 */
#define	SB_AFAR_PA	0x000001FFFFFFFFFFULL /* PA<40:0>: physical address */

/*
 * Function prototypes
 */
extern int
sysio_err_init(struct sbus_soft_state *softsp, int address);
extern int
sysio_err_resume_init(struct sbus_soft_state *softsp);

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_SYSIOERR_H */