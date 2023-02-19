#include <stdio.h>
#include <string>

// bool macros
#define VERROR 0
#define VTRUE 1

// Data File Path
#define DATA_PATH "res/covid19.json"

// Print Log
#define VTRACE(enum_value, str)                                                                                          \
    switch (enum_value)                                                                                                  \
    {                                                                                                                    \
    case MsgTypes::LOG:                                                                                                  \
        printf("Date:%s Time:%s  Func:%s  Row:%d   LOG_Content: %s\n", __DATE__, __TIME__, __FUNCTION__, __LINE__, str); \
        break;                                                                                                           \
    case MsgTypes::ERR:                                                                                                  \
        printf("Date:%s Time:%s  Func:%s  Row:%d   ERR_Content: %s\n", __DATE__, __TIME__, __FUNCTION__, __LINE__, str); \
        break;                                                                                                           \
    default:                                                                                                             \
        printf("Date:%s Time:%s  Func:%s  Row:%d   Content: %s\n", __DATE__, __TIME__, __FUNCTION__, __LINE__, str);     \
        break;                                                                                                           \
    }

// Enumnate value
enum MsgTypes
{
    LOG = 1,
    ERR
};

// The total number of countries and territories in the world by 2023
constexpr unsigned int NUM_OF_CT_2023 = 233;
constexpr unsigned int INFINITE = INT_MAX;
constexpr unsigned int MAX = INFINITE;
constexpr unsigned int MIN = 0;
