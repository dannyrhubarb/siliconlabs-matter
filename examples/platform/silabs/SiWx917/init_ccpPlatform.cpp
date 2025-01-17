/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2019 Google LLC.
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include "AppConfig.h"
#include <lib/support/CHIPPlatformMemory.h>
#include <platform/CHIPDeviceLayer.h>

#ifdef __cplusplus
extern "C" {
#endif
#include <assert.h>
#include <string.h>

#include "rsi_pll.h"
#include "rsi_board.h"
#include "system_RS1xxxx.h"
#include "rsi_rom_clks.h"

#include <mbedtls/platform.h>

#include "init_ccpPlatform.h"

extern "C" void RSI_Board_Init(void);

void initAntenna(void);

/* GPIO button config */
void RSI_Wakeupsw_config(void);

void init_ccpPlatform(void)
{
    SystemCoreClockUpdate();

    RSI_Board_Init();

    RSI_Wakeupsw_config();

#if SILABS_LOG_ENABLED
    silabsInitLog();
#endif

}

#ifdef __cplusplus
}
#endif
