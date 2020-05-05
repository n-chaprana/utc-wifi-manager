//
// Copyright (c) 2014 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include "tct_common.h"

#define MOBILE 1
#ifdef MOBILE	//Starts MOBILE
#include "tct-wifi-manager-core_mobile.h"
#endif  //MOBILE	//End MOBILE

#ifdef WEARABLE	//Starts WEARABLE
#include "tct-wifi-manager-core_wearable.h"
#endif  //WEARABLE	//End WEARABLE

#ifdef TV	//Starts TV
#include "tct-wifi-manager-core_tv.h"
#endif  //TV	//End TV

#ifdef TIZENIOT	//Starts TIZENIOT
#include "tct-wifi-manager-core_tizeniot.h"
#endif  //TIZENIOT	//End TIZENIOT

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <glib.h>
#include <stdbool.h>
#include <dlog.h>

int main(int argc, char *argv[])
{
	int i=0, result=0;
	int total = 0, failed = 0, passed = 0;

	printf("pid [%d]\n", getpid());

	for ( i = 0; tc_array[i].name; i++ )
	{
		DUMP_UTC_ERRLOG();
		dlog_print(DLOG_INFO, "NativeTCT", "%s : Startup begin", tc_array[i].name);
		if ( tc_array[i].startup )
		{
			tc_array[i].startup();
		}
		dlog_print(DLOG_INFO, "NativeTCT", "%s : Startup end", tc_array[i].name);

		dlog_print(DLOG_INFO, "NativeTCT", "%s : Body begin", tc_array[i].name);
		result = tc_array[i].function();
		dlog_print(DLOG_INFO, "NativeTCT", "%s returns value = %d", tc_array[i].name, result);
		dlog_print(DLOG_INFO, "NativeTCT", "%s : Body end", tc_array[i].name);

		dlog_print(DLOG_INFO, "NativeTCT", "%s : Cleanup begin", tc_array[i].name);
		if ( tc_array[i].cleanup )
		{
			tc_array[i].cleanup();
		}
		dlog_print(DLOG_INFO, "NativeTCT", "%s : Cleanup end", tc_array[i].name);

		CLOSE_UTC_ERRLOG();
		PRINT_TC_RESULT("%d",result);
		printf("[%s]:[%s]\n", (result == 0) ? "pass" : "fail", tc_array[i].name);
		if (result != 0)
			failed++;
		else
			passed++;
	}

	printf("Total [%d], Passed [%d], Failed [%d]\n", total, passed, failed);
	return 0;
}
