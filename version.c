
#ifdef VERSION_STRING
	#define VER     " "VERSION_STRING
#else
	#define VER     ""
#endif


const char Version[]      = AUTHOR_STRING VER;
const char UART_Version[] = "UV-K5 Firmware, Open Edition, " AUTHOR_STRING VER "\r\n";

#ifdef ENABLE_FEAT_F4HWN
	const char Feat[]         = "Feat " FEAT_STRING;
#endif