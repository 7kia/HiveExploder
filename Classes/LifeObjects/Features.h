#pragma once

#include "CMovement.h"

class CDynamicFeature
{
public:
	void SetValue(int setValue);
	void AddToValue(int summand);

	int GetValue() const;
private:
	int value;
};