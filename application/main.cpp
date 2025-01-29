#include "argparse.h"


int main(int argc, char * argv[])
{
    auto parser = argparse::ArgumentParser();
    parser.add_argument("positional");
    parser.add_argument("--optional");
    parser.add_argument("-v", "--version").action(argparse::version).version("prealpha");
    parser.parse_args(argc, argv);
}
