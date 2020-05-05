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
#ifndef _TCT_COMMON_H_
#define _TCT_COMMON_H_

#include "assert.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define CONFIG_LINE_LEN_MAX			2048
#define CONFIG_VALUE_LEN_MAX		1024

#define UTC_LOG "/tmp/utclog_core"
#define TC_RESULT "/tmp/tcresult"

#define CONFIGFILE_PATH "/opt/usr/data/network/utc-wifi-manager.conf"

#define FPRINTF(...) {\
}

#define DUMP_UTC_ERRLOG() {\
}

#define CLOSE_UTC_ERRLOG() {\
}

#define PRINT_UTC_LOG(...) {\
}

#define PRINT_TC_RESULT(...) {\
}

#define FREE_MEMORY(pointer) {\
}

#define FREE_MEMORY_TC(buffer) {\
}

#endif // _TCT_COMMON_H_
