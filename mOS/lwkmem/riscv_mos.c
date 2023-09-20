// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2012 Regents of the University of California
 * Copyright (C) 2019 Western Digital Corporation or its affiliates.
 * Copyright (C) 2020 FORTH-ICS/CARV
 *  Nick Kossifidis <mick@ics.forth.gr>
 */

#include <linux/init.h>
#include <linux/mm.h>
#include <linux/memblock.h>
#include <linux/initrd.h>
#include <linux/swap.h>
#include <linux/swiotlb.h>
#include <linux/sizes.h>
#include <linux/of_fdt.h>
#include <linux/of_reserved_mem.h>
#include <linux/libfdt.h>
#include <linux/set_memory.h>
#include <linux/dma-map-ops.h>
#include <linux/crash_dump.h>
#include <linux/hugetlb.h>
#ifdef CONFIG_RELOCATABLE
#include <linux/elf.h>
#endif
#include <linux/kfence.h>

#include <asm/fixmap.h>
#include <asm/tlbflush.h>
#include <asm/sections.h>
#include <asm/soc.h>
#include <asm/io.h>
#include <asm/ptdump.h>
#include <asm/numa.h>

#include "../kernel/head.h"

int arch_add_memory(int nid, u64 start, u64 size,
		    struct mhp_params *params)
{
  //	unsigned long start_pfn = start >> PAGE_SHIFT;
  //	unsigned long nr_pages = size >> PAGE_SHIFT;

  panic("arch_add_memory: fix me");
  //init_memory_mapping(start, start + size, params->pgprot);

  //return add_pages(nid, start_pfn, nr_pages, params);
  return -1;
}

void __ref arch_remove_memory(u64 start, u64 size, struct vmem_altmap *altmap)
{
  panic("arch_remove_memory");
}

void __ref vmemmap_free(unsigned long start, unsigned long end,
		struct vmem_altmap *altmap)
{
  panic("vmemmap_free");
}

/*
 * When an LWK process is launched, this function will be called with a cpumask
 * representing the CPUs reserved for the process. Polling will be disabled
 * for correctable machine check events and correctable machine check interrupts
 * will be disabled.
 */
void mce_lwkprocess_begin(cpumask_t *lwkcpus, unsigned int threshold,
			  bool poll_enable)
{
	panic(__func__);
}
/*
 * When an LWK process exits, this function will be called with a cpumask
 * representing the CPUs reserved for the process. The state of machine check
 * polling, correctable machine check interrupt enablement and thresholding will
 * be restored. An immediate poll of the machine check banks to flush out any
 * events that may have accumulated during the process execution will be
 * performed.
 */
void mce_lwkprocess_end(cpumask_t *lwkcpus, bool reset_threshold,
		bool reenable_poll)
{
	panic(__func__);
}


/*
 * Multi Operating System (mOS)
 * Copyright (c) 2020 Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */
#include <asm/tlbflush.h>
#include <asm/pgalloc.h>
#include <linux/mos.h>
#include <trace/events/lwkmem.h>

/* Private headers */
#include "lwk_mm_private.h"

#define LWKPG_SPLIT_PMD_FLAGS (_PAGE_DIRTY | _PAGE_ACCESSED | _PAGE_RW)
#define LWKPG_SPLIT_PUD_FLAGS (LWKPG_SPLIT_PMD_FLAGS)

#define TRACE_PTE	0
#define TRACE_PMD	1
#define TRACE_PUD	2

/*
 * Linux does not have this function yet. We follow pmdp_estabish() logic
 * that is defined at arch/x86/include/asm/pgtable.h
 *
 * Keeping this identical to Linux pmdp_establish() prototype so that if
 * Linux adds this function later then it would conflict with us and we
 * will know about that change.
 */
static inline pud_t pudp_establish(struct vm_area_struct *vma,
				   unsigned long address,
				   pud_t *pudp, pud_t pud)
{
	panic(__func__);
}

/*
 * Simplified version of __split_huge_pmd_locked(), look at mm/huge_memory.c
 * comments on hardware limitations and related handling of huge PMD splits.
 * We ignore the reference counts for now as LWK memory is not ref. counted.
 */
void lwk_mm_split_pmd_locked(struct vm_area_struct *vma, pmd_t *pmd,
			     unsigned long address)
{
	panic(__func__);
}

