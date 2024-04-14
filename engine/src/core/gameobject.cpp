#include "core/gameobject.h"
#include "logging.h"

namespace engine {

GameObjectManager::GameObjectManager() : m_maxID(0)
{
    m_GameObjects = std::unordered_map<GameObjectID, GameObject*>();
}

GameObjectManager::~GameObjectManager()
{}

const GameObject* GameObjectManager::GetObject(GameObjectID id)
{
    auto it = m_GameObjects.find(id);
    return it != m_GameObjects.end() ? it->second : nullptr;
}

GameObjectID GameObjectManager::CreateGameObject(GameObject **goPtr)
{
    auto id = m_maxID++;
    m_GameObjects[id] = new GameObject(id);

    if (goPtr != nullptr) {
        *goPtr = m_GameObjects[id];
    }

    return id;
}

void GameObjectManager::DeleteGameObject(GameObjectID id)
{
    delete m_GameObjects[id];
}

}; // namespace engine