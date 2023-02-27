#pragma once
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Json_data
{
public:
    static Json_data *getSingletonInstance();
    bool empty() noexcept
    {
        return _JsonData.empty();
    }
    std::vector<json> getJsonData() const noexcept
    {
        return this->_JsonData;
    }

    // Print Curr Json Data with string
    void printData();

    // Continent
    std::vector<std::string> getCont();
    // English Abbreviation
    std::vector<std::string> getEngAbb();
    // names of States or Territories
    std::vector<std::string> getSoTN();
    std::vector<std::string> getDate();
    // Total Population
    std::vector<int> getTotalPop();
    // Total Diagnosis
    std::vector<int> getTotalDiag();
    // Newly Increased Diagnosis
    std::vector<int> getNewIncDiag();
    // Total Diagnosis Per Millions
    std::vector<float> getTotalDiagPerM();
    // Newly Increased Diagnosis Per Millions
    std::vector<float> getNewIncDiagPerM();
    // Weekly Average Newly Increased Diagnosis
    std::vector<float> getWeekAvNewIncDiag();
    // Weekly Average Newly Increased Diagnosis Per Millions
    std::vector<float> getWeekAvNewIncDiagPerM();

private:
    static Json_data *instance;

    Json_data()
    {
        _JsonData = {};
        initialization();
        printData();
    }

    std::vector<json> _JsonData;
    std::vector<std::string> VecEngAbb;
    std::vector<std::string> VecCont;
    std::vector<std::string> VecSoTN;
    std::vector<std::string> VecDate;
    std::vector<int> VecTotalDiag;
    std::vector<int> VecTotalPop;
    std::vector<int> VecNewIncDiag;
    std::vector<float> VecTotalDiagPerM;
    std::vector<float> VecNewIncDiagPerM;
    std::vector<float> VecWeekAvNewIncDiag;
    std::vector<float> VecWeekAvNewIncDiagPerM;

    bool readData();
    bool initialization();
};
