/********************************************************************************
** Form generated from reading UI file 'bstwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BSTWINDOW_H
#define UI_BSTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BSTWindow
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_1;
    QVBoxLayout *verticalLayout_1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_1;
    QLineEdit *getN_lineEdit;
    QPushButton *createBSTButton;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLineEdit *insertKey_lineEdit;
    QPushButton *insertButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *treeNode_comboBox;
    QPushButton *deleteButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *searchBST_lineEdit;
    QPushButton *searchBST_pushButton;
    QLabel *label_6;
    QTextBrowser *nodeInfo_textBrowser;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTextBrowser *inorder_textBrowser;
    QLabel *label_4;
    QTextBrowser *reverseInorder_textBrowser;
    QLabel *label_7;
    QTextBrowser *printTree_textBrowser;
    QVBoxLayout *verticalLayout;
    QPushButton *clearTree_pushButton;
    QPushButton *returnButton;

    void setupUi(QWidget *BSTWindow)
    {
        if (BSTWindow->objectName().isEmpty())
            BSTWindow->setObjectName("BSTWindow");
        BSTWindow->resize(1031, 667);
        layoutWidget = new QWidget(BSTWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 1011, 651));
        horizontalLayout_1 = new QHBoxLayout(layoutWidget);
        horizontalLayout_1->setObjectName("horizontalLayout_1");
        horizontalLayout_1->setContentsMargins(0, 0, 0, 0);
        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setObjectName("verticalLayout_1");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName("label_1");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_1->sizePolicy().hasHeightForWidth());
        label_1->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_1);

        getN_lineEdit = new QLineEdit(layoutWidget);
        getN_lineEdit->setObjectName("getN_lineEdit");

        horizontalLayout_2->addWidget(getN_lineEdit);

        createBSTButton = new QPushButton(layoutWidget);
        createBSTButton->setObjectName("createBSTButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(createBSTButton->sizePolicy().hasHeightForWidth());
        createBSTButton->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(createBSTButton);


        verticalLayout_1->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(label);

        insertKey_lineEdit = new QLineEdit(layoutWidget);
        insertKey_lineEdit->setObjectName("insertKey_lineEdit");

        horizontalLayout_7->addWidget(insertKey_lineEdit);

        insertButton = new QPushButton(layoutWidget);
        insertButton->setObjectName("insertButton");

        horizontalLayout_7->addWidget(insertButton);


        verticalLayout_1->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_2);

        treeNode_comboBox = new QComboBox(layoutWidget);
        treeNode_comboBox->setObjectName("treeNode_comboBox");

        horizontalLayout_3->addWidget(treeNode_comboBox);

        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout_3->addWidget(deleteButton);


        verticalLayout_1->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        searchBST_lineEdit = new QLineEdit(layoutWidget);
        searchBST_lineEdit->setObjectName("searchBST_lineEdit");

        horizontalLayout_4->addWidget(searchBST_lineEdit);

        searchBST_pushButton = new QPushButton(layoutWidget);
        searchBST_pushButton->setObjectName("searchBST_pushButton");

        horizontalLayout_4->addWidget(searchBST_pushButton);


        verticalLayout_1->addLayout(horizontalLayout_4);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        verticalLayout_1->addWidget(label_6);

        nodeInfo_textBrowser = new QTextBrowser(layoutWidget);
        nodeInfo_textBrowser->setObjectName("nodeInfo_textBrowser");
        nodeInfo_textBrowser->setMaximumSize(QSize(16777215, 200));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Sans Typewriter")});
        nodeInfo_textBrowser->setFont(font);

        verticalLayout_1->addWidget(nodeInfo_textBrowser);

        verticalLayout_1->setStretch(0, 2);
        verticalLayout_1->setStretch(1, 2);
        verticalLayout_1->setStretch(2, 2);
        verticalLayout_1->setStretch(3, 2);
        verticalLayout_1->setStretch(4, 1);
        verticalLayout_1->setStretch(5, 3);

        horizontalLayout_1->addLayout(verticalLayout_1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        inorder_textBrowser = new QTextBrowser(layoutWidget);
        inorder_textBrowser->setObjectName("inorder_textBrowser");
        inorder_textBrowser->setFont(font);

        verticalLayout_2->addWidget(inorder_textBrowser);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        reverseInorder_textBrowser = new QTextBrowser(layoutWidget);
        reverseInorder_textBrowser->setObjectName("reverseInorder_textBrowser");
        reverseInorder_textBrowser->setFont(font);

        verticalLayout_2->addWidget(reverseInorder_textBrowser);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        verticalLayout_2->addWidget(label_7);

        printTree_textBrowser = new QTextBrowser(layoutWidget);
        printTree_textBrowser->setObjectName("printTree_textBrowser");
        printTree_textBrowser->setFont(font);

        verticalLayout_2->addWidget(printTree_textBrowser);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 1);
        verticalLayout_2->setStretch(4, 1);
        verticalLayout_2->setStretch(5, 15);

        horizontalLayout_1->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        clearTree_pushButton = new QPushButton(layoutWidget);
        clearTree_pushButton->setObjectName("clearTree_pushButton");

        verticalLayout->addWidget(clearTree_pushButton);

        returnButton = new QPushButton(layoutWidget);
        returnButton->setObjectName("returnButton");

        verticalLayout->addWidget(returnButton);


        horizontalLayout_1->addLayout(verticalLayout);

        horizontalLayout_1->setStretch(0, 1);
        horizontalLayout_1->setStretch(1, 6);
        horizontalLayout_1->setStretch(2, 1);

        retranslateUi(BSTWindow);

        QMetaObject::connectSlotsByName(BSTWindow);
    } // setupUi

    void retranslateUi(QWidget *BSTWindow)
    {
        BSTWindow->setWindowTitle(QCoreApplication::translate("BSTWindow", "BSTWindow", nullptr));
        label_1->setText(QCoreApplication::translate("BSTWindow", "\350\257\267\350\276\223\345\205\245\350\212\202\347\202\271\346\225\260N\357\274\232", nullptr));
        createBSTButton->setText(QCoreApplication::translate("BSTWindow", "\351\232\217\346\234\272\347\224\237\346\210\220N\344\270\252\350\212\202\347\202\271\346\267\273\345\212\240\345\210\260\344\272\214\345\217\211\346\216\222\345\272\217\346\240\221", nullptr));
        label->setText(QCoreApplication::translate("BSTWindow", "\350\257\267\350\276\223\345\205\245\346\217\222\345\205\245\347\232\204\350\212\202\347\202\271\347\232\204\345\200\274\357\274\232", nullptr));
        insertButton->setText(QCoreApplication::translate("BSTWindow", "\346\217\222\345\205\245", nullptr));
        label_2->setText(QCoreApplication::translate("BSTWindow", "\350\257\267\351\200\211\346\213\251\350\212\202\347\202\271\357\274\232", nullptr));
        deleteButton->setText(QCoreApplication::translate("BSTWindow", "\345\210\240\351\231\244", nullptr));
        label_5->setText(QCoreApplication::translate("BSTWindow", "\350\257\267\350\276\223\345\205\245\345\270\246\346\237\245\350\257\242\350\212\202\347\202\271\347\232\204\345\200\274\357\274\232", nullptr));
        searchBST_pushButton->setText(QCoreApplication::translate("BSTWindow", "\346\237\245\350\257\242", nullptr));
        label_6->setText(QCoreApplication::translate("BSTWindow", "\346\237\245\350\257\242\345\210\260\347\232\204\350\212\202\347\202\271\344\277\241\346\201\257\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("BSTWindow", "\344\270\255\345\272\217\351\201\215\345\216\206\345\272\217\345\210\227\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("BSTWindow", "\351\200\206\345\272\217\347\232\204\344\270\255\345\272\217\351\201\215\345\216\206\345\272\217\345\210\227\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("BSTWindow", "\346\240\221\347\212\266\350\241\250\347\244\272\345\233\276\357\274\232", nullptr));
        clearTree_pushButton->setText(QCoreApplication::translate("BSTWindow", "\346\270\205\347\251\272\344\272\214\345\217\211\346\216\222\345\272\217\346\240\221", nullptr));
        returnButton->setText(QCoreApplication::translate("BSTWindow", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BSTWindow: public Ui_BSTWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BSTWINDOW_H
