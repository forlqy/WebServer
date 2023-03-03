#ifndef __SYLAR_LOG_H__
#define __SYLAR_LOG_H__

#include <string>
#include <stdint.h>
#include <memory>
#include <list>
#include <sstring>
#include <fstream>
#include <vector>

namespace sylar{
//日志事件    
class LogEvent{
public:
    typedef std::shared_ptr<LogEvent> ptr;
    LogEvent();
private:
    const char* m_file = nullptr; //文件名(成员变量前加m表示成员变量，用于和方法参数名称相同时冲突)
    int32_t m_line = 0; //行号
    uint32_t m_elapse = 0; //程序启动开始到现在的毫秒数 (内存对齐)
    uint32_t m_threadId = 0; //线程ID
    uint32_t m_fiberId = 0; //协程ID
    uint64_t m_time = 0; //时间戳
    std::string m_content;
};

//日志级别
class LogLevel{
public:
    enum Level{
        DEBUG = 1,
        INFO = 2,
        WARN = 3,
        ERROR = 4,
        FATAL = 5
    };
};

//日志格式器
class LogFormatter{
public:
    typedef std::shared_ptr<LogFormatter> ptr;
    LogFormatter(const std::string& pattern);
    std::string format(LogEvent::ptr event);
private:
    class FormatItem{
    public:
        using ptr = std::shared_ptr<FormatItem>;
        virtual void format(std::ostream os, LogEvent::ptr event) = 0;
        virtual ~FormatItem(){}
    };
    void init();
private:
    std::string m_pattern;
    std::vector<FormatItem::ptr> m_items;
};

//日志输出地
class LogAppender{
public:
    typedef std::shared_ptr<LogAppender> ptr;
    virtual ~LogAppender(){}

    virtual void log(LogLevel::Level level, LogEvent::ptr event) = 0;

    void setFormatter(LogFormatter::ptr val){m_formatter = val;}
    LogFormatter::ptr getFormatter() const{return m_formatter;}
protected: //虚基类，要设置为protected以便于派生类修改m_level
    LogLevel::Level m_level;
    LogFormatter::ptr m_formatter;
};

//日志器
class Logger{
public:
    typedef std::shared_ptr<Logger> ptr;

    Logger(const std::string& name = "root");
    void log(LogLevel::Level level, LogEvent::ptr event); 

    void debug(LogEvent::ptr event);
    void info(LogEvent::ptr event);
    void warn(LogEvent::ptr event);
    void error(LogEvent::ptr event);
    void fatal(LogEvent::ptr event);

    void addAppender(LogAppender::ptr appender);
    void delAppender(LogAppender::ptr appender);
    LogLevel::Level getLevel() const{return m_level;}
    void setLevel(LogLevel::Level val){m_level = val;}
private:
    std::string m_name; //日志名称
    LogLevel::Level m_level; //日志级别
    std::list<LogAppender::ptr> m_appenders; //Appender集合
};

//输出到控制台的Appender
class StdoutLogAppender : public LogAppender{
public:
    using ptr = std::shared_ptr<StdoutLogAppender>; //仅在类内部生效的类型别名 此处用using 代替 typedef
    void log(LogLevel::Level level, LogEvent::ptr event) override;
};

//输出到文件的Appender
class FileLogAppender : public LogAppender{  
public:
    using ptr = std::shared_ptr<FileLogAppender>; 
    FileLogAppender(const std::string& filename);
    void log(LogLevel::Level level, LogEvent::ptr event) override;
    bool reopen(); //重新打开文件，打开成功返回true，否则返回false
private:
    std::string m_filename;
    std::ofstream m_filestream;
};

}


#endif