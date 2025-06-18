#include <QMessageBox>
#include <QStringListModel>
#include "../HeaderFiles/bstwindow.h"
#include "../UIFiles/ui_bstwindow.h"
#include "../HeaderFiles/mainwindow.h"


BSTWindow::BSTWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::BSTWindow) {
    ui->setupUi(this);

    this->root = nullptr;

    // printTree_textBrowser设置水平滚动条策略 + 关闭自动换行
    ui->printTree_textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->printTree_textBrowser->setWordWrapMode(QTextOption::NoWrap);

    // 点击返回按钮（returnButton）的时候返回主窗口，同时关闭当前窗口
    connect(ui->returnButton, &QPushButton::clicked, [=]() {
        this->close();
        auto *mainWindow = new MainWindow();
        mainWindow->show();
    });

    // 点击createButton时从getN_lineEdit获取输入的n，并调用createBST_random函数创建一棵BST
    connect(ui->createBSTButton, &QPushButton::clicked, [=]() {
        int num = ui->getN_lineEdit->text().toInt();
        if (num <= 0) {
            QMessageBox::warning(this, "警告", "请输入大于0的整数");
            return;
        }
        this->root = createBST_random(this->root, num);
        this->updateTreeViews();
        ui->getN_lineEdit->clear();
    });


    // 点击delete按钮时候，从treeNode_comboBox中获取要删除的节点，并调用deleteBSTNode函数删除该节点
    connect(ui->deleteButton, &QPushButton::clicked, [=]() {
        QString text = ui->treeNode_comboBox->currentText();
        deleteBSTNode(this->root, text.toInt());
        this->updateTreeViews();
    });

    // 点击insertButton时，从insertKey_lineEdit获取输入的n，并调用insertBST函数插入该节点
    connect(ui->insertButton, &QPushButton::clicked, [=]() {
        bool ok;
        int key = ui->insertKey_lineEdit->text().toInt(&ok);
        if (!ok) {  // 如果输入的不是整数，弹出警告信息
            QMessageBox::warning(this, "警告", "请输入整数");
        } else if (searchBST(this->root, key)) {
            QMessageBox::warning(this, "警告", QString("值为%1的节点已存在").arg(key));
        } else {  // 插入成功的弹窗
            this->root = insertBST(this->root, key);
            this->updateTreeViews();
            // QMessageBox::information(this, "提示", QString("插入值为%1的节点成功").arg(key));
        }
        ui->insertKey_lineEdit->clear();
    });

    // 点击searchBST_pushButton时，从searchBST_lineEdit获取输入的key，并调用searchBST函数搜索该节点
    connect(ui->searchBST_pushButton, &QPushButton::clicked, [=]() {
        bool ok;

        int input = ui->searchBST_lineEdit->text().toInt(&ok);
        if (!ok) {  // 如果输入的不是整数，弹出警告信息
            QMessageBox::warning(this, "警告", "请输入整数");
            return;
        } else {
            if (searchBST(this->root, input)) {
                QMessageBox::information(this, "提示", QString("找到值为%1的节点").arg(input));

                // 在nodeInfo_textBrowser显示节点在二叉树中的位置情况（层次、父节点、兄弟、左右孩子）、前驱、后继
                char info[1024] = {0};
                getNodeInfo(this->root, input, info);
                ui->nodeInfo_textBrowser->setText(info);
            } else {
                QMessageBox::warning(this, "警告", QString("未找到值为%1的节点").arg(input));
                ui->nodeInfo_textBrowser->setText(QString("不存在值为%1的节点！\n").arg(input));
            }
        }
    });

    // 点击clearTree_pushButton的时候清空树
    connect(ui->clearTree_pushButton, &QPushButton::clicked, [=]() {
        this->root = nullptr;
        this->updateTreeViews();
        ui->nodeInfo_textBrowser->clear();
        ui->searchBST_lineEdit->clear();
    });

}

void BSTWindow::updateTreeViews() {
    // 在inorder_textBrowser显示中序遍历序列
    char inorderResult[1024] = {0};
    inorderTraversal(this->root, inorderResult);
    ui->inorder_textBrowser->setText(inorderResult);

    // 在reverseInorder_textBrowser显示逆序遍历序列
    char reverseInorderResult[1024] = {0};
    reverseInorderTraversal(this->root, reverseInorderResult);
    ui->reverseInorder_textBrowser->setText(reverseInorderResult);

    // inorderResult是一个以空格为分隔符的节点序列，将其依次添加到下拉菜单中
    QStringList list = QString(inorderResult).split(" ");
    ui->treeNode_comboBox->clear();
    for (const auto &i: list) {
        ui->treeNode_comboBox->addItem(i);
    }

    if (this->root != nullptr) {
        char printResult[1048576] = {0};
        printTree(this->root, printResult);
        ui->printTree_textBrowser->setText(printResult);

        printf("\n%s", printResult);
    } else {
        ui->printTree_textBrowser->setText("空树!");
    }
}

BSTWindow::~BSTWindow() {
    delete ui;
}
