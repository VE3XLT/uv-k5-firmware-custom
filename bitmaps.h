
#ifndef BITMAP_H
#define BITMAP_H

#include <stdint.h>

extern const uint8_t gFontPowerSave[2][6];
extern const uint8_t gFontPttOnePush[2][6];
extern const uint8_t gFontPttClassic[2][6];
extern const uint8_t gFontF[1][8];
extern const uint8_t gFontS[1][6];

extern const uint8_t gFontKeyLock[1][9];
extern const uint8_t gFontLight[9];

extern const uint8_t gFontXB[2][6];
extern const uint8_t gFontMO[2][6];
extern const uint8_t gFontDWR[3][6];
extern const uint8_t gFontHold[2][5];

extern const uint8_t BITMAP_BatteryLevel[2];
extern const uint8_t BITMAP_BatteryLevel1[17];
extern const uint8_t BITMAP_USB_C[9];
extern const uint8_t BITMAP_Ready[7];

#ifdef ENABLE_VOX
    extern const uint8_t gFontVox[2][6];
#endif

extern const uint8_t BITMAP_Antenna[5];
extern const uint8_t BITMAP_VFO_Default[7];
extern const uint8_t BITMAP_VFO_NotDefault[7];
extern const uint8_t BITMAP_VFO_Lock[7];
extern const uint8_t BITMAP_ScanList0[7];
extern const uint8_t BITMAP_ScanList1[7];
extern const uint8_t BITMAP_ScanList2[7];
extern const uint8_t BITMAP_ScanList3[7];
extern const uint8_t BITMAP_ScanList123[19];
extern const uint8_t BITMAP_ScanListAll[19];
extern const uint8_t BITMAP_ScanListE[7];
extern const uint8_t BITMAP_PowerUser[3];
extern const uint8_t BITMAP_compand[6];

#ifdef ENABLE_NOAA
	extern const uint8_t BITMAP_NOAA[11];
#endif

#ifndef ENABLE_CUSTOM_MENU_LAYOUT
    extern const uint8_t BITMAP_CurrentIndicator[8];
#endif

#endif
