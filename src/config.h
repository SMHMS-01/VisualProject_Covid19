#include <stdio.h>
#include <string>

// bool macros
#define VERROR 0
#define VTRUE 1

// Data File Path
#define DATA_PATH "res/covid19.json"

// Print Log
#define TRACE(enum_value, str)                                                                                         \
    switch (enum_value)                                                                                                \
    {                                                                                                                  \
    case MsgTypes::LOG:                                                                                                \
        printf("Date:%s Time:%s  Func:%s  Row:%d   LOG_Content: %s", __DATE__, __TIME__, __FUNCTION__, __LINE__, str); \
        break;                                                                                                         \
    case MsgTypes::ERR:                                                                                                \
        printf("Date:%s Time:%s  Func:%s  Row:%d   ERR_Content: %s", __DATE__, __TIME__, __FUNCTION__, __LINE__, str); \
        break;                                                                                                         \
    default:                                                                                                           \
        break;                                                                                                         \
    }

// Enumnate value
enum MsgTypes
{
    LOG,
    ERR
};

constexpr unsigned int INFINITE = INT_MAX;
constexpr unsigned int MAX = INFINITE;
constexpr unsigned int MIN = 0;