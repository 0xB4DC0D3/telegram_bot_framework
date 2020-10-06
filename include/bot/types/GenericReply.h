#pragma once

#include <memory> 

struct GenericReply {
	using Ptr = std::shared_ptr<GenericReply>;
	GenericReply() = default;
	virtual ~GenericReply() = default;
};