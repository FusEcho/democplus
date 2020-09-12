#include "json.hpp"

#include <iostream>

using json_t = nlohmann::json;

void case2()
{
    std::string str = R"({
        "name": "happy",
        "age" : 23,
    })";

    auto j = json_t::parse(str);

    assert(j["age"] == 23);
    assert(j["name"] == "happy");

    std::cout << j["name"] << std::endl;
}

int main()
{
    json_t j;
    j["age"]           = 23;
    j["name"]          = "haha";
    j["gear"]["suits"] = "2020";
    j["jobs"]          = {"superhero", "hahahh"};

    std::vector<int> v = {1, 2, 3};
    j["numbers"]       = v;

    std::map<std::string, int> m = {{"one", 1}, {"two", 2}};
    j["kv"]                      = m;

    std::cout << j.dump() << std::endl;
    std::cout << j.dump(2) << std::endl;

    case2();
    return 0;
}