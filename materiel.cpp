
#include "materiel.h"
#include "ui_materiel.h"
#include "machine.h"
#include "piece.h"
#include "materiel.h"
#include <QMessageBox>

materiel::materiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materiel)
{
    ui->setupUi(this);

    afficher();

}
void materiel::afficher()
{

//**************
    proxy_machine = new QSortFilterProxyModel();
    proxy_machine ->setSourceModel(tmp.afficher());
        proxy_machine ->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxy_machine ->setFilterKeyColumn(selected_machine);
      ui->tab_machine->setModel(proxy_machine );

            proxy_piece = new QSortFilterProxyModel();
            proxy_piece->setSourceModel(emp.afficher());
                proxy_piece->setFilterCaseSensitivity(Qt::CaseInsensitive);
                proxy_piece->setFilterKeyColumn(selected_piece);
            ui->tab_piece->setModel(proxy_piece);

}


materiel::~materiel()
{
    delete ui;
}




void materiel::on_ajout_mach_clicked()
{


    int code_mach =ui->code_mach->text().toInt();
        QString type_mach =ui->type_mach->text();
        QDate date_mach=ui->date_mach->date();

        machine m(code_mach,type_mach,date_mach);

        bool test=m.ajouter();

        if(test){
              afficher();

    QMessageBox::information(nullptr, QObject::tr("ajouter une machine"),
                        QObject::tr("machine ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



    }
        else{
            QMessageBox::critical(nullptr, QObject::tr("ajouter une machine"),
                        QObject::tr("machine non ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


     }


}

void materiel::on_modifier_mach_clicked()
{
    int code_mach =ui->code_mach->text().toInt();
        QString type_mach =ui->type_mach->text();
        QDate date_mach=ui->date_mach->date();

        machine m(code_mach,type_mach,date_mach);

        bool test=m.editer();

        if(test){
            afficher();

    QMessageBox::information(nullptr, QObject::tr("edité une machine"),
                        QObject::tr("machine edité.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



    }
        else{
            QMessageBox::critical(nullptr, QObject::tr("editer une machine"),
                        QObject::tr("machine non edité.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


     }



}

void materiel::on_supp_mach_clicked()
{
    int code_mach =ui->code_mach->text().toInt();




        bool test=tmp.supprimer(code_mach);

        if(test){
              afficher();

    QMessageBox::information(nullptr, QObject::tr("supprimer une machine"),
                        QObject::tr("machine supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



    }
        else{
            QMessageBox::critical(nullptr, QObject::tr("supprimer une machine"),
                        QObject::tr("machine non supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


     }

}

void materiel::on_ajout_p_clicked()
{
    int code_m =ui->code_m->text().toInt();
    int code_p =ui->code_p->text().toInt();
        QString nom =ui->nom->text();
        QDate date_piece=ui->date_piece->date();

        piece p(code_m,code_p,nom,date_piece);

        bool test=p.ajouter();

        if(test){
              afficher();

    QMessageBox::information(nullptr, QObject::tr("ajouter une piece"),
                        QObject::tr("piece ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



    }
        else{
            QMessageBox::critical(nullptr, QObject::tr("ajouter une piece"),
                        QObject::tr("piece non ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


     }



}

void materiel::on_modifier_p_clicked()
{  int code_m =ui->code_m->text().toInt();
    int code_p =ui->code_p->text().toInt();
        QString nom =ui->nom->text();
        QDate date_piece=ui->date_piece->date();

        piece p(code_m,code_p,nom,date_piece);

        bool test=p.editer();

        if(test){
              afficher();

    QMessageBox::information(nullptr, QObject::tr("editer une piece"),
                        QObject::tr("piece éditée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



    }
        else{
            QMessageBox::critical(nullptr, QObject::tr("editer une piece"),
                        QObject::tr("piece non editée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


     }





}

void materiel::on_supp_p_clicked()
{
    int code_m =ui->code_m->text().toInt();




        bool test=emp.supprimer(code_m);

        if(test){
              afficher();
            QMessageBox::information(nullptr, QObject::tr("editer une piece"),
                                QObject::tr("piece éditée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);



            }
                else{
                    QMessageBox::critical(nullptr, QObject::tr("editer une piece"),
                                QObject::tr("piece non editée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);


             }

        }


void materiel::on_comboBox_piece_currentIndexChanged(int index)
{
    selected_machine=ui->comboBox_piece->currentIndex();
            afficher();

}

void materiel::on_lineEdit_machine_textChanged(const QString &arg1)
{
     proxy_machine->setFilterFixedString(arg1);
}

void materiel::on_lineEdit_piece_textChanged(const QString &arg1)
{
     proxy_piece->setFilterFixedString(arg1);
}

void materiel::on_comboBox_machine_currentIndexChanged(int index)
{
    selected_machine=ui->comboBox_machine->currentIndex();
            afficher();
}
