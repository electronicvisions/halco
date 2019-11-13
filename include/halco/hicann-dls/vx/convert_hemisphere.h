#ifndef HEMISPHERE_CLASS
#error "HEMISPHERE_CLASS needs to be defined."
#endif

#define HEMISPHERE_COORDINATE(Name)                                                                \
	Name HEMISPHERE_CLASS::to##Name() const { return Name(toEnum()); }
#include "hemisphere.def"
#undef HEMISPHERE_CLASS
