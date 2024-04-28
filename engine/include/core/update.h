#pragma once

#include <functional>
#include <vector>

namespace engine {

    class Update {
    public:
        static const unsigned long long kDefaultFixedUpdateMs = 250;

        using UpdateFunc = std::function<void(float)>;
        using FixedUpdateFunc = std::function<void(void)>;

        Update();
        ~Update();

        void RegisterUpdate(const UpdateFunc&);
        void RegisterUpdate(UpdateFunc&&);

        void RegisterFixedUpdate(const FixedUpdateFunc&);
        void RegisterFixedUpdate(FixedUpdateFunc&&);

        // Run once per frame.
        // @param dt    time in seconds
        void RunUpdate(float dt) const;

        // Run at fixed interval
        void RunFixedUpdate() const;

        // @return Interval in milliseconds RunFixedUpdate() is called
        unsigned long long FixedUpdateMs() const { return m_FixedUpdateMs; }

    private:
        std::vector<UpdateFunc> m_UpdateFuncs;
        std::vector<FixedUpdateFunc> m_FixedUpdateFuncs;

        unsigned long long m_FixedUpdateMs;
    };

}; // namespace engine