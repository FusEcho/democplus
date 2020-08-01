#include <iostream>
#include "json.hpp"

using json_t = nlohmann::json;

int main()
{
    json_t j;
    j["age"] = 23;
    j["name"] = "haha";
    j["gear"]["suits"] = "2020";
    j["jobs"] = {"superhero", "hahahh"};

    std::vector<int> v = {1,2,3};
    j["numbers"] = v;

    std::map<std::string, int> m = {{"one",1}, {"two", 2}};
    j["kv"] = m;

    std::cout << j.dump() << std::endl;
    std::cout << j.dump(2) << std::endl;

    return 0;
} 