#include <string>
#include <iostream>
#include <boost/program_options.hpp>
#include "versioner.h"

using namespace std;

namespace po = boost::program_options;

int main(int argc, char** argv) {
    po::options_description desc("Allowed options");
    try {
        desc.add_options()
            ("help", "produce help message")
            ("version", "print program version, revision and exit");
        po::variables_map options;
        po::store(po::parse_command_line(argc, argv, desc), options);
        po::notify(options);

        if(options.count("help")) {
            cout << desc << endl;
            return 1;
        }
        if(options.count("version")) {
            cout << "version: " << Versioner::getVersion() << endl;
            cout << "revision: " << Versioner::getRevision() << endl;
            return 1;
        }
    } catch(const po::unknown_option& error) {
        cout << error.what() << endl;
        cout << desc << endl;
        return 1;
    }

    cout << "Hello, World!" << endl;
    
    return 0;
}
