/********************************************************************************
** Form generated from reading UI file 'lorette.ui'
**
** Created: Mon 7. Mar 22:48:57 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LORETTE_H
#define UI_LORETTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lorette
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QMainWindow *Lorette)
    {
        if (Lorette->objectName().isEmpty())
            Lorette->setObjectName(QString::fromUtf8("Lorette"));
        Lorette->resize(693, 344);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Lorette.png"), QSize(), QIcon::Normal, QIcon::Off);
        Lorette->setWindowIcon(icon);
        Lorette->setDocumentMode(true);
        centralWidget = new QWidget(Lorette);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 553, 318));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(centralWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::NoButton);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);

        Lorette->setCentralWidget(centralWidget);

        retranslateUi(Lorette);

        QMetaObject::connectSlotsByName(Lorette);
    } // setupUi

    void retranslateUi(QMainWindow *Lorette)
    {
        Lorette->setWindowTitle(QApplication::translate("Lorette", "Lorette", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Lorette", "M\303\251thode", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("Lorette", "Pivot de Gauss", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("Lorette", "Jacobi", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("Lorette", "Gauss-Seidel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Lorette: public Ui_Lorette {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LORETTE_H
