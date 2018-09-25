#include <iostream>
#include <boost/program_options.hpp>
#include "versioner.h"

using namespace std;

namespace options = boost::program_options;

int main(int argc, char** argv) {
    try {
        options::option_description desc("Allowed options");
        // desc.add_options()("help", "produce help message");
    } catch(...) {

    }
    cout << "Hello, World!" << endl;

    cout << "Version: " << Versioner::getVersion() << endl;
    cout << "Revision: " << Versioner::getRevision() << endl;
    return 0;
}
