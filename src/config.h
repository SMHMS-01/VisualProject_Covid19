#include <stdio.h>
#include <string>
#include <windows.h>

// bool macros
#define VERROR 0
#define VTRUE 1

// Data File Path
#define DATA_PATH "res/covid19.json"

// Main date
int arr[6] = {14, 56, 140, 166, 181, 196};
// Print Log
#define VTRACE(LogType, ...)                                                                                                       \
    switch (LogType)                                                                                                               \
    {                                                                                                                              \
    case MsgTypes::LOG:                                                                                                            \
        printf("Date:%s Time:%s  Func:%s  Row:%d   LOG_Content: %s\n", __DATE__, __TIME__, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        break;                                                                                                                     \
    case MsgTypes::ERR:                                                                                                            \
        printf("Date:%s Time:%s  Func:%s  Row:%d   ERR_Content: %s\n", __DATE__, __TIME__, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        break;                                                                                                                     \
    default:                                                                                                                       \
        printf("Date:%s Time:%s  Func:%s  Row:%d   Content: %s\n", __DATE__, __TIME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);     \
        break;                                                                                                                     \
    }

// Enumnate value
enum MsgTypes
{
    LOG = 1,
    ERR
};

// The total number of countries and territories in the world by 2023
constexpr int NUM_OF_CT_2023 = 233;
constexpr unsigned int INFINITY = INT_MAX;
constexpr unsigned int MAX = INFINITY;
constexpr unsigned int MIN = 0;
