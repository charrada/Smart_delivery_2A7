#ifndef MACHINE_H
#define MACHINE_H


#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>

class machine
{


public:
    machine();
    ~machine();
    machine(int,QString,QDate);

    int getcode_mach();
    QString gettype_mach();
    QDate getdate_mach();
    void setdate_mach(QDate );



    bool ajouter();

    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool chercher(QString);
    bool editer();



 private:
    int code_mach;
    QString type_mach;
    QDate date_mach;
};


#endif // MACHINE_H
