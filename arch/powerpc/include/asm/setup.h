#ifndef _ASM_POWERPC_SETUP_H
#define _ASM_POWERPC_SETUP_H

#include <uapi/asm/setup.h>

#ifndef __ASSEMBLY__
extern void ppc_printk_progress(char *s, unsigned short hex);

extern unsigned int rtas_data;
extern unsigned long long memory_limit;
extern unsigned long klimit;
extern void *zalloc_maybe_bootmem(size_t size, gfp_t mask);

struct device_node;
extern void note_scsi_host(struct device_node *, void *);

/* Used in very early kernel initialization. */
extern unsigned long reloc_offset(void);
extern unsigned long add_reloc_offset(unsigned long);
extern void reloc_got2(unsigned long);

#define PTRRELOC(x)	((typeof(x)) add_reloc_offset((unsigned long)(x)))

void check_for_initrd(void);
void initmem_init(void);
#define ARCH_PANIC_TIMEOUT 180

/* These are bit flags */
enum stf_barrier_type {
	STF_BARRIER_NONE	= 0x1,
	STF_BARRIER_FALLBACK	= 0x2,
	STF_BARRIER_EIEIO	= 0x4,
	STF_BARRIER_SYNC_ORI	= 0x8,
};

void setup_stf_barrier(void);
void do_stf_barrier_fixups(enum stf_barrier_type types);

enum l1d_flush_type {
	L1D_FLUSH_NONE		= 0x1,
	L1D_FLUSH_FALLBACK	= 0x2,
	L1D_FLUSH_ORI		= 0x4,
	L1D_FLUSH_MTTRIG	= 0x8,
};

void setup_rfi_flush(enum l1d_flush_type, bool enable);
void do_rfi_flush_fixups(enum l1d_flush_type types);

#endif /* !__ASSEMBLY__ */

#endif	/* _ASM_POWERPC_SETUP_H */

