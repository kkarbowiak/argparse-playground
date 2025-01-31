#include "argparse.h"
#include <string>
#include <iostream>


int main(int argc, char * argv[])
{
    using namespace std::string_literals;

    auto parser = argparse::ArgumentParser();
    parser.add_argument("positional");
    parser.add_argument("--optional");
    parser.add_argument("-v", "--version").action(argparse::version).version("1.0.0");
    auto const args = parser.parse_args(argc, argv);
    auto const pos = args.get("positional");
    auto const opt = args.get("optional");
    auto const ver = args.get("version");
    std::cout << "positional: " << (pos ? pos.get() : "<none>"s) << '\n';
    std::cout << "optional: " << (opt ? opt.get() : "<none>"s) << '\n';
    std::cout << "version: " << (ver ? ver.get<bool>() ? "true"s : "false"s : "<none>"s) << '\n';
}
