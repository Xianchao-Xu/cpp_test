#include <fstream>
#include <iostream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "请输入需要解析的json文件名。\n";
        return 1;
    }

    std::ifstream f(argv[1]);
    json data = json::parse(f);

    for (const auto& item : data.items())
    {
        std::cout << "key: " << item.key() << std::endl;
    }
}
