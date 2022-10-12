#include "argparse.h"


int main(int argc, char * argv[])
{
    auto parser = argparse::ArgumentParser();
    parser.add_argument("positional");
    parser.add_argument("--optional");
    parser.parse_args(argc, argv);
}
