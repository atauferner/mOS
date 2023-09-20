# Multi Operating System (mOS)
# Copyright (c) 2016-2020, Intel Corporation.
#
# This program is free software; you can redistribute it and/or modify it
# under the terms and conditions of the GNU General Public License,
# version 2, as published by the Free Software Foundation.
#
# This program is distributed in the hope it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
# more details.

#
# mOS: Lightweight Kernel Memory Management
#

obj-$(CONFIG_MOS_LWKMEM) += mm.o init.o yod_options.o pma_buddy.o
obj-$(CONFIG_MOS_LWKMEM) += mm_mempolicy.o
ifeq ($(CONFIG_RISCV),y)
obj-$(CONFIG_MOS_LWKMEM) += riscv_mos.o
endif
ifeq ($(CONFIG_X86_64),y)
obj-$(CONFIG_MOS_LWKMEM) += mm_pagetable.o
obj-$(CONFIG_MOS_LWKMEM) += xpmem_utils.o
endif
obj-$(CONFIG_MOS_LWKMEM) += mm_protection.o
obj-$(CONFIG_MOS_LWKMEM) += mm_gup.o
