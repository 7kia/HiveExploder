#include "FeaturesLifeObject.h"

void CDynamicFeature::SetValue(int setValue)
{
	value = setValue;
}

void CDynamicFeature::AddToValue(int summand)
{
	value += summand;
}

int CDynamicFeature::GetValue()
{
	return value;
}
