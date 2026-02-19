#ifndef PROJECT_UTILS_TRACKING_LOGGER_HPP
#define PROJECT_UTILS_TRACKING_LOGGER_HPP

#include "logger.hpp"

#include <atomic>
#include <type_traits>
#include <utility>


/// @brief Inherit `MyClass : private TrackingLogger<MyClass>` to track allocations and special member functions
/// @tparam Derived The class you want to track
template <typename Derived>
class TrackingLogger : Logger<Derived>
{
protected:
    TrackingLogger()
    {
        static_assert(
            !std::is_convertible_v<Derived*, TrackingLogger<Derived>*>,
            "Inherit privately: class MyClass : private TrackingLogger<MyClass>"
        );
        instances_.fetch_add(1, std::memory_order_relaxed);
        this->TRACE("{} constructor [{}]", type_name<Derived>(), instances_.load(std::memory_order_relaxed));
    }

    ~TrackingLogger() noexcept
    {
        instances_.fetch_sub(1, std::memory_order_relaxed);
        this->TRACE("{} destructor [{}]", type_name<Derived>(), instances_.load(std::memory_order_relaxed));
    }

    TrackingLogger(TrackingLogger const& other)
        : Logger<Derived>(other)
    {
        instances_.fetch_add(1, std::memory_order_relaxed);
        this->TRACE("{} copy constructor [{}]", type_name<Derived>(), instances_.load(std::memory_order_relaxed));
    }

    TrackingLogger(TrackingLogger&& other) noexcept
        : Logger<Derived>(std::move(other))
    {
        instances_.fetch_add(1, std::memory_order_relaxed);
        this->TRACE("{} move constructor [{}]", type_name<Derived>(), instances_.load(std::memory_order_relaxed));
    }

    TrackingLogger& operator =(TrackingLogger const& other)
    {
        if (this != &other) {
            Logger<Derived>::operator =(other);
            this->TRACE("{} copy assignment [{}]", type_name<Derived>(), instances_.load(std::memory_order_relaxed));
        }

        return *this;
    }

    TrackingLogger& operator =(TrackingLogger&& other) noexcept
    {
        if (this != &other) {
            Logger<Derived>::operator =(std::move(other));
            this->TRACE("{} move assignment [{}]", type_name<Derived>(), instances_.load(std::memory_order_relaxed));
        }

        return *this;
    }

private:
    inline static std::atomic<int64_t> instances_ {0};
};

/// @brief Wraps a POD-like type T with full lifecycle tracking.
///        T itself is left completely untouched.
template <typename T>
requires std::is_trivially_copyable_v<T>
class Tracked : private TrackingLogger<T>
{
public:

    Tracked()
        : TrackingLogger<T>(),
          value{}
    {}

    template <typename ... Args>
    requires std::is_constructible_v<T, Args...>
    explicit Tracked(Args&&... args)
        : TrackingLogger<T>(),
          value(std::forward<Args>(args)...)
    {}


    Tracked(Tracked const&)             = default;
    Tracked(Tracked&&)                  = default;
    Tracked& operator =(Tracked const&) = default;
    Tracked& operator =(Tracked&&)      = default;
    ~Tracked()                          = default;


    T value;

    T*       operator ->()       { return &value; }
    T const* operator ->() const { return &value; }
    T&       operator *()        { return value; }
    T const& operator *() const  { return value; }

    operator T&() { return value; }
    operator T const&() const { return value; }
};


#endif // PROJECT_UTILS_TRACKING_LOGGER_HPP
