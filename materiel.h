#ifndef MATERIEL_H
#define MATERIEL_H

#include <QDialog>
#include "machine.h"
#include "piece.h"
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>

namespace Ui {
class materiel;
}

class materiel : public QDialog
{
    Q_OBJECT

public:
    explicit materiel(QWidget *parent = nullptr);
    ~materiel();

    QSortFilterProxyModel *proxy_machine,*proxy_piece;

    void afficher();
private slots:


    void on_ajout_mach_clicked();

    void on_modifier_mach_clicked();

    void on_supp_mach_clicked();

    void on_ajout_p_clicked();

    void on_modifier_p_clicked();

    void on_supp_p_clicked();



    void on_comboBox_piece_currentIndexChanged(int index);

    void on_lineEdit_machine_textChanged(const QString &arg1);

    void on_lineEdit_piece_textChanged(const QString &arg1);

    void on_comboBox_machine_currentIndexChanged(int index);

private:
    Ui::materiel *ui;

   machine  tmp;
   piece   emp;
   int selected_machine=0;
       int selected_piece=0;
};

#endif // MATERIEL_H
