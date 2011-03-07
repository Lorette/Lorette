/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Mon 7. Mar 22:48:57 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *close;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QCheckBox *steps;
    QLabel *label;
    QSpinBox *_max;
    QDoubleSpinBox *prec;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(400, 207);
        gridLayout = new QGridLayout(Settings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        close = new QPushButton(Settings);
        close->setObjectName(QString::fromUtf8("close"));

        gridLayout->addWidget(close, 2, 1, 1, 1);

        frame = new QFrame(Settings);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        steps = new QCheckBox(frame);
        steps->setObjectName(QString::fromUtf8("steps"));
        steps->setChecked(true);

        gridLayout_2->addWidget(steps, 0, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        _max = new QSpinBox(frame);
        _max->setObjectName(QString::fromUtf8("_max"));
        _max->setMinimum(1);
        _max->setMaximum(10000);
        _max->setValue(100);

        gridLayout_2->addWidget(_max, 1, 2, 1, 1);

        prec = new QDoubleSpinBox(frame);
        prec->setObjectName(QString::fromUtf8("prec"));
        prec->setDecimals(6);
        prec->setMinimum(1e-06);
        prec->setMaximum(1);
        prec->setSingleStep(0.0001);
        prec->setValue(1e-06);

        gridLayout_2->addWidget(prec, 2, 1, 1, 2);


        gridLayout->addWidget(frame, 0, 0, 1, 2);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Options", 0, QApplication::UnicodeUTF8));
        close->setText(QApplication::translate("Settings", "Fermer", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Settings", "Pr\303\251cision (Jacobi et Gauss-Seidel)", 0, QApplication::UnicodeUTF8));
        steps->setText(QApplication::translate("Settings", "Afficher toutes les etapes", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Settings", "Maximum D'it\303\251ration (Jacobi et Gauss-Seidel)", 0, QApplication::UnicodeUTF8));
        _max->setSuffix(QApplication::translate("Settings", " it\303\251rations", 0, QApplication::UnicodeUTF8));
        _max->setPrefix(QString());
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
