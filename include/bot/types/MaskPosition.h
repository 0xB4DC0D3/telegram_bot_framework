#pragma once

#include <memory>
#include <string>

struct MaskPosition {
	using Ptr = std::shared_ptr<MaskPosition>;
	
	std::string point;
	float x_shift;
	float y_shift;
	float scale;
};