#pragma once
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Json_data
{
public:
    static Json_data *getSingletonInstance();
    bool empty() const noexcept { return data.empty(); }
    std::vector<json> getData() const noexcept { return this->data; }
    void printData();

protected:
    bool readData();

private:
    static Json_data *instance;
    Json_data() { data = {}; }
    std::vector<json> data;
};