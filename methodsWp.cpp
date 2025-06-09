#include "HeaderWp.hpp"

namespace cpump_Lib {

__Base__::__Base__(uint8_t pin, bool state) : _pump_{pin, state} {
    pinMode(_pump_.pin, OUTPUT);
    digitalWrite(_pump_.pin, _pump_.state);
}

__Base__::~__Base__(void) {
    pinMode(_pump_.pin, INPUT);
    digitalWrite(_pump_.pin, LOW);
}

Bombs::Bombs(uint8_t pin, bool state, uint8_t powerLevel)
    : __Base__(pin, state), power(powerLevel) {}

void Bombs::swapState(bool toChange) {
    _pump_.state ^= !toChange;
    digitalWrite(_pump_.pin, _pump_.state);
}

void Bombs::analogPower(uint8_t value) {
    power = (value & ~(0b00000000));
    analogWrite(_pump_.pin, power);
}

void Bombs::closeObj(void) {
    pinMode(_pump_.pin, INPUT);
    digitalWrite(_pump_.pin, LOW);
}

Bombs& Bombs::operator+=(uint8_t&& value) {
    power = (power + (value & 0xFF)) & 0xFF;
    analogWrite(_pump_.pin, power);
    return *this;
}

Bombs& Bombs::operator-=(uint8_t&& value) {
    power = (power - (value & 0xFF)) & 0xFF;
    analogWrite(_pump_.pin, power);
    return *this;
}

Bombs& Bombs::operator|=(uint8_t&& value) {
    power |= (value & ~(0b0000000));
    analogWrite(_pump_.pin, power);
    return *this;
}

Bombs& Bombs::operator^=(uint8_t&& value) {
    value = (value > 1) ? 1 : (value < 1) ? 0 : 0;
    digitalWrite(_pump_.pin, value);
    return *this;
}

Bombs& Bombs::operator++(uint8_t&&) {
    ++power;
    analogWrite(_pump_.pin, (power & 0xFF));
    return *this;
}

Bombs& Bombs::operator--(uint8_t&&) {
    --power;
    analogWrite(_pump_.pin, (power & 0xFF));
    return *this;
}

Bombs& Bombs::operator=(const char* ASCII) {
    unsigned short powerL{0};
    for (size_t i = 0; i < strlen(ASCII); ++i) powerL += ASCII[i];
    powerL -= (powerL > 0xFF) ? 0xAA : 0x00;
    analogWrite(_pump_.pin, powerL);
    return *this;
}

Bombs::~Bombs(void) = default;

} // namespace cpump_Lib
