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
 * $Id: sdk_config.h,v 1.5 2012/03/02 15:13:56 yaronm Exp $
 * $Copyright: (c) 2006 Broadcom Corp.
 * All Rights Reserved.$
 *
 *
 */

#ifndef __SDK_CONFIG_H__
#define __SDK_CONFIG_H__

/*
 * Include custom overrides
 */
#ifdef SDK_INCLUDE_CUSTOM_CONFIG
#include <sdk_custom_config.h>
#endif


/*
 * Memory Barrier operation if required. 
 * Defaults to nothing. 
 */
#ifndef SDK_CONFIG_MEMORY_BARRIER
#define SDK_CONFIG_MEMORY_BARRIER
#endif



#endif /* __SDK_CONFIG_H__ */
