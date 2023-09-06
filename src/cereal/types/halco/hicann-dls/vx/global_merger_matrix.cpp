#include "cereal/types/halco/hicann-dls/vx/global_merger_matrix.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/global_merger_matrix.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::GlobalMergerMatrixOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::GlobalMergerMatrixOutputConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronLabelToGL1EventLUTEntryOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::GlobalMergerMatrixNodeOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_global_merger_matrix)
