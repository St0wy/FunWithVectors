#pragma once

#include <sstream>
#include <string>

class FpsCounter
{
public:
    [[nodiscard]] float GetFps() const;
    [[nodiscard]] std::string GetFpsString() const;
    void Update(float deltaTime);
private:
    int m_FrameCount{};
    float m_Fps{};
    float m_Accumulator = 0;
};

inline void FpsCounter::Update(const float deltaTime)
{
    // Time in seconds when the fps counter should update
    constexpr float timeToUpdate = 0.7f;

    m_FrameCount++;
    m_Accumulator += deltaTime;

    if (m_Accumulator >= timeToUpdate)
    {
        m_Accumulator -= timeToUpdate;
        m_Fps = static_cast<float>(m_FrameCount) / timeToUpdate;
        m_FrameCount = 0;
    }
}

inline float FpsCounter::GetFps() const
{
    return m_Fps;
}

inline std::string FpsCounter::GetFpsString() const
{
    std::ostringstream oss{};
    oss.precision(0);
    oss << std::fixed;
    oss << GetFps();
    return oss.str();
}
