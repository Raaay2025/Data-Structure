/********************************************************************************
** Form generated from reading UI file 'huffmanwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUFFMANWINDOW_H
#define UI_HUFFMANWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HuffmanWindow
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTextEdit *writeFile_textEdit;
    QPushButton *writeFile_Button;
    QPushButton *buileTree_Button;
    QFrame *frame;
    QLabel *label_7;
    QLineEdit *getNewText_lineEdit;
    QPushButton *encodeButton;
    QLabel *label_8;
    QTextBrowser *HuffEncoding_textBrowser;
    QLabel *label_10;
    QTextBrowser *decode_textBrowser;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QTextBrowser *Text_textBrowser;
    QLabel *label_2;
    QTextBrowser *Freq_textBrowser;
    QLabel *label_3;
    QLabel *label_9;
    QTextBrowser *HuffTree_textBrowser;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QTextBrowser *printTree_textBrowser;
    QLabel *label_4;
    QTextBrowser *HuffCode_textBrowser;
    QLabel *label_11;
    QTextBrowser *CodedSequence_textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QTextBrowser *wpl_textBrowser;
    QPushButton *clearButton;
    QPushButton *returnButton;

    void setupUi(QWidget *HuffmanWindow)
    {
        if (HuffmanWindow->objectName().isEmpty())
            HuffmanWindow->setObjectName("HuffmanWindow");
        HuffmanWindow->resize(1077, 666);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HuffmanWindow->sizePolicy().hasHeightForWidth());
        HuffmanWindow->setSizePolicy(sizePolicy);
        horizontalLayoutWidget = new QWidget(HuffmanWindow);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 1061, 651));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        writeFile_textEdit = new QTextEdit(horizontalLayoutWidget);
        writeFile_textEdit->setObjectName("writeFile_textEdit");

        verticalLayout->addWidget(writeFile_textEdit);

        writeFile_Button = new QPushButton(horizontalLayoutWidget);
        writeFile_Button->setObjectName("writeFile_Button");

        verticalLayout->addWidget(writeFile_Button);

        buileTree_Button = new QPushButton(horizontalLayoutWidget);
        buileTree_Button->setObjectName("buileTree_Button");
        buileTree_Button->setContextMenuPolicy(Qt::DefaultContextMenu);

        verticalLayout->addWidget(buileTree_Button);

        frame = new QFrame(horizontalLayoutWidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::HLine);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);

        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName("label_7");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMaximumSize(QSize(16777215, 30));
        label_7->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout->addWidget(label_7);

        getNewText_lineEdit = new QLineEdit(horizontalLayoutWidget);
        getNewText_lineEdit->setObjectName("getNewText_lineEdit");
        getNewText_lineEdit->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(getNewText_lineEdit);

        encodeButton = new QPushButton(horizontalLayoutWidget);
        encodeButton->setObjectName("encodeButton");

        verticalLayout->addWidget(encodeButton);

        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(16777215, 30));
        label_8->setContextMenuPolicy(Qt::DefaultContextMenu);

        verticalLayout->addWidget(label_8);

        HuffEncoding_textBrowser = new QTextBrowser(horizontalLayoutWidget);
        HuffEncoding_textBrowser->setObjectName("HuffEncoding_textBrowser");
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Sans Typewriter")});
        HuffEncoding_textBrowser->setFont(font);

        verticalLayout->addWidget(HuffEncoding_textBrowser);

        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName("label_10");

        verticalLayout->addWidget(label_10);

        decode_textBrowser = new QTextBrowser(horizontalLayoutWidget);
        decode_textBrowser->setObjectName("decode_textBrowser");

        verticalLayout->addWidget(decode_textBrowser);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 4);
        verticalLayout->setStretch(6, 2);
        verticalLayout->setStretch(7, 1);
        verticalLayout->setStretch(8, 4);
        verticalLayout->setStretch(9, 1);
        verticalLayout->setStretch(10, 5);

        horizontalLayout->addLayout(verticalLayout);

        frame_2 = new QFrame(horizontalLayoutWidget);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::VLine);
        frame_2->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        verticalLayout_3->addWidget(label);

        Text_textBrowser = new QTextBrowser(horizontalLayoutWidget);
        Text_textBrowser->setObjectName("Text_textBrowser");
        Text_textBrowser->setFont(font);

        verticalLayout_3->addWidget(Text_textBrowser);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        Freq_textBrowser = new QTextBrowser(horizontalLayoutWidget);
        Freq_textBrowser->setObjectName("Freq_textBrowser");
        Freq_textBrowser->setFont(font);

        verticalLayout_3->addWidget(Freq_textBrowser);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName("label_9");

        verticalLayout_3->addWidget(label_9);

        HuffTree_textBrowser = new QTextBrowser(horizontalLayoutWidget);
        HuffTree_textBrowser->setObjectName("HuffTree_textBrowser");
        HuffTree_textBrowser->setFont(font);

        verticalLayout_3->addWidget(HuffTree_textBrowser);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);

        printTree_textBrowser = new QTextBrowser(horizontalLayoutWidget);
        printTree_textBrowser->setObjectName("printTree_textBrowser");
        printTree_textBrowser->setFont(font);

        verticalLayout_2->addWidget(printTree_textBrowser);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        HuffCode_textBrowser = new QTextBrowser(horizontalLayoutWidget);
        HuffCode_textBrowser->setObjectName("HuffCode_textBrowser");
        HuffCode_textBrowser->setFont(font);

        verticalLayout_2->addWidget(HuffCode_textBrowser);

        label_11 = new QLabel(horizontalLayoutWidget);
        label_11->setObjectName("label_11");

        verticalLayout_2->addWidget(label_11);

        CodedSequence_textBrowser = new QTextBrowser(horizontalLayoutWidget);
        CodedSequence_textBrowser->setObjectName("CodedSequence_textBrowser");
        CodedSequence_textBrowser->setFont(font);

        verticalLayout_2->addWidget(CodedSequence_textBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_2->addWidget(label_6);

        wpl_textBrowser = new QTextBrowser(horizontalLayoutWidget);
        wpl_textBrowser->setObjectName("wpl_textBrowser");
        wpl_textBrowser->setFont(font);

        horizontalLayout_2->addWidget(wpl_textBrowser);


        verticalLayout_2->addLayout(horizontalLayout_2);

        clearButton = new QPushButton(horizontalLayoutWidget);
        clearButton->setObjectName("clearButton");

        verticalLayout_2->addWidget(clearButton);

        returnButton = new QPushButton(horizontalLayoutWidget);
        returnButton->setObjectName("returnButton");

        verticalLayout_2->addWidget(returnButton);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 15);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 7);
        verticalLayout_2->setStretch(4, 1);
        verticalLayout_2->setStretch(5, 5);
        verticalLayout_2->setStretch(6, 1);
        verticalLayout_2->setStretch(7, 2);
        verticalLayout_2->setStretch(8, 2);

        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(HuffmanWindow);

        QMetaObject::connectSlotsByName(HuffmanWindow);
    } // setupUi

    void retranslateUi(QWidget *HuffmanWindow)
    {
        HuffmanWindow->setWindowTitle(QCoreApplication::translate("HuffmanWindow", "HuffmanWindow", nullptr));
        writeFile_Button->setText(QCoreApplication::translate("HuffmanWindow", "\345\206\231\345\205\245Text.txt\346\226\207\344\273\266", nullptr));
        buileTree_Button->setText(QCoreApplication::translate("HuffmanWindow", "\344\273\216Text.txt\346\226\207\344\273\266\350\257\273\345\217\226\346\226\207\346\234\254\345\271\266\346\236\204\345\273\272\345\223\210\345\244\253\346\233\274\346\240\221", nullptr));
        label_7->setText(QCoreApplication::translate("HuffmanWindow", "\350\257\267\350\276\223\345\205\245\346\226\260\346\226\207\346\234\254\357\274\232", nullptr));
        encodeButton->setText(QCoreApplication::translate("HuffmanWindow", "\347\274\226\347\240\201", nullptr));
        label_8->setText(QCoreApplication::translate("HuffmanWindow", "\346\226\260\346\226\207\346\234\254\347\274\226\347\240\201\347\273\223\346\236\234\357\274\232\343\200\220HuffEncoding.txt\343\200\221", nullptr));
        label_10->setText(QCoreApplication::translate("HuffmanWindow", "\350\247\243\347\240\201\347\273\223\346\236\234\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("HuffmanWindow", "\345\216\237\345\247\213\346\226\207\346\234\254\357\274\232\343\200\220Text.txt\343\200\221", nullptr));
        label_2->setText(QCoreApplication::translate("HuffmanWindow", "\351\242\221\345\272\246\347\273\237\350\256\241\347\273\223\346\236\234\357\274\232\343\200\220Freq.txt\343\200\221", nullptr));
        label_3->setText(QCoreApplication::translate("HuffmanWindow", "\351\241\272\345\272\217\345\255\230\345\202\250\357\274\232\343\200\220HuffTree.txt\343\200\221", nullptr));
        label_9->setText(QCoreApplication::translate("HuffmanWindow", "\357\274\210\344\270\213\346\240\207\357\274\214\346\235\203\345\200\274\357\274\214\345\217\214\344\272\262\357\274\214\345\267\246\345\255\251\345\255\220\357\274\214\345\217\263\345\255\251\345\255\220\357\274\211", nullptr));
        label_5->setText(QCoreApplication::translate("HuffmanWindow", "\345\223\210\345\244\253\346\233\274\346\240\221\347\232\204\346\240\221\347\212\266\350\241\250\347\244\272\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("HuffmanWindow", "\347\274\226\347\240\201\347\273\223\346\236\234\357\274\232\343\200\220HuffCode.txt\343\200\221", nullptr));
        label_11->setText(QCoreApplication::translate("HuffmanWindow", "\347\274\226\347\240\201\345\272\217\345\210\227\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("HuffmanWindow", "WPL\357\274\232", nullptr));
        clearButton->setText(QCoreApplication::translate("HuffmanWindow", "\346\270\205\347\251\272\345\223\210\345\244\253\346\233\274\346\240\221", nullptr));
        returnButton->setText(QCoreApplication::translate("HuffmanWindow", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HuffmanWindow: public Ui_HuffmanWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUFFMANWINDOW_H
