#include <fstream>
#include <iostream>
#include "config.h"
#include "data.h"

Json_data *Json_data::instance = 0;

Json_data *Json_data::getSingletonInstance()
{
    if (!instance)
        instance = new Json_data;
    return instance;
}

bool Json_data::readData()
{
    TRACE(MsgTypes::LOG, "");
    std::ifstream data_file(DATA_PATH);
    if (data_file.is_open())
    {
        json _midJson = json::parse(data_file);
        for (json::iterator iter = _midJson.begin(); iter != _midJson.end(); ++iter)
        {
            data.emplace_back(iter.value());
        }
        return VTRUE;
    }
    data_file.close();
    TRACE(MsgTypes::ERR, "File read failed!");
    return VERROR;
}

void Json_data::printData()
{
    TRACE(MsgTypes::LOG, "");

    if (!readData())
        return;

    for (int i = 0; i <= (int)data.size(); ++i)
    {
        for (json::iterator iter = data[i].begin(); iter != data[i].end(); ++iter)
        {
            if (iter.key() == "a01")
                std::cout << "英文缩写: " << (std::string)iter.value() << std::endl;
            else if (iter.key() == "a02")
                std::cout << "洲名 : " << (std::string)iter.value() << std::endl;
            else if (iter.key() == "a03")
                std::cout << "国家/地区 : " << (std::string)iter.value() << std::endl;
            else if (iter.key() == "a04")
                std::cout << "日期 : " << (std::string)iter.value() << std::endl;
            else if (iter.key() == "a07")
                std::cout << "总确诊数 : " << atof(std::string(iter.value()).c_str()) << std::endl;
            else if (iter.key() == "a08")
                std::cout << "新增确诊数 : " << atof(std::string(iter.value()).c_str()) << std::endl;
            else if (iter.key() == "a09")
                std::cout << "总确诊数/百万人 : " << atof(std::string(iter.value()).c_str()) << std::endl;
            else if (iter.key() == "a10")
                std::cout << "新增确诊数/百万人 : " << atof(std::string(iter.value()).c_str()) << std::endl;
            else if (iter.key() == "a11")
                std::cout << "总人口数 : " << atoi(std::string(iter.value()).c_str()) << std::endl;
            // else if (iter.key() == "id")
            //     std::cout << "ID : " << std::string(iter.value()) << std::endl;
            else
                continue;
        }
        std::cout << std::endl;
    }
}