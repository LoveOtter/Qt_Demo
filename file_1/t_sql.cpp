#include "t_sql.h"
#include<QDebug>

T_sql::T_sql() {

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("music");
    db.transaction();
    if(!db.open()){
        qDebug()<<"链接失败";
        return;
    }else{
        qDebug()<<"链接成功";
    }

    QSqlQuery query;
    query.exec("select* from heardmusic");


    while (query.next()) {
        qDebug()<<query.value("id").toString()
                 <<query.value("name").toString()
                 <<query.value("author").toString();
    }

}
