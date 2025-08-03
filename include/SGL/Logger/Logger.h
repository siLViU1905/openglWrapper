
#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <vector>
#include <ostream>

namespace sgl
{
   class Logger
   {
      std::vector<std::string> m_Buffer;

      size_t m_CurrentIndex;
   public:
      constexpr Logger():m_CurrentIndex(0) {}

      constexpr const auto& getBuffer() const {return m_Buffer;}

      constexpr void log(const std::string& message)
      {
         m_Buffer.push_back(message);
      }

      constexpr void log(std::string&& message)
      {
         m_Buffer.push_back(std::move(message));
      }

      constexpr void flush()
      {
         m_Buffer.clear();
         m_CurrentIndex = 0;
      }
      //clears the buffer

      friend std::ostream& operator<<(std::ostream& outputStream, Logger& logger);
      //support for std::cout
      // outputs only the messages after the last log called
   };
}



#endif //LOGGER_H
