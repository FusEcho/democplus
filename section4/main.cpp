#include <cassert>
#include <cpr/cpr.h>
#include <iostream>

using namespace std;

void case1() {

    const auto url = "http://openresty.org"s;

    auto res = cpr::Get(cpr::Url{url});

    std::cout << res.elapsed << std::endl;

    std::cout << res.url << std::endl;
    std::cout << res.status_code << std::endl;
    std::cout << res.text.length() << std::endl;

    for (auto &x : res.header) {
        std::cout << x.first << "=>" << x.second << std::endl;
    }
}

void case2() {

    const auto url = "http://openresty.org"s;

    auto res1 = cpr::Head(cpr::Url{url});
    assert(res1.text.empty());

    auto res2 = cpr::Get(cpr::Url{url}, cpr::Parameters{{"a", "1"}, {"b", "2"}});

    auto res3 = cpr::Post(cpr::Url{url}, cpr::Header{{"x", "xxx"}, {"expect", ""}}, cpr::Body{"post data"}, cpr::Timeout{200ms});
}

void case3() {
    auto f = cpr::GetAsync(cpr::Url{"http://openresty.org"});

    auto res = f.get();

    std::cout << res.elapsed << std::endl;

    for (auto &x : res.header) {
        std::cout << x.first << "=>" << x.second << std::endl;
    }
}

int main() {

    case1();
    case2();
    case3();

    return 0;
}