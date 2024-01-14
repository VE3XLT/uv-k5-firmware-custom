
#ifdef VERSION_STRING
	#define VER     " "VERSION_STRING
#else
	#define VER     ""
#endif

#ifdef ENABLE_FEAT_F4HWN
	const char Version[]      = AUTHOR_STRING " v0.21+";
	const char UART_Version[] = "UV-K5 Firmware, Open Edition, " AUTHOR_STRING "\r\n";
	const char Feat[]         = "Feat " FEAT_STRING;
#else
	const char Version[]      = AUTHOR_STRING VER;
	const char UART_Version[] = "UV-K5 Firmware, Open Edition, " AUTHOR_STRING VER "\r\n";
#endif