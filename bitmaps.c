
#include "bitmaps.h"

// all these images are on their right sides
// turn your monitor 90-deg anti-clockwise to see the images

const uint8_t gFontPowerSave[2][6] =
{
    {0x00, 0x7f, 0x9, 0x9, 0x9, 0x6},
    {0x00, 0x26, 0x49, 0x49, 0x49, 0x32},
};

const uint8_t gFontPttOnePush[2][6] =
{
    {0x00, 0x3e, 0x41, 0x41, 0x41, 0x3e},
    {0x00, 0x7f, 0x9, 0x9, 0x9, 0x6},
};

const uint8_t gFontPttClassic[2][6] =
{
    {0x00, 0x3e, 0x41, 0x41, 0x41, 0x22},
    {0x00, 0x7f, 0x40, 0x40, 0x40, 0x40},
};

const uint8_t gFontF[1][8] =
{
    {0x7f, 0x00, 0x76, 0x76, 0x76, 0x76, 0x7e, 0x7f}, // 'F'
};

const uint8_t gFontS[1][6] =
{
    {0x26, 0x49, 0x49, 0x49, 0x49, 0x32}, // 'S'
};

const uint8_t gFontKeyLock[1][9] =
{
    {0x7c, 0x46, 0x45, 0x45, 0x45, 0x45, 0x45, 0x46, 0x7c}
};

const uint8_t gFontLight[9] =
{
    0b00001100,
    0b00010010,
    0b00100001,
    0b01101101,
    0b01111001,
    0b01101101,
    0b00100001,
    0b00010010,
    0b00001100,
};

const uint8_t gFontXB[2][6] =
{   // "XB"
    {0x00, 0x63, 0x14, 0x8, 0x14, 0x63},
    {0x00, 0x7f, 0x49, 0x49, 0x49, 0x36},
};

const uint8_t gFontMO[2][6] =
{   // "MO"
    {0x00, 0x7f, 0x2, 0x1c, 0x2, 0x7f},
    {0x00, 0x3e, 0x41, 0x41, 0x41, 0x3e},
};

const uint8_t gFontDWR[3][6] =
{   // "DWR"

    {0x00, 0x7f, 0x41, 0x41, 0x41, 0x3e},
    {0x00, 0x3f, 0x40, 0x38, 0x40, 0x3f},
    {0x00, 0x7f, 0x9, 0x19, 0x29, 0x46},
};

const uint8_t gFontHold[2][5] =
{   // "><" .. DW on hold
    {0x00, 0x41, 0x22, 0x14, 0x8},
    {0x00, 0x8, 0x14, 0x22, 0x41},
};

const uint8_t BITMAP_BatteryLevel[2] =
{
    0b01011101,
    0b01011101
};

// Quansheng way (+ pole to the left)
const uint8_t BITMAP_BatteryLevel1[17] =
{
    0b00000000,
    0b00111110,
    0b00100010,
    0b01000001,
    0b01000001,
    0b01000001,
    0b01000001,
    0b01000001,
    0b01000001,
    0b01000001,
    0b01000001,
    0b01000001,
    0b01000001,
    0b01000001,
    0b01000001,
    0b01000001,
    0b01111111
};

const uint8_t BITMAP_USB_C[9] =
{
    0b00000000,
    0b00011100,
    0b00100111,
    0b01000100,
    0b01000100,
    0b01000100,
    0b01000100,
    0b00100111,
    0b00011100
};

#ifdef ENABLE_VOX
    const uint8_t gFontVox[2][6] =
    {
        {0x00, 0x1f, 0x20, 0x40, 0x20, 0x1f},
        {0x00, 0x63, 0x14, 0x8, 0x14, 0x63},
    };
#endif

const uint8_t BITMAP_Antenna[5] =
{
    0b00000011,
    0b00000101,
    0b01111111,
    0b00000101,
    0b00000011
};

const uint8_t BITMAP_VFO_Lock[7] =
{
    0b01111100,
    0b01000110,
    0b01000101,
    0b01000101,
    0b01000101,
    0b01000110,
    0b01111100,
};

const uint8_t BITMAP_VFO_Default[7] =
{
    0b01111111,
    0b01111111,
    0b00111110,
    0b00111110,
    0b00011100,
    0b00011100,
    0b00001000
};

const uint8_t BITMAP_VFO_NotDefault[7] =
{
    0b01000001,
    0b01000001,
    0b00100010,
    0b00100010,
    0b00010100,
    0b00010100,
    0b00001000
};

const uint8_t BITMAP_ScanList0[7] =
{   // '0' symbol
    0b01111111,
    0b01111111,
    0b01000011,
    0b01011101,
    0b01100001,
    0b01111111,
    0b01111111
};

const uint8_t BITMAP_ScanList1[7] =
{   // '1' symbol
    0b01111111,
    0b01111111,
    0b01111011,
    0b01000001,
    0b01111111,
    0b01111111,
    0b01111111
};

const uint8_t BITMAP_ScanList2[7] =
{   // '2' symbol
    0b01111111,
    0b01111111,
    0b01001101,
    0b01010101,
    0b01011011,
    0b01111111,
    0b01111111
};

const uint8_t BITMAP_ScanList3[7] =
{   // '3' symbol
    0b01111111,
    0b01111111,
    0b01011101,
    0b01010101,
    0b01101011,
    0b01111111,
    0b01111111
};

const uint8_t BITMAP_ScanListE[7] =
{   // 'E' symbol
    0b01111111,
    0b01111111,
    0b01000001,
    0b01010101,
    0b01010101,
    0b01111111,
    0b01111111
};

const uint8_t BITMAP_ScanList123[19] =
{
    // 'All' symbol
    0b01111111,
    0b01111111,
    0b01111011,
    0b01000001,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01001101,
    0b01010101,
    0b01011011,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01011101,
    0b01010101,
    0b01101011,
    0b01111111,
    0b01111111
};

const uint8_t BITMAP_ScanListAll[19] =
{
    // 'All' symbol
    0b01111111,
    0b01111111,
    0b01000011,
    0b01110101,
    0b01000011,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01000001,
    0b01011111,
    0b01011111,
    0b01111111,
    0b01111111,
    0b01111111,
    0b01000001,
    0b01011111,
    0b01011111,
    0b01111111,
    0b01111111
};

const uint8_t BITMAP_compand[6] =
{
    0b00000000,
    0b00111100,
    0b01000010,
    0b01000010,
    0b01000010,
    0b00100100
};

const uint8_t BITMAP_Ready[7] =
{
    0b00001000,
    0b00010000,
    0b00100000,
    0b00010000,
    0b00001000,
    0b00000100,
    0b00000010,
};

const uint8_t BITMAP_PowerUser[3] =
{   // 'arrow' symbol
    0b00111110,
    0b00011100,
    0b00001000,
};

#ifdef ENABLE_NOAA
	const uint8_t BITMAP_NOAA[11] =
	{	// "NS"
		0b00000000,
		0b01111111,
		0b00000100,
		0b00001000,
		0b00010000,
		0b01111111,
		0b00000000,
		0b01000110,
		0b01001001,
		0b01001001,
		0b00110001
	};
#endif

#ifndef ENABLE_CUSTOM_MENU_LAYOUT
const uint8_t BITMAP_CurrentIndicator[8] = {
    0xFF,
    0xFF,
    0x7E,
    0x7E,
    0x3C,
    0x3C,
    0x18,
    0x18
};
#endif
