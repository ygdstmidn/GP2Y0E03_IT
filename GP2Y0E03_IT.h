/// @copyright Copyright © 2025 ygdstmidn
/// @license This file is released under the MIT License(https://opensource.org/license/mit)
#ifndef __INCLUDE_GP2Y0E03_IT_H
#define __INCLUDE_GP2Y0E03_IT_H

#include <main.h>
#include <I2CInterruptSystem/I2CInterruptSystem.h>

namespace GP2Y0E03_IT
{
    /// 8bit
    constexpr uint8_t SLAVE_ADDRESS_LIST[16] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0};

    constexpr uint8_t LOCATION_ShiftBit = 0x02;
    constexpr uint8_t LOCATION_Distance = 0x5E;
    constexpr uint8_t LOCATION_Distance2 = 0x5F;

    constexpr uint8_t DEFAULT_ShiftBit = 0x02;

    class GP2Y0E03_IT
    {
    public:
        GP2Y0E03_IT(I2CInterruptSystem::I2CInterruptSystem *i2cITSystem, uint8_t address);
        ~GP2Y0E03_IT(void);
        void setup_read(void);
        double read(void);

    private:
        I2CInterruptSystem::I2CInterruptSystem *_i2cITSystem;
        unsigned int _i2cITSystemIndex = 0;
        uint8_t _address;
        uint8_t _ShiftBit = DEFAULT_ShiftBit;
        uint8_t _rxArray[2]; // 最長:distanceのデータ
    };
} // namespace GP2Y0E03_IT

#endif // __INCLUDE_GP2Y0E03_IT_H