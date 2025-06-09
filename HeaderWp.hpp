#ifndef CPUMP_LIB_H
#define CPUMP_LIB_H

#include <Arduino.h>
#include <string.h>

namespace cpump_Lib {

class __Base__ {
public:
private:
    friend class Bombs;
protected:
    struct PumpData {
        uint8_t pin;
        bool state;
    } _pump_;

    __Base__(uint8_t pin, bool state);
    virtual ~__Base__(void);

    virtual void swapState(bool toChange = 0) = 0;
    virtual void analogPower(uint8_t value) = 0;
    bool getState() const { return _pump_.state; }
};

inline namespace ScopeInternal {
    class Bombs final : public __Base__ {
    private:
        uint8_t power;

    public:
        using __Base__::getState;
        friend class __Base__;

        explicit Bombs(uint8_t pin, bool state, uint8_t powerLevel = 0);
        void swapState(bool toChange = 0x00) override;
        void analogPower(uint8_t value = 0x00) override;

        Bombs& operator+=(uint8_t&& value = 0x00);
        Bombs& operator-=(uint8_t&& value = 0x00);
        Bombs& operator|=(uint8_t&& value = 0x00);
        Bombs& operator^=(uint8_t&& value = 0x00);
        Bombs& operator++(uint8_t&& value = 0x00);
        Bombs& operator--(uint8_t&& value = 0x00);
        Bombs& operator=(const char* ASCII = "");

        ~Bombs(void);
    };
} // namespace ScopeInternal
} // namespace cpump_Lib

#endif // CPUMP_LIB_H
