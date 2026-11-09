#pragma once

#include <vector>

namespace uevent {
    template<class... ArgT> class Event {
        using funcptr = void(*)(ArgT...);

        std::vector<funcptr> _targets;
    public:
        bool contains(funcptr func) {
            for (auto t : _targets)
                if (t == func) return true;
            return false;
        }

        void invoke(ArgT... args) {
            for (auto t : _targets)
                t(args...);
        }

        void add(funcptr func) {
            if (!contains(func))
                _targets.push_back(func);
        }

        void remove(funcptr func) {
            std::erase(_targets, func);
        }

        void operator+= (const funcptr func) {
            add(func);
        }

        void operator-= (const funcptr func) {
            remove(func);
        }
    };
}
