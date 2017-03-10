#ifdef DEBUG
 #define DEBUG_INIT(x)    Serial.begin(x); while (!Serial);
 #define DEBUG_PRINT(x)   Serial.println(x)
 #define DEBUG_PRINT_(x)  Serial.print(x)
 #define DEBUG_PRINTD(x)  Serial.println(x, DEC)
#else
 #define DEBUG_INIT(x)
 #define DEBUG_PRINT(x)
 #define DEBUG_PRINT_(x)
 #define DEBUG_PRINTD(x)
#endif