void lwk_mm_split_pud_locked(struct vm_area_struct *vma, pud_t *pud,
			     unsigned long address)
{
	panic(__func__);
}

void lwk_mm_split_pmd(struct vm_area_struct *vma, unsigned long address)
{
	panic(__func__);
}

void lwk_mm_split_pud(struct vm_area_struct *vma, unsigned long address)
{
	panic(__func__);
}

/*
 * Function to clear struct page and corresponding physical memory contents
 * before releasing it to physical memory allocator. To be used by unmap
 * functions.
 */
static void clear_user_lwkpg(struct page *page, unsigned long page_size,
			     bool pte_dirty)
{
	panic(__func__);
}

/*
 * Functions to map page table for a range of addresses within an LWK VMA
 */
int lwk_mm_map_pte(pmd_t *pmd, struct vm_area_struct *vma, unsigned long start,
		   unsigned long end, struct list_head *list)
{
	panic(__func__);
}

int lwk_mm_map_pmd(pud_t *pud, struct vm_area_struct *vma, unsigned long start,
		   unsigned long end, enum lwk_page_type t,
		   struct list_head *list)

{
	panic(__func__);
}

int lwk_mm_map_pud(p4d_t *p4d, struct vm_area_struct *vma, unsigned long start,
		   unsigned long end, enum lwk_page_type t,
		   struct list_head *list)
{
	panic(__func__);
}

int lwk_mm_map_p4d(pgd_t *pgd, struct vm_area_struct *vma, unsigned long start,
		   unsigned long end, enum lwk_page_type t,
		   struct list_head *list)
{
	panic(__func__);
}

int lwk_mm_map_pages(struct vm_area_struct *vma, unsigned long start,
		     unsigned long end, enum lwk_page_type t,
		     struct list_head *list)
{
	panic(__func__);
}

/*
 * Functions to unmap page table for a range of addresses within an LWK VMA
 */
static void lwk_mm_unmap_pte(struct vm_area_struct *vma, pmd_t *pmd,
			     unsigned long start, unsigned long end,
			     struct list_head (*list)[LWK_MAX_NUMPGTYPES])
{
	panic(__func__);
}

static void lwk_mm_unmap_pmd(struct vm_area_struct *vma, pud_t *pud,
			     unsigned long start, unsigned long end,
			     struct list_head (*list)[LWK_MAX_NUMPGTYPES])
{
	panic(__func__);
}

static void lwk_mm_unmap_pud(struct vm_area_struct *vma, p4d_t *p4d,
			     unsigned long start, unsigned long end,
			     struct list_head (*list)[LWK_MAX_NUMPGTYPES])
{
	panic(__func__);
}

static void lwk_mm_unmap_p4d(struct vm_area_struct *vma, pgd_t *pgd,
			     unsigned long start, unsigned long end,
			     struct list_head (*list)[LWK_MAX_NUMPGTYPES])
{
	panic(__func__);
}

void lwk_mm_unmap_pages(struct vm_area_struct *vma,
			unsigned long start, unsigned long end)
{
	panic(__func__);
}

/*
 * Support for remaping part of the page table from old virtual address range to
 * the new virtual address range. We could have re-used Linux move_page_table()
 * with minor patches but unfortunately it does not support PUD size huge pages
 * yet. So we do something similar but with the consideration that there could
 * be PUD size pages in LWK VMAs.
 */
unsigned long lwk_mm_move_entire_pmd(pmd_t *old_pmd,
				     struct vm_area_struct *old_vma,
				     unsigned long old_addr,
				     struct vm_area_struct *new_vma,
				     unsigned long *new_addrp)
{
	panic(__func__);
}

unsigned long lwk_mm_move_entire_pud(pud_t *old_pud,
				     struct vm_area_struct *old_vma,
				     unsigned long old_addr,
				     struct vm_area_struct *new_vma,
				     unsigned long *new_addrp)
{
	panic(__func__);
}

static pte_t *get_new_pte(struct mm_struct *mm, unsigned long addr,
			  spinlock_t **ptl)
{
	panic(__func__);
}

unsigned long lwk_mm_move_pte(pmd_t *old_pmd, struct vm_area_struct *old_vma,
			      unsigned long old_addr, unsigned long old_end,
			      struct vm_area_struct *new_vma,
			      unsigned long *new_addrp)
{
	panic(__func__);
}

unsigned long lwk_mm_move_pmd(pud_t *pud, struct vm_area_struct *old_vma,
			      unsigned long old_addr, unsigned long old_end,
			      struct vm_area_struct *new_vma,
			      unsigned long *new_addrp)
{
	panic(__func__);
}

unsigned long lwk_mm_move_pud(p4d_t *p4d, struct vm_area_struct *old_vma,
			      unsigned long old_addr, unsigned long old_end,
			      struct vm_area_struct *new_vma,
			      unsigned long *new_addrp)
{
	panic(__func__);
}

unsigned long lwk_mm_move_p4d(pgd_t *pgd, struct vm_area_struct *old_vma,
			      unsigned long old_addr, unsigned long old_end,
			      struct vm_area_struct *new_vma,
			      unsigned long *new_addrp)
{
	panic(__func__);
}

unsigned long lwk_mm_move_page_tables(struct vm_area_struct *old_vma,
				      unsigned long old_start,
				      struct vm_area_struct *new_vma,
				      unsigned long new_start,
				      unsigned long len)
{
	panic(__func__);
}

void init_xpmem_stats(struct lwk_vm_stats *vm_stats)
{
	enum lwk_page_type k1, k2;
	enum attachment_align_stats_t s;

	for (k1 = LWK_PG_4K; k1 < LWK_MAX_NUMPGTYPES; k1++) {
		for (k2 = LWK_PG_4K; k2 < LWK_MAX_NUMPGTYPES; k2++) {
			vm_stats->src_pgmap[k1][k2] = 0;
			vm_stats->dst_pgmap[k1][k2] = 0;
		}
	}

	for (s = 0; s < ALIGN_STAT_END; s++)
		vm_stats->attachment_align_stats[s] = 0;
}

int unmap_lwkxpmem_range(struct vm_area_struct *vma, unsigned long start,
			 unsigned long end)
{
	int rc = -EINVAL;
#if 0
	if (start > end || !is_lwkxpmem(vma) || !vma->vm_private_data)
		goto out;
	rc = remove_vma_subregions(vma, start, end);
out:
	trace_mos_unmap_lwkxpmem_range(vma->vm_start, vma->vm_end, start, end,
		rc);
#endif
	panic(__func__);
	return rc;
}
static void show_xpmem_pgmap_stats(struct lwk_vm_stats *vm_stats, bool src)
{
  panic(__func__);
#if 0
	int rc;
	enum lwk_page_type k1, k2;
	unsigned long size = LWK_MAX_NUMPGTYPES * MAX_CHARS;
	char *str = kzalloc(size, GFP_KERNEL);

	if (!vm_stats || !str)
		goto out;

	/* Print header */
	pr_info("%s map stats:\n", src ? "Source" : "Destination");
	for (k1 = LWK_MAX_NUMPGTYPES - 1, rc = 0; (int) k1 >= LWK_PG_4K; k1--)
		rc += snprintf((str + rc), size - rc, " %16s", kind_str[k1]);
	pr_info("%4s%s\n", " ", str);

	/* Print table */
	memset(str, 0, size);
	for (k1 = LWK_MAX_NUMPGTYPES - 1; (int) k1 >= LWK_PG_4K; k1--) {
		for (k2 = LWK_MAX_NUMPGTYPES - 1, rc = 0;
		     (int) k2 >= LWK_PG_4K; k2--) {
			rc += snprintf((str + rc), size - rc, " %16ld",
					src ? vm_stats->src_pgmap[k1][k2] :
					      vm_stats->dst_pgmap[k1][k2]);
		}
		pr_info("%3s:%s\n", kind_str[k1], str);
	}
out:
	kfree(str);
#endif
}
void show_xpmem_stats(struct lwk_vm_stats *vm_stats)
{
  panic(__func__);
#if 0
	enum attachment_align_stats_t s;

	pr_info("mOS XPMEM stats for tgid %d\n", current->tgid);
	show_xpmem_pgmap_stats(vm_stats, true);
	show_xpmem_pgmap_stats(vm_stats, false);

	pr_info("Attachment alignment stats:\n");
	for (s = 0; s < ALIGN_STAT_END; s++) {
		pr_info("%-35s: %ld\n", attachment_align_msg[s],
			vm_stats->attachment_align_stats[s]);
	}
#endif
}


