#pragma once

#include "logging.h"

namespace engine {

	using GameObjectID = std::uint32_t;

	// TODO: Create custom allocator for GameObjects
	struct GameObject_ {
		GameObjectID id;

		GameObject_(GameObjectID id) : id(id), ref_count_(0)
		{}

		// Arbitrary value for max references to a game object
		void reference() { CHECK(++ref_count_ < 65536) << "Object reference count to high"; }
		void release() { CHECK(--ref_count_ > 0) << "Game Object invalid reference count"; }

		void free() { CHECK(--ref_count_ == 0) << "Game Object already free'd"; }

	private:
		int32_t ref_count_;
	};
	using GameObject = struct GameObject_;


	class GameObjectManager {
	public:
		GameObjectManager();
		~GameObjectManager();

		const GameObject* GetObject(GameObjectID);

		GameObjectID CreateGameObject(GameObject**);
		void DeleteGameObject(GameObjectID);
	};

}; // namespace engine