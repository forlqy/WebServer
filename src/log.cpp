#include "../log/log.h"

namespace sylar{

Logger::Logger(const std::string& name) : m_name(name){

}
void Logger::addAppender(LogAppender::ptr appender){
    m_appenders.push_back(appender);
}

void Logger::delAppender(LogAppender::ptr appender){
    for(auto it = m_appenders.begin(); it!= m_appenders.end(); ++it){
        if(*it == appender){
            m_appenders.erase(it);
            break;
        }
    }

}

void Logger::log(LogLevel level, LogEvent::ptr event){
    if(level >= m_level){
        for(auto& i : m_appenders){
            i->log(level, event);
        }
    }
}

void Logger::debug(LogEvent::ptr event){
    log(LogLevel::DEBUG, event);

}

void Logger::info(LogEvent::ptr event){
    log(LogLevel::INFO, event);

}

void Logger::warn(LogEvent::ptr event){
    log(LogLevel::WARN, event);

}

void Logger::error(LogEvent::ptr event){
    log(LogLevel::ERROR, event);

}

void Logger::fatal(LogEvent::ptr event){
    log(LogLevel::FATAL, event);

}

FileLogAppender::FileLogAppender(const std::string& filename) : m_filename(filename){
}

void FileLogAppender::log(LogLevel::Level level, LogEvent::ptr event){
    if(level >= m_level){
        m_filestream << m_formatter->format(event); //这里m_formatter是智能指针，但本质也是类，所以用.
    }
}

bool FileLogAppender::reopen(){
    if(m_filestream){
        m_filestream.close();
    }
    m_filestream.open(m_filename);
    return !!m_filestream; //!!将非0值转为1，0还是0
}

void StdoutLogAppender::log(LogLevel::Level level, LogEvent::ptr event){
    if(level >= m_level){
        std::cout << m_formatter->format(event);
    }
}

LogFormatter::LogFormatter(const std::string& pattern){
}

void LogFormatter::format(std::ostream os, LogEvent::ptr event){
}

void LogFormatter::init(){  
}

}
//观察者模式 logevent出现 -> logger触发 -> appender显示