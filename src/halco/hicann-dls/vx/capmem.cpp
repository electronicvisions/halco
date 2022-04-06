#include "halco/hicann-dls/vx/capmem.h"

namespace halco::hicann_dls::vx {

CapMemBlockOnHemisphere const CapMemBlockOnHemisphere::left{0};
CapMemBlockOnHemisphere const CapMemBlockOnHemisphere::right{1};

CapMemBlockOnHemisphere CapMemBlockOnDLS::toCapMemBlockOnHemisphere() const
{
	return CapMemBlockOnHemisphere(toEnum() % CapMemBlockOnHemisphere::size);
}

CapMemBlockOnHemisphere CapMemBlockConfigOnDLS::toCapMemBlockOnHemisphere() const
{
	return CapMemBlockOnHemisphere(toEnum() % CapMemBlockOnHemisphere::size);
}

HemisphereOnDLS CapMemBlockOnDLS::toHemisphereOnDLS() const
{
	return HemisphereOnDLS(toEnum() / CapMemBlockOnHemisphere::size);
}

HemisphereOnDLS CapMemBlockConfigOnDLS::toHemisphereOnDLS() const
{
	return HemisphereOnDLS(toEnum() / CapMemBlockOnHemisphere::size);
}

} // namespace halco::hicann_dls::vx:v2
