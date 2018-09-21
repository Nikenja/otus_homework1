#include <iostream>
#include "versioner.h"

using namespace std;
// add commet for test
int main() {
    cout << "Hello, World!" << endl;
    cout << "Version: " << Versioner::getVersion() << endl;
    cout << "Revision: " << Versioner::getRevision() << endl;
    return 0;
}
