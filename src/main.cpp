#include <iostream>
#include "json.hpp" // https://github.com/nlohmann/json

using namespace std;
using json = nlohmann::json;

void test_json();

int main(int argc, const char *argv[])
{
    try
    {
        test_json();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

void test_json()
{
    json j2 = {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {"answer", {{"everything", 42}}},
        {"list", {1, 0, 2}},
        {"object", {{"currency", "USD"}, {"value", 42.99}}}};

    cout << "pi = " << j2["pi"].dump() << endl;

    for (const auto &[key, value] : j2.items())
    {
        cout << key << ":" << value << endl;
    }
}