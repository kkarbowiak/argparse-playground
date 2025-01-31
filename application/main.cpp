#include "argparse.h"
#include <string>
#include <iostream>


int main(int argc, char * argv[])
{
    using namespace std::string_literals;

    auto parser = argparse::ArgumentParser();
    parser.add_argument("pos1");
    parser.add_argument("pos2");
    parser.add_argument("-o", "--opt1");
    parser.add_argument("-p", "--opt2");
    parser.add_argument("-f", "--flag").action(argparse::store_true);
    parser.add_argument("-v", "--version").action(argparse::version).version("1.0.0");
    auto const args = parser.parse_args(argc, argv);
    auto const pos1 = args.get("pos1");
    auto const pos2 = args.get("pos2");
    auto const opt1 = args.get("opt1");
    auto const opt2 = args.get("opt2");
    auto const flag = args.get("flag");
    auto const ver = args.get("version");
    std::cout << "pos1: " << (pos1 ? pos1.get() : "<none>"s) << '\n';
    std::cout << "pos2: " << (pos2 ? pos2.get() : "<none>"s) << '\n';
    std::cout << "opt1: " << (opt1 ? opt1.get() : "<none>"s) << '\n';
    std::cout << "opt2: " << (opt2 ? opt2.get() : "<none>"s) << '\n';
    std::cout << "flag: " << (flag.get<bool>() ? "true"s : "false"s) << '\n';
    std::cout << "ver: " << (ver.get<bool>() ? "true"s : "false"s) << '\n';
}
