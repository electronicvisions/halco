#include "halco/hicann-dls/vx/i2c.h"

namespace halco::hicann_dls::vx {

I2CINA219RoRegisterOnINA219 const I2CINA219RoRegisterOnINA219::shunt{0};
I2CINA219RoRegisterOnINA219 const I2CINA219RoRegisterOnINA219::bus{1};
I2CINA219RoRegisterOnINA219 const I2CINA219RoRegisterOnINA219::power{2};
I2CINA219RoRegisterOnINA219 const I2CINA219RoRegisterOnINA219::current{3};

I2CINA219RwRegisterOnINA219 const I2CINA219RwRegisterOnINA219::config{0};
I2CINA219RwRegisterOnINA219 const I2CINA219RwRegisterOnINA219::calibration{1};

I2CTCA9554RoRegisterOnTCA9554 const I2CTCA9554RoRegisterOnTCA9554::inputs{0};

I2CTCA9554RwRegisterOnTCA9554 const I2CTCA9554RwRegisterOnTCA9554::outputs{0};
I2CTCA9554RwRegisterOnTCA9554 const I2CTCA9554RwRegisterOnTCA9554::polarity{1};
I2CTCA9554RwRegisterOnTCA9554 const I2CTCA9554RwRegisterOnTCA9554::config{2};

} // namespace halco::hicann_dls::vx
