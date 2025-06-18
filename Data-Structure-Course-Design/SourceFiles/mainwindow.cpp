#include <QGraphicsScene>
#include "../HeaderFiles/mainwindow.h"
#include "../UIFiles/ui_mainwindow.h"
#include "../HeaderFiles/bstwindow.h"
#include "../HeaderFiles/huffmanwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // 点击bst按钮的时候弹出bst窗口
    connect(ui->bstButton, &QPushButton::clicked, [=]() {
        auto *bstWindow = new BSTWindow();
        bstWindow->show();
    });

    // 点击huffButton的时候弹出Huffman窗口
    connect(ui->huffButton, &QPushButton::clicked, [=]() {
        auto *huffmanWindow = new HuffmanWindow();
        huffmanWindow->show();
    });
}

MainWindow::~MainWindow() {
    delete ui;
}
