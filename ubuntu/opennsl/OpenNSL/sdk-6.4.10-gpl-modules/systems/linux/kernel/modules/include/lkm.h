/*
 * Unless you and Broadcom execute a separate written software license
 * agreement governing use of this software, this software is licensed to
 * you under the terms of the GNU General Public License version 2 (the
 * "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
 * with the following added to such license:
 * 
 * As a special exception, the copyright holders of this software give
 * you permission to link this software with independent modules, and to
 * copy and distribute the resulting executable under terms of your
 * choice, provided that you also meet, for each linked independent
 * module, the terms and conditions of the license of that module.  An
 * independent module is a module which is not derived from this
 * software.  The special exception does not apply to any modifications
 * of the software.
 */
/*
 * $Id: lkm.h,v 1.22 2013/03/06 23:44:17 mlarsen Exp $
 * $Copyright: (c) 2005 Broadcom Corp.
 * All Rights Reserved.$
 */

#ifndef __COMMON_LINUX_KRN_LKM_H__
#define __COMMON_LINUX_KRN_LKM_H__

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#include <linux/init.h>
#include <linux/version.h>
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,5,0)
#include <linux/config.h>
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,1,0)
#include <linux/kconfig.h>
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0)
#include <linux/slab.h>
#endif
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,39)
#include <linux/smp_lock.h>
#endif
#include <linux/module.h>

/* Helper defines for multi-version kernel  support */
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,5,0)
#define LKM_2_4
#else
#define LKM_2_6
#endif

#include <linux/kernel.h>   /* printk() */
#include <linux/fs.h>       /* everything... */
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>    /* O_ACCMODE */
#include <linux/pci.h>
#include <linux/interrupt.h>
#include <linux/stat.h>
#include <linux/sched.h>
#include <linux/delay.h>

#include <asm/io.h>
#include <asm/hardirq.h>
#include <asm/uaccess.h>

#ifdef CONFIG_DEVFS_FS
#include <linux/devfs_fs_kernel.h>
#endif

#define PROC_INTERFACE_KERN_VER_3_10 (LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0))

/* Compatibility Macros */

#ifdef LKM_2_4

#include <linux/compatmac.h>
#include <linux/wrapper.h>
#define LKM_MOD_PARAM(n,ot,nt,d) MODULE_PARM(n,ot)
#define LKM_MOD_PARAM_ARRAY(n,ot,nt,c,d) MODULE_PARM(n,ot)
#define LKM_EXPORT_SYM(s)
#define _free_netdev kfree

#else /* LKM_2_6 */

#define LKM_MOD_PARAM(n,ot,nt,d) module_param(n,nt,d)
#define LKM_MOD_PARAM_ARRAY(n,ot,nt,c,d) module_param_array(n,nt,c,d)
#define LKM_EXPORT_SYM(s) EXPORT_SYMBOL(s)
#define _free_netdev free_netdev

#endif /* LKM_2_x */

#ifndef list_for_each_safe
#define list_for_each_safe(l,t,i) t = 0; list_for_each((l),(i))
#endif

#ifndef reparent_to_init
#define reparent_to_init()
#endif

#ifndef MODULE_LICENSE
#define MODULE_LICENSE(str)
#endif

#ifndef EXPORT_NO_SYMBOLS
#define EXPORT_NO_SYMBOLS
#endif

#ifndef DEFINE_SPINLOCK
#define DEFINE_SPINLOCK(_lock) spinlock_t _lock = SPIN_LOCK_UNLOCKED
#endif

#ifndef __SPIN_LOCK_UNLOCKED
#define __SPIN_LOCK_UNLOCKED(_lock) SPIN_LOCK_UNLOCKED
#endif

#ifndef lock_kernel
#ifdef preempt_disable
#define lock_kernel() preempt_disable()
#else
#define lock_kernel()
#endif
#endif

#ifndef unlock_kernel
#ifdef preempt_enable
#define unlock_kernel() preempt_enable()
#else
#define unlock_kernel()
#endif
#endif

#ifndef init_MUTEX_LOCKED
#define init_MUTEX_LOCKED(_sem) sema_init(_sem, 0)
#endif

#ifdef CONFIG_BCM98245
#define CONFIG_BMW
#endif

#if PROC_INTERFACE_KERN_VER_3_10
#define PROC_CREATE(_entry, _name, _acc, _path, _fops)                  \
    do {                                                                \
        _entry = proc_create(_name, _acc, _path, _fops);                \
    } while (0)

#define PROC_CREATE_DATA(_entry, _name, _acc, _path, _fops, _data)      \
    do {                                                                \
        _entry = proc_create_data(_name, _acc, _path, _fops, _data);    \
    } while (0)

#define PROC_PDE_DATA(_node) PDE_DATA(_node)

#else
#define PROC_CREATE(_entry, _name, _acc, _path, _fops)                  \
    do {                                                                \
        _entry = create_proc_entry(_name, _acc, _path);                 \
        if (_entry) {                                                   \
            _entry->proc_fops = _fops;                                  \
        }                                                               \
    } while (0)

#define PROC_CREATE_DATA(_entry, _name, _acc, _path, _fops, _data)      \
    do {                                                                \
        _entry = create_proc_entry(_name, _acc, _path);                 \
        if (_entry) {                                                   \
            _entry->proc_fops = _fops;                                  \
            _entry->data=_data;                                         \
        }                                                               \
    } while (0)

#define PROC_PDE_DATA(_node) PROC_I(_node)->pde->data
#endif

#endif /* __COMMON_LINUX_KRN_LKM_H__ */
