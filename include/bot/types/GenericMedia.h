#pragma once

#include <memory>

struct GenericMedia {
	using Ptr = std::shared_ptr<GenericMedia>;
	virtual ~GenericMedia() {}
};