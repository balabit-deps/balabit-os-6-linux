/*********************************************************************
*
* (C) Copyright Broadcom Corporation 2013-2016
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*
**********************************************************************
*
* \file         driver.h
*
* \brief        This file contains utility functions called externally
*
**********************************************************************/
#ifndef DRIVER_H
#define DRIVER_H

typedef struct opennsl_config_s
{
  char         *cfg_fname;  /* Configuration file name along with the path */
  unsigned int flags;       /* OpenNSL boot up flags */
  char         *wb_fname;   /* File to store warmboot configuration *
                            * along with the path */
  char         *rmcfg_fname; /* RM config file name along with the path */
} opennsl_init_t;

/*****************************************************************//**
* \brief Function to initialize the switch.
*
* \param init       [IN]   pointer to structure that contains path to
*                          platform customization config file, boot flags.
*
* \return OPENNSL_E_XXX     OpenNSL API return code
********************************************************************/
extern int opennsl_driver_init(opennsl_init_t *init);

/**************************************************************************//**
 * \brief To get platform boot flags
 *
 * \return      unsigned int    Boot flags
 *****************************************************************************/
extern unsigned int opennsl_driver_boot_flags_get(void);

/*****************************************************************//**
* \brief Bringup diagnostic shell prompt and process the input commands.
*
* \return OPENNSL_E_XXX     OpenNSL API return code
********************************************************************/
extern int opennsl_driver_shell();

/*****************************************************************//**
* \brief Process diagnostic shell command.
*
* \param commandBuf    [IN]    pointer to hold the diagnostic shell command
*
* \return OPENNSL_E_XXX     OpenNSL API return code
********************************************************************/
extern int opennsl_driver_process_command(char *commandBuf);

extern char *readline(const char *prompt);
#endif  /* DRIVER_H */
