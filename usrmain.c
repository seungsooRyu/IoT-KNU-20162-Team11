/*
  Copyright (C) 2009 Sung Ho Park
  Contact: ubinos.org@gmail.com

  This file is part of the exe_helloworld component of the Ubinos.

  GNU General Public License Usage
  This file may be used under the terms of the GNU
  General Public License version 3.0 as published by the Free Software
  Foundation and appearing in the file license_gpl3.txt included in the
  packaging of this file. Please review the following information to
  ensure the GNU General Public License version 3.0 requirements will be
  met: http://www.gnu.org/copyleft/gpl.html.

  GNU Lesser General Public License Usage
  Alternatively, this file may be used under the terms of the GNU Lesser
  General Public License version 2.1 as published by the Free Software
  Foundation and appearing in the file license_lgpl.txt included in the
  packaging of this file. Please review the following information to
  ensure the GNU Lesser General Public License version 2.1 requirements
  will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.

  Commercial Usage
  Alternatively, licensees holding valid commercial licenses may
  use this file in accordance with the commercial license agreement
  provided with the software or, alternatively, in accordance with the
  terms contained in a written agreement between you and rightful owner.
*/

/* -------------------------------------------------------------------------
	Include
 ------------------------------------------------------------------------- */
#include "../ubiconfig.h"

// standard c library include
#include <stdio.h>
#include <sam4e.h>

// ubinos library include
#include "itf_ubinos/itf/bsp.h"
#include "itf_ubinos/itf/ubinos.h"
#include "itf_ubinos/itf/bsp_fpu.h"

// chipset driver include
#include "ioport.h"
#include "pio/pio.h"

// new estk driver include
#include "lib_new_estk_api/itf/new_estk_led.h"
#include "lib_new_estk_api/itf/new_estk_glcd.h"
#include "lib_i2c/itf/lib_i2c.h"
#include "lib_i2c_master/itf/lib_i2c_master.h"
#include "lib_switch/itf/lib_switch.h"
#include "lib_sensor/itf/lib_sensor.h"
#include "lib_EV3_sensor/itf/lib_EV3_sensor.h"
#include "lib_motor_driver/itf/lib_motor_driver.h"

//library
#include "../../lib_new/itf/lib_new.h"

// user header file include

/* -------------------------------------------------------------------------
	Global variables
 ------------------------------------------------------------------------- */
/* define */
#define	LOOP	1000

/* global variable */
static int LOCK = 1;

/* task */
void task_first(void);
void task_second(void);
void task_third(void);
/* -------------------------------------------------------------------------
	Prototypes
 ------------------------------------------------------------------------- */



/* -------------------------------------------------------------------------
	Function Definitions
 ------------------------------------------------------------------------- */
int usrmain(int argc, char * argv[]) {

	int r;

	printf("\n\n\n\r");
	printf("================================================================================\n\r");
	printf("exe_ubinos_test (build time: %s %s)\n\r", __TIME__, __DATE__);
	printf("================================================================================\n\r");

	/* task create */
	r=task_create(NULL, task_first, NULL, task_gethighestpriority(), 500, NULL);
	if (0 != r) {
		logme("fail at task_create\r\n");
	}

	r=task_create(NULL, task_second, NULL, task_gethighestpriority()-1, 500, NULL);
	if (0 != r) {
		logme("fail at task_create\r\n");
	}

	r=task_create(NULL, task_third, NULL, task_gethighestpriority()-2, 500, NULL);
	if (0 != r) {
		logme("fail at task_create\r\n");
	}

	ubik_comp_start();
	return 0;

}


void task_first(void) {
	if(LOCK==1){
		LOCK = 0;

		int i, j;

		for(i=0; i<10; i++) {
			for (j=0; j<LOOP; j++) {}
		}

		printf("task1\r\n");
	}
	else task_sleep(100);

	LOCK=1;
}

void task_second(void) {
	int i, j;

	for(i=0; i<10; i++) {
		for (j=0; j<LOOP; j++) {}
	}

	printf("task1\r\n");
}

void task_third(void) {
	if(LOCK==1){
		LOCK = 0;

		int i, j;

		for(i=0; i<10; i++) {
			for (j=0; j<LOOP; j++) {}
		}

		printf("task1\r\n");
		if (i==5) task_sleep(1000);
	}
	else task_sleep(100);

	LOCK=1;
}
