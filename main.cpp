#include "dismantler.h"
#include "d_exc.h"

int main() {
    try {
        dismatler d1;
        d1.init_file();
    }
    catch ( d_exc &e ) {
        std::cout << e.what();
    }
}
