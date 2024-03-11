
#ifndef BITMAP_H
#define BITMAP_H

#include <stdint.h>

extern const uint8_t gFontPowerSave[2][6];
extern const uint8_t gFontTx[1][5];
extern const uint8_t gFontRx[1][5];
extern const uint8_t gFontPttOnePush[2][6];
extern const uint8_t gFontPttClassic[2][6];
extern const uint8_t gFontFM[2][6];
extern const uint8_t gFontKeyLock[1][8];
extern const uint8_t gFontScanAll[10];
extern const uint8_t gFontLight[10];

extern const uint8_t gFontXB[2][6];
extern const uint8_t gFontMO[2][6];
extern const uint8_t gFontDWR[3][6];
extern const uint8_t gFontHold[2][5];

extern const uint8_t BITMAP_BatteryLevel[2];
extern const uint8_t BITMAP_BatteryLevel1[17];
extern const uint8_t BITMAP_USB_C[9];

#ifdef ENABLE_VOX
	extern const uint8_t gFontVox[2][6];
#endif

extern const uint8_t BITMAP_Antenna[5];
extern const uint8_t BITMAP_VFO_Default[8];
extern const uint8_t BITMAP_VFO_NotDefault[8];
extern const uint8_t BITMAP_ScanList1[6];
extern const uint8_t BITMAP_ScanList2[6];
extern const uint8_t BITMAP_compand[6];

#ifndef ENABLE_CUSTOM_MENU_LAYOUT
	extern const uint8_t BITMAP_CurrentIndicator[8];
#endif

#endif
