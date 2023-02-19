#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include "data.h"

using json = nlohmann::json;

void foo()
{
	std::ifstream f("res/geojson.json");
	if (!f.is_open())
		std::cerr << "Open file failed!" << std::endl;

	json jf = json::parse(f);
	std::vector<json> vj;

	json::iterator iter = jf.begin();

	for (int i = 0; iter != jf.end(); iter++)
		if (iter.key() == "features")
		{
			json tmp_j = iter.value();
			for (json::iterator ij = tmp_j.begin(); ij != tmp_j.end(); ij++)
				vj.emplace_back(ij.value());
		}
}
int main(int argc, char *argv[])
{
	Json_data *jd = Json_data::getSingletonInstance();

	// foo();
}