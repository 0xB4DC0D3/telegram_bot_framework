#pragma once

#include <memory>

#include "GenericReply.h"

struct ForceReply : GenericReply {
	using Ptr = std::shared_ptr<ForceReply>;
	
	bool force_reply;
	[[maybe_unused]] bool selective;
};