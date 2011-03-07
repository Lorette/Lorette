/********************************************************************************
** Form generated from reading UI file 'resultat.ui'
**
** Created: Mon 7. Mar 22:51:06 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTAT_H
#define UI_RESULTAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Resultat
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *Resultat)
    {
        if (Resultat->objectName().isEmpty())
            Resultat->setObjectName(QString::fromUtf8("Resultat"));
        Resultat->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Lorette.png"), QSize(), QIcon::Normal, QIcon::Off);
        Resultat->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Resultat);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(Resultat);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setDocumentMode(true);
        tabWidget->setMovable(true);

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(Resultat);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::NoButton);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Resultat);

        QMetaObject::connectSlotsByName(Resultat);
    } // setupUi

    void retranslateUi(QWidget *Resultat)
    {
        Resultat->setWindowTitle(QApplication::translate("Resultat", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Resultat: public Ui_Resultat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTAT_H
