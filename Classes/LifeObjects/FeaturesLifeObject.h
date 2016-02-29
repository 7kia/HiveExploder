#ifndef FEATURESLIFEOBJECT_H
#define FEATURESLIFEOBJECT_H

#pragma once

#include "CMovement.h"

class CDynamicFeature
{
public:
	void SetValue(int setValue);
	void AddToValue(int summand);

	int GetValue();
private:
	int value;
};
#endif
