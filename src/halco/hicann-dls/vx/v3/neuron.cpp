#include "halco/hicann-dls/vx/v3/neuron.h"

#include "halco/common/cerealization_geometry.h"
#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/cereal.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>

namespace halco::hicann_dls::vx::v3 {

#include "halco/hicann-dls/vx/neuron_ns_includes_impl.h"

#define EXPLICIT_INSTANTIATE_CEREAL_SERIALIZE(CLASS_NAME)                                          \
	template void CLASS_NAME ::CEREAL_SERIALIZE_FUNCTION_NAME(                                     \
	    cereal::BinaryOutputArchive&, std::uint32_t const);                                        \
	template void CLASS_NAME ::CEREAL_SERIALIZE_FUNCTION_NAME(                                     \
	    cereal::BinaryInputArchive&, std::uint32_t const);                                         \
	template void CLASS_NAME ::CEREAL_SERIALIZE_FUNCTION_NAME(                                     \
	    cereal::JSONOutputArchive&, std::uint32_t const);                                          \
	template void CLASS_NAME ::CEREAL_SERIALIZE_FUNCTION_NAME(                                     \
	    cereal::JSONInputArchive&, std::uint32_t const);                                           \
	template void CLASS_NAME ::CEREAL_SERIALIZE_FUNCTION_NAME(                                     \
	    cereal::PortableBinaryOutputArchive&, std::uint32_t const);                                \
	template void CLASS_NAME ::CEREAL_SERIALIZE_FUNCTION_NAME(                                     \
	    cereal::PortableBinaryInputArchive&, std::uint32_t const);                                 \
	template void CLASS_NAME ::CEREAL_SERIALIZE_FUNCTION_NAME(                                     \
	    cereal::XMLOutputArchive&, std::uint32_t const);                                           \
	template void CLASS_NAME ::CEREAL_SERIALIZE_FUNCTION_NAME(                                     \
	    cereal::XMLInputArchive&, std::uint32_t const);

EXPLICIT_INSTANTIATE_CEREAL_SERIALIZE(LogicalNeuronCompartments)
EXPLICIT_INSTANTIATE_CEREAL_SERIALIZE(LogicalNeuronOnDLS)

} // namespace halco::hicann_dls::vx::v3
