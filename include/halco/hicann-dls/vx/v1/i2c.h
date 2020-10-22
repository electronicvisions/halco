#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/i2c.h"

namespace halco::hicann_dls::vx::v1 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V1 {

using I2CIdRegisterOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::I2CIdRegisterOnBoard;
using I2CINA219RoRegisterOnINA219 GENPYBIND(visible) =
    halco::hicann_dls::vx::I2CINA219RoRegisterOnINA219;
using I2CINA219RwRegisterOnINA219 GENPYBIND(visible) =
    halco::hicann_dls::vx::I2CINA219RwRegisterOnINA219;
using I2CINA219RoRegisterOnBoard GENPYBIND(visible) =
    halco::hicann_dls::vx::I2CINA219RoRegisterOnBoard;
using I2CINA219RwRegisterOnBoard GENPYBIND(visible) =
    halco::hicann_dls::vx::I2CINA219RwRegisterOnBoard;
using I2CTCA9554RoRegisterOnTCA9554 GENPYBIND(visible) =
    halco::hicann_dls::vx::I2CTCA9554RoRegisterOnTCA9554;
using I2CTCA9554RwRegisterOnTCA9554 GENPYBIND(visible) =
    halco::hicann_dls::vx::I2CTCA9554RwRegisterOnTCA9554;
using I2CTCA9554RoRegisterOnBoard GENPYBIND(visible) =
    halco::hicann_dls::vx::I2CTCA9554RoRegisterOnBoard;
using I2CTCA9554RwRegisterOnBoard GENPYBIND(visible) =
    halco::hicann_dls::vx::I2CTCA9554RwRegisterOnBoard;

} // namespace halco::hicann_dls::vx::v1
