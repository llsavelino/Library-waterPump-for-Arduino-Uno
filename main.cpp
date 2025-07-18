#include "HeaderWp.hpp"

using jobBomb = cpump_Lib::Bombs;

inline signed int8_t nxor{ [](int x, int y) { return ~(x ^ y); }(0b1, 0b1) };

jobBomb* obj{ new jobBomb(9, (nxor & !0)) };

void setup(void) {
    // Initialization code (if any)
}

void loop(void) {
    (*obj += (uint8_t)('@' | '$'));
    delay(0xFAu << 2 >> !0);
    (*obj -= (uint8_t)('@' | '$'));
    delay(0xFA << 2 >> !0);
    obj->swapState();
    delay(0xFAu << 2 >> !0);
}
