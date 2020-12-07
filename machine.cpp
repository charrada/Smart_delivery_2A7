#include "machine.h"
#include <QDebug>

machine::machine()//par defaut
{
    this->code_mach=0;
    this->type_mach="";
    this->date_mach=date_mach.currentDate();

}
machine::machine(int code_mach,QString type_mach,QDate date_mach){
    this->code_mach=code_mach;
    this->type_mach=type_mach;
    this->date_mach=date_mach;
}
machine::~machine()
{

}

void machine::setdate_mach(QDate date_mach){
    this->date_mach=date_mach;
}

int machine::getcode_mach(){
    return code_mach;
}
QString machine::gettype_mach(){
    return type_mach;
}


QDate machine::getdate_mach(){
    return date_mach;
}





bool machine::ajouter(){
    QSqlQuery query;
    QString res= QString::number(code_mach);


   query.prepare("insert into machine (code_mach,type_mach,date_mach) values (:code_mach,:type_mach,:date_mach)");

      query.bindValue(":code_mach",res);
       query.bindValue(":type_mach",type_mach);
       query.bindValue(":date_mach",date_mach);
    return query.exec();

}
QSqlQueryModel * machine::afficher(){

    QSqlQueryModel * model=new QSqlQueryModel();



    model->setQuery("select * from machine");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));



    return model;

}
bool machine::supprimer(int code_mach){
    QSqlQuery query;
   QString res= QString::number(code_mach);
    query.prepare("DELETE FROM machine WHERE code_mach=:code_mach");
     query.bindValue(":code_mach",res);

     return query.exec();
}

bool machine::editer(){
    QSqlQuery query;
    QString r= QString::number(code_mach);
    query.prepare("UPDATE machine SET code_mach=:code_mach,type_mach=:type_mach,date_mach=:date_mach WHERE code_mach=:code_mach");
   query.bindValue(":code_mach",r);
   query.bindValue(":type_mach",type_mach);
   query.bindValue(":date_mach",date_mach);


    return query.exec();
}
