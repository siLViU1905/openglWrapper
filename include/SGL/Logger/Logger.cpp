#include "Logger.h"

namespace sgl
{
    std::ostream &operator<<(std::ostream &outputStream, Logger &logger)
    {
        while (logger.m_CurrentIndex < logger.m_Buffer.size())
            outputStream << "[Logger] " << logger.m_Buffer[logger.m_CurrentIndex++] << '\n';

        return outputStream;
    }
}
