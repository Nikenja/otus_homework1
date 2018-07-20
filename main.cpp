#include <iostream>
#include "lib.h"

using namespace std;

int main(int argc, char** argv) {
    cout << "Hello, World!" << endl;
    cout << "Version: " << Version::getVersion() << endl;
    return 0;
}
