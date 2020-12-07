#ifndef PIECE_H
#define PIECE_H



#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>
class piece
{
public:
    piece();
    ~piece();
    piece(int,int,QString,QDate);

    int getcode_m();
     int getcode_p();

    QString getnom();
    QDate getdate_piece();
    void setdate_piece(QDate );



    bool ajouter();

    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool chercher(QString);
    bool editer();



 private:
    int code_m,code_p;
    QString nom;
    QDate date_piece;
};


#endif // PIECE_H
