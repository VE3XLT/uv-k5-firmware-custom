/* Copyright 2024 Armel F4HWN
 * https://github.com/armel
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#include "debugging.h"
#include "driver/st7565.h"

static inline void getScreenShot(void)
{
    char str[2] = "";

    LogUart("P1\n");
    LogUart("128 64\n");

    for(uint8_t b = 0; b < 8; b++)
    {
        for(uint8_t i = 0; i < 128; i++)
        {
            sprintf(str, "%d ", ((gStatusLine[i] >> b)  & 0x01));
            LogUart(str);
        }
        LogUart("\n");
    }

    for(uint8_t l = 0; l < 7; l++)
    {
        for(uint8_t b = 0; b < 8; b++)
        {
            for(uint8_t i = 0; i < 128; i++)
            {
                sprintf(str, "%d ", ((gFrameBuffer[l][i] >> b)  & 0x01));
                LogUart(str);
            }
        }
        LogUart("\n");
    }

    LogUart("\n----------------\n");
}