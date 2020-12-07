#include <QDebug>
#include "piece.h"
piece::piece(){
    this->code_m=0;
     this->code_p=0;

    this->nom="";
    this->date_piece=date_piece.currentDate();
}


piece::piece(int code_m,int code_p,QString nom,QDate date_piece){
    this->code_m=code_m;
    this->code_p=code_p;
    this->nom=nom;
    this->date_piece=date_piece;
}
piece::~piece()
{

}

void piece::setdate_piece(QDate date_piece){
    this->date_piece=date_piece;
}

int piece::getcode_m(){
    return code_m;
}
    int piece::getcode_p(){
        return code_p;
}
QString piece::getnom(){
    return nom;
}


QDate piece::getdate_piece(){
    return date_piece;
}





bool piece::ajouter(){
    QSqlQuery query;
    QString res= QString::number(code_m);
     QString r= QString::number(code_p);


   query.prepare("insert into piece (code_m,code_p,nom,date_piece) values (:code_m,:code_p,:nom,:date_piece)");

      query.bindValue(":code_m",res);
       query.bindValue(":code_p",r);
       query.bindValue(":nom",nom);
       query.bindValue(":date_piece",date_piece);
    return query.exec();

}
QSqlQueryModel * piece::afficher(){

    QSqlQueryModel * model=new QSqlQueryModel();



    model->setQuery("select * from piece");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code machine"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("code piece"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom piece"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("date"));




    return model;

}
bool piece::supprimer(int code_m){
    QSqlQuery query;
   QString res= QString::number(code_m);
    query.prepare("DELETE FROM piece WHERE code_m=:code_m");
     query.bindValue(":code_m",res);

     return query.exec();
}

bool piece::editer(){
    QSqlQuery query;
    QString res= QString::number(code_m);
    QString r= QString::number(code_p);
    query.prepare("UPDATE piece SET code_m=:code_m,code_p=:code_p,nom=:nom,date_piece=:date_piece WHERE code_m=:code_m");
    query.bindValue(":code_m",res);
     query.bindValue(":code_p",r);
     query.bindValue(":nom",nom);
     query.bindValue(":date_piece",date_piece);

    return query.exec();
}
