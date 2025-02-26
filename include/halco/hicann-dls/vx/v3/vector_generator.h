#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/vector_generator.h"

namespace halco::hicann_dls::vx { namespace v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using VectorGeneratorLUTEntryOnVectorGeneratorLUT GENPYBIND(visible) =
    halco::hicann_dls::vx::VectorGeneratorLUTEntryOnVectorGeneratorLUT;
using VectorGeneratorTriggerOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::VectorGeneratorTriggerOnFPGA;
using VectorGeneratorFIFOWordOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::VectorGeneratorFIFOWordOnFPGA;
using VectorGeneratorLUTEntryOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::VectorGeneratorLUTEntryOnFPGA;
using VectorGeneratorLUTOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::VectorGeneratorLUTOnFPGA;
using VectorGeneratorNotificationAddressOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::VectorGeneratorNotificationAddressOnFPGA;
using VectorGeneratorControlOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::VectorGeneratorControlOnFPGA;
using VectorGeneratorOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::VectorGeneratorOnFPGA;
using SourceOnVectorGenerator GENPYBIND(visible) = halco::hicann_dls::vx::SourceOnVectorGenerator;

} // namespace v3
} // namespace halco::hicann_dls::vx
