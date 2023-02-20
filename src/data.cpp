#include <fstream>
#include <iostream>
#include "config.h"
#include "data.h"

Json_data *Json_data::instance = 0;

Json_data *Json_data::getSingletonInstance()
{
    VTRACE(NULL, "IN");
    if (!instance)
        instance = new Json_data;
    return instance;
    VTRACE(NULL, "OUT");
}

bool Json_data::readData()
{
    VTRACE(NULL, "IN");
    std::ifstream data_file(DATA_PATH);
    if (data_file.is_open())
    {
        json _midJson = json::parse(data_file);
        for (json::iterator iter = _midJson.begin(); iter != _midJson.end(); ++iter)
        {
            _JsonData.emplace_back(iter.value());
        }
        return VTRUE;
    }
    data_file.close();
    VTRACE(MsgTypes::ERR, "File read failed!\t OUT");
    return VERROR;
}

bool Json_data::initialization()
{
    VTRACE(NULL, "IN");

    if (!this->readData())
        return VERROR;
    // So far, we have information available for 233 countries and territories at most
    for (int i = 0; i < NUM_OF_CT_2023; ++i)
    {
        for (json::iterator iter = _JsonData[i].begin(); iter != _JsonData[i].end(); ++iter)
        {
            if (iter.key() == "a01")
                VecEngAbb.emplace_back((std::string)iter.value());
            else if (iter.key() == "a02")
                VecCont.emplace_back((std::string)iter.value());
            else if (iter.key() == "a03")
                VecSoTN.emplace_back((std::string)iter.value());
            else if (iter.key() == "a04")
                VecDate.emplace_back((std::string)iter.value());
            else if (iter.key() == "a11")
                VecTotalPop.emplace_back(atoi(std::string(iter.value()).c_str()));
            else if (iter.key() == "a05")
                VecTotalDiag.emplace_back(atoi(std::string(iter.value()).c_str()));
            else if (iter.key() == "a08")
                VecTotalDiagPerM.emplace_back(atof(std::string(iter.value()).c_str()));
            else if (iter.key() == "a06")
                VecNewIncDiag.emplace_back(atoi(std::string(iter.value()).c_str()));
            else if (iter.key() == "a09")
                VecNewIncDiagPerM.emplace_back(atof(std::string(iter.value()).c_str()));
            else if (iter.key() == "a07")
                VecWeekAvNewIncDiag.emplace_back(atof(std::string(iter.value()).c_str()));
            else if (iter.key() == "a10")
                VecWeekAvNewIncrDiagPerM.emplace_back(atof(std::string(iter.value()).c_str()));
            else
                continue;
        }
    }
    VTRACE(NULL, "OUT");
}

void Json_data::printData()
{
    VTRACE(NULL, "IN");

    if (empty())
        VTRACE(MsgTypes::ERR, "_JsonData is empty!");

    for (int i = 0; i < (int)_JsonData.size(); ++i)
    {
        std::cout << "区域英文缩写： " << VecEngAbb.at(i) << "\n洲名： " << VecCont.at(i) << "\n国家/地区: " << VecSoTN.at(i)
                  << "\n日期: " << VecDate.at(i) << "\n总确诊数: " << VecTotalDiag.at(i) << "\n新增确诊数: " << VecNewIncDiag.at(i)
                  << "\n七天平均新增确诊数: " << VecWeekAvNewIncDiag.at(i) << "\n总确诊数/百万人: " << VecTotalDiagPerM.at(i)
                  << "\n新增确诊数/百万人： " << VecNewIncDiagPerM.at(i) << "\n七天平均新增确诊数/百万人： " << VecWeekAvNewIncrDiagPerM.at(i)
                  << "\n总人口数: " << VecTotalPop.at(i) << std::endl
                  << std::endl;
    }

    std::cout << "Print Over." << std::endl;
    VTRACE(NULL, "OUT");
}

#define JSON_DATA_PARSING_STRING(str_funcname)              \
    std::vector<std::string> Json_data::get##str_funcname() \
    {                                                       \
        return Vec##str_funcname;                           \
    }

JSON_DATA_PARSING_STRING(Cont);
JSON_DATA_PARSING_STRING(EngAbb);
JSON_DATA_PARSING_STRING(SoTN);
JSON_DATA_PARSING_STRING(Date);

#define JSON_DATA_PARSING_INT(int_funcname)         \
    std::vector<int> Json_data::get##int_funcname() \
    {                                               \
        return Vec##int_funcname;                   \
    }

JSON_DATA_PARSING_INT(TotalPop);
JSON_DATA_PARSING_INT(TotalDiag);
JSON_DATA_PARSING_INT(NewIncDiag);

#define JSON_DATA_PARSING_FLOAT(float_funcname)         \
    std::vector<float> Json_data::get##float_funcname() \
    {                                                   \
        return Vec##float_funcname;                     \
    }

JSON_DATA_PARSING_FLOAT(TotalDiagPerM);
JSON_DATA_PARSING_FLOAT(NewIncDiagPerM);
JSON_DATA_PARSING_FLOAT(WeekAvNewIncDiag);
JSON_DATA_PARSING_FLOAT(WeekAvNewIncrDiagPerM);