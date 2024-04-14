#include "core/update.h"

namespace engine {

Update::Update() : m_FixedUpdateMs(kDefaultFixedUpdateMs)
{
    m_UpdateFuncs = std::vector<UpdateFunc>();
    m_FixedUpdateFuncs = std::vector<FixedUpdateFunc>();
}

Update::~Update()
{}

void Update::RegisterUpdate(const UpdateFunc& f)
{
    m_UpdateFuncs.push_back(f);
}

void Update::RegisterUpdate(UpdateFunc&& f)
{
    m_UpdateFuncs.push_back(std::move(f));
}

void Update::RegisterFixedUpdate(const FixedUpdateFunc& f)
{
    m_FixedUpdateFuncs.push_back(f);
}

void Update::RegisterFixedUpdate(FixedUpdateFunc&& f)
{
    m_FixedUpdateFuncs.push_back(std::move(f));
}

void Update::RunUpdate(float dt) const
{
    for (const auto& f : m_UpdateFuncs) {
        f(dt);
    }
}

void Update::RunFixedUpdate() const
{
    for (const auto& f : m_FixedUpdateFuncs) {
        f();
    }
}

}; // namespace engine