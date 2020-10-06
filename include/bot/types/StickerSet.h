#pragma once

#include <memory>
#include <vector>
#include <string>

#include "Sticker.h"
#include "PhotoSize.h"

struct StickerSet {
	using Ptr = std::shared_ptr<StickerSet>;
	
	std::string name;
	std::string title;
	bool is_animated;
	bool contains_masks;
	std::vector<Sticker::Ptr> stickers;
	[[maybe_unused]] PhotoSize::Ptr thumb;
};