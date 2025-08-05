/// @copyright Copyright © 2025 ygdstmidn
/// @license This file is released under the MIT License(https://opensource.org/license/mit)

#include "GP2Y0E03_IT.h"

namespace GP2Y0E03_IT
{
    GP2Y0E03_IT::GP2Y0E03_IT(I2CInterruptSystem::I2CInterruptSystem *i2cITSystem, uint8_t address)
    {
        _i2cITSystem = i2cITSystem;
        _address = address;
    }

    GP2Y0E03_IT::~GP2Y0E03_IT()
    {
    }

    void GP2Y0E03_IT::setup_read(void)
    {
        _i2cITSystemIndex = _i2cITSystem->addMemRead(_address, LOCATION_Distance, 2, _rxArray, 2);
    }

    double GP2Y0E03_IT::read(void)
    {
        if (_i2cITSystem->sendCheck(_i2cITSystemIndex) == 0)
        {
            return -1.0; // エラー
        }
        double distance = (_rxArray[0] << 4 | _rxArray[1]) / 16.0;
        for (int i = 0; i < _ShiftBit; i++)
        {
            distance /= 2;
        }
        return distance;
    }
} // namespace GP2Y0E03_IT