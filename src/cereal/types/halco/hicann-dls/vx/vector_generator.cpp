#include "cereal/types/halco/hicann-dls/vx/vector_generator.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/vector_generator.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorControlOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorLUTOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorLUTEntryOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorNotificationAddressOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorTriggerOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorFIFOWordOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorControlOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorLUTOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorLUTEntryOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorNotificationAddressOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorTriggerOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorFIFOWordOnFPGA)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_vector_generator)
