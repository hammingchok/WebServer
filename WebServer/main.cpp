#include "config.h"

int main(int argc, char *argv[])
{
    string user = "root";
    string passwd = "123456";
    string databasename = "web";

    //命令行解析
    Config config;
    config.parse_arg(argc, argv);

    WebServer server;

    //初始化
    server.init(config.PORT, user, passwd, databasename, config.LOGWrite, config.SQLVerify,
                config.OPT_LINGER, config.TRIGMode,  config.sql_num,  config.thread_num, 
                config.close_log, config.actor_model);
    
    //日志初始化
    server.log_write();

    //数据库连接池
    server.sql_pool();

    //线程池
    server.thread_pool();

    //开启监听
    server.eventListen();

    //开启事件循环
    server.eventLoop();

    return 0;
}
