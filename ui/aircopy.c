/* Copyright 2023 Dual Tachyon
 * https://github.com/DualTachyon
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

#ifdef ENABLE_AIRCOPY

#include <string.h>

#include "app/aircopy.h"
#include "driver/st7565.h"
#include "external/printf/printf.h"
#include "misc.h"
#include "radio.h"
#include "ui/aircopy.h"
#include "ui/helper.h"
#include "ui/inputbox.h"

static int8_t map(int8_t x, int8_t in_min, int8_t in_max, int8_t out_min, int8_t out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void UI_DisplayAircopy(void)
{
	char String[16] = { 0 };
	char *pPrintStr = { 0 };
	static bool crc[120] = { 0 };
	static uint8_t lErrorsDuringAirCopy = 0;

	UI_DisplayClear();

	if (gAircopyState == AIRCOPY_READY) {
		pPrintStr = "AIR COPY(RDY)";
	} else if (gAircopyState == AIRCOPY_TRANSFER) {
		pPrintStr = "AIR COPY";
	} else {
		pPrintStr = "AIR COPY(CMP)";
	}

	UI_PrintString(pPrintStr, 2, 127, 0, 8);

	if (gInputBoxIndex == 0) {
		uint32_t frequency = gRxVfo->freq_config_RX.Frequency;
		sprintf(String, "%3u.%05u", frequency / 100000, frequency % 100000);
		// show the remaining 2 small frequency digits
		UI_PrintStringSmallNormal(String + 7, 97, 0, 3);
		String[7] = 0;
		// show the main large frequency digits
		UI_DisplayFrequency(String, 16, 2, false);
	} else {
		const char *ascii = INPUTBOX_GetAscii();
		sprintf(String, "%.3s.%.3s", ascii, ascii + 3);
		UI_DisplayFrequency(String, 16, 2, false);
	}

	memset(String, 0, sizeof(String));
	if (gAirCopyIsSendMode == 0) {
		sprintf(String, "RCV:%02d%% E:%02d", map(gAirCopyBlockNumber + gErrorsDuringAirCopy, 0, 120, 0, 100), gErrorsDuringAirCopy);
	} else if (gAirCopyIsSendMode == 1) {
		sprintf(String, "SND:%02d%%", map(gAirCopyBlockNumber + gErrorsDuringAirCopy, 0, 120, 0, 100));
	}
	UI_PrintString(String, 2, 127, 5, 8);

	// Draw gauge
	gFrameBuffer[4][2] = 0xff;

	for(uint8_t i = 1; i <= 122; i++)
	{
		gFrameBuffer[4][2 + i] = 0x81;
	}

	if(gAirCopyBlockNumber + gErrorsDuringAirCopy != 0)
	{
		// Check CRC
		if(gErrorsDuringAirCopy != lErrorsDuringAirCopy)
		{
			crc[gAirCopyBlockNumber + gErrorsDuringAirCopy - 1] = 1;
			lErrorsDuringAirCopy = gErrorsDuringAirCopy;
		}

		for(uint8_t i = 0; i < (gAirCopyBlockNumber + gErrorsDuringAirCopy); i++)
		{
			if(crc[i] == 0)
			{
				gFrameBuffer[4][i + 4] = 0xbd;
			}
		}
	}

	gFrameBuffer[4][125] = 0xff;

	ST7565_BlitFullScreen();
}

#endif
