#pragma once

#include "Movement.h"

class CDynamicFeature
{
public:
	void				SetValue(int setValue);
	void				AddToValue(int summand);

	int					GetValue() const;
private:
	int					m_value;
};
