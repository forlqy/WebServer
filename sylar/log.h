#ifndef __SYLAR_LOG_H__
#define __SYLAR_LOG_H__

#include <iostream>
#include <string>
#include <stdint.h>
#include <memory>
#include <list>
#include <sstream>
#include <fstream>
#include <vector>

namespace sylar{
class Logger;
//日志事件    
class LogEvent{
public:
    typedef std::shared_ptr<LogEvent> ptr;
    LogEvent(const char* file, int32_t m_line, uint32_t elapse, uint32_t thread_id, uint32_t fiber_id, uint64_t time);

    const char* getFile() const{return m_file;}
    int32_t getLine() const{return m_line;}
    uint32_t getElapse() const{return m_elapse;}
    uint32_t getThreadId() const{return m_threadId;}
    uint32_t getFiberId() const{return m_fiberId;}
    uint64_t getTime() const{return m_time;}
    std::string getContent() const{return m_ss.str();}

    std::stringstream& getSS() {return m_ss;}
private:
    const char* m_file = nullptr; //文件名(成员变量前加m表示成员变量，用于和方法参数名称相同时冲突)
    int32_t m_line = 0; //行号
    uint32_t m_elapse = 0; //程序启动开始到现在的毫秒数 (内存对齐)
    uint32_t m_threadId = 0; //线程ID
    uint32_t m_fiberId = 0; //协程ID
    uint64_t m_time = 0; //时间戳
    std::stringstream m_ss;
    std::string m_content;
};

//日志级别
class LogLevel{
public:
    enum Level{
        UNKNOW = 0,
        DEBUG = 1,
        INFO = 2,
        WARN = 3,
        ERROR = 4,
        FATAL = 5
    };

    static const char* ToString(LogLevel::Level level);
};

//日志格式器
class LogFormatter{
public:
    typedef std::shared_ptr<LogFormatter> ptr;
    LogFormatter(const std::string& pattern);
    std::string format(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);
public: //实例
    class FormatItem{
    public:
        using ptr = std::shared_ptr<FormatItem>;
        FormatItem(const std::string& fmt = "") {}
        virtual void format(std::ostream& os, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;
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

    virtual void log(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;

    void setFormatter(LogFormatter::ptr val){m_formatter = val;}
    LogFormatter::ptr getFormatter() const{return m_formatter;}
protected: //虚基类，要设置为protected以便于派生类修改m_level
    LogLevel::Level m_level;
    LogFormatter::ptr m_formatter;
};

//日志器
class Logger : public std::enable_shared_from_this<Logger>{ //enable
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

    const std::string& getName() const {return m_name;}
private:
    std::string m_name; //日志名称
    LogLevel::Level m_level; //日志级别
    std::list<LogAppender::ptr> m_appenders; //Appender集合
    LogFormatter::ptr m_formatter; //输出格式
};

//输出到控制台的Appender
class StdoutLogAppender : public LogAppender{
public:
    using ptr = std::shared_ptr<StdoutLogAppender>; //仅在类内部生效的类型别名 此处用using 代替 typedef
    void log(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override; //bug
};

//输出到文件的Appender
class FileLogAppender : public LogAppender{  
public:
    using ptr = std::shared_ptr<FileLogAppender>; 
    FileLogAppender(const std::string& filename);
    void log(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override;
    bool reopen(); //重新打开文件，打开成功返回true，否则返回false
private:
    std::string m_filename;
    std::ofstream m_filestream;
};

}


#endif