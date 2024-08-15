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

#include <string.h>

#include "app/chFrScanner.h"
#ifdef ENABLE_FMRADIO
    #include "app/fm.h"
#endif
#include "app/scanner.h"
#include "bitmaps.h"
#include "driver/keyboard.h"
#include "driver/st7565.h"
#include "external/printf/printf.h"
#include "functions.h"
#include "helper/battery.h"
#include "misc.h"
#include "settings.h"
#include "ui/battery.h"
#include "ui/helper.h"
#include "ui/ui.h"
#include "ui/status.h"

#ifdef ENABLE_FEAT_F4HWN_RX_TX_TIMER
static void convertTime(uint8_t *line, uint8_t type) 
{
    uint16_t t = (type == 0) ? (gTxTimerCountdown_500ms / 2) : (3600 - gRxTimerCountdown_500ms / 2);

    uint8_t m = t / 60;
    uint8_t s = t % 60; // Utilisation de l'opérateur modulo pour simplifier le calcul des secondes

    gStatusLine[0] = gStatusLine[7] = gStatusLine[14] = 0x00; // Quick fix on display (on scanning I, II, etc.)

    char str[8];
    sprintf(str, "%02d:%02d", m, s);
    UI_PrintStringSmallBufferNormal(str, line);

    gUpdateStatus = true;
}
#endif

void UI_DisplayStatus()
{
    char str[8] = "";

    gUpdateStatus = false;
    memset(gStatusLine, 0, sizeof(gStatusLine));

    uint8_t     *line = gStatusLine;
    unsigned int x    = 0;
    // **************

    // POWER-SAVE indicator
    if (gCurrentFunction == FUNCTION_POWER_SAVE) {
        memcpy(line + x, gFontPowerSave, sizeof(gFontPowerSave));
    }
    x += 8;
    unsigned int x1 = x;

#ifdef ENABLE_NOAA
    if (gIsNoaaMode) { // NOASS SCAN indicator
        memcpy(line + x, BITMAP_NOAA, sizeof(BITMAP_NOAA));
        x1 = x + sizeof(BITMAP_NOAA);
    }
    x += sizeof(BITMAP_NOAA);
#endif

#ifdef ENABLE_DTMF_CALLING
    if (gSetting_KILLED) {
        memset(line + x, 0xFF, 10);
        x1 = x + 10;
    }
    else
#endif
    { // SCAN indicator
        if (gScanStateDir != SCAN_OFF || SCANNER_IsScanning()) {
            if (IS_MR_CHANNEL(gNextMrChannel) && !SCANNER_IsScanning()) { // channel mode
                switch(gEeprom.SCAN_LIST_DEFAULT) {
                    case 0:
                        memcpy(line + 0, BITMAP_ScanList0, sizeof(BITMAP_ScanList0));
                        break;
                    case 1: 
                        memcpy(line + 0, BITMAP_ScanList1, sizeof(BITMAP_ScanList1));
                        break;
                    case 2:
                        memcpy(line + 0, BITMAP_ScanList2, sizeof(BITMAP_ScanList2));
                        break;
                    case 3:
                        memcpy(line + 0, BITMAP_ScanList3, sizeof(BITMAP_ScanList3));
                        break;
                    case 4:
                        memcpy(line + 0, BITMAP_ScanList123, sizeof(BITMAP_ScanList123));
                        break;
                    case 5:
                        memcpy(line + 0, BITMAP_ScanListAll, sizeof(BITMAP_ScanListAll));
                        break;
                }
            }
            else {  // frequency mode
                memcpy(line + x + 1, gFontS, sizeof(gFontS));
                //UI_PrintStringSmallBufferNormal("S", line + x + 1);
            }
            x1 = x + 10;
        }
    }
    x += 10;  // font character width

    // Only for debug
    // Only for debug
    // Only for debug
    
    bool debug = false;
    if(debug)
    {
        sprintf(str, "%d", gDebug);
        UI_PrintStringSmallBufferNormal(str, line + x + 1);
        x += 16;
    }
    else
    {

    #ifdef ENABLE_VOICE
        // VOICE indicator
        if (gEeprom.VOICE_PROMPT != VOICE_PROMPT_OFF){
            memcpy(line + x, BITMAP_VoicePrompt, sizeof(BITMAP_VoicePrompt));
            x1 = x + sizeof(BITMAP_VoicePrompt);
        }
        x += sizeof(BITMAP_VoicePrompt);
    #endif

        if(!SCANNER_IsScanning()) {
        #ifdef ENABLE_FEAT_F4HWN_RX_TX_TIMER
            if(gCurrentFunction == FUNCTION_TRANSMIT && gSetting_set_tmr == true)
            {
                convertTime(line, 0);
            }
            else if(FUNCTION_IsRx() && gSetting_set_tmr == true)
            {
                convertTime(line, 1);
            }
            else
        #endif
            {
                uint8_t dw = (gEeprom.DUAL_WATCH != DUAL_WATCH_OFF) + (gEeprom.CROSS_BAND_RX_TX != CROSS_BAND_OFF) * 2;
                if(dw == 1 || dw == 3) { // DWR - dual watch + respond
                    if(gDualWatchActive)
                        memcpy(line + x + (dw==1?0:2), gFontDWR, sizeof(gFontDWR) - (dw==1?0:5));
                    else
                        memcpy(line + x + 3, gFontHold, sizeof(gFontHold));
                }
                else if(dw == 2) { // XB - crossband
                    memcpy(line + x + 2, gFontXB, sizeof(gFontXB));
                }
                else
                {
                    memcpy(line + x + 2, gFontMO, sizeof(gFontMO));
                }
            }
        }
        x += sizeof(gFontDWR) + 3;
    }

#ifdef ENABLE_VOX
    // VOX indicator
    if (gEeprom.VOX_SWITCH) {
        memcpy(line + x, gFontVox, sizeof(gFontVox));
        x1 = x + sizeof(gFontVox) + 1;
    }
    x += sizeof(gFontVox) + 3;
#endif

#ifdef ENABLE_FEAT_F4HWN
    // PTT indicator
    if (gSetting_set_ptt_session) {
        memcpy(line + x, gFontPttOnePush, sizeof(gFontPttOnePush));
        x1 = x + sizeof(gFontPttOnePush) + 1;
    }
    else
    {
        memcpy(line + x, gFontPttClassic, sizeof(gFontPttClassic));
        x1 = x + sizeof(gFontPttClassic) + 1;       
    }
    x += sizeof(gFontPttClassic) + 3;
#endif

    x = MAX(x1, 70u);

    // KEY-LOCK indicator
    if (gEeprom.KEY_LOCK) {
        memcpy(line + x + 1, gFontKeyLock, sizeof(gFontKeyLock));
    }
    else if (gWasFKeyPressed) {
        memcpy(line + x + 1, gFontF, sizeof(gFontF));
        /*
        UI_PrintStringSmallBufferNormal("F", line + x + 1);
        
        for (uint8_t i = 71; i < 79; i++)
        {
            gStatusLine[i] ^= 0x7F;
        }
        */
    }
    else if (gBackLight)
    {
        memcpy(line + x + 1, gFontLight, sizeof(gFontLight));
    }
    #ifdef ENABLE_FEAT_F4HWN_CHARGING_C
    else if (gChargingWithTypeC)
    {
        memcpy(line + x + 1, BITMAP_USB_C, sizeof(BITMAP_USB_C));
    }
    #endif
    
    // Battery
    unsigned int x2 = LCD_WIDTH - sizeof(BITMAP_BatteryLevel1) - 0;

    UI_DrawBattery(line + x2, gBatteryDisplayLevel, gLowBatteryBlink);

    switch (gSetting_battery_text) {
        default:
        case 0:
            break;

        case 1: {   // voltage
            const uint16_t voltage = (gBatteryVoltageAverage <= 999) ? gBatteryVoltageAverage : 999; // limit to 9.99V
#ifdef ENABLE_FEAT_F4HWN
            sprintf(str, "%u.%02u", voltage / 100, voltage % 100);
#else
            sprintf(str, "%u.%02uV", voltage / 100, voltage % 100);
#endif
            break;
        }

        case 2:     // percentage
            sprintf(str, "%u%%", BATTERY_VoltsToPercent(gBatteryVoltageAverage));
            break;
    }

    x2 -= (7 * strlen(str));
    UI_PrintStringSmallBufferNormal(str, line + x2);

    // **************

    ST7565_BlitStatusLine();
}
