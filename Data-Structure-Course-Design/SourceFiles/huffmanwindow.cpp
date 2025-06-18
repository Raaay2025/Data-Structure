//
// Created by 27574 on 2024/6/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_HuffmanWindow.h" resolved

#include <QFileDialog>
#include <QMessageBox>
#include "../HeaderFiles/huffmanwindow.h"
#include "../UIFiles/ui_huffmanwindow.h"
#include "../HeaderFiles/mainwindow.h"
#include "../HeaderFiles/huffman.h"


HuffmanWindow::HuffmanWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::HuffmanWindow) {
    ui->setupUi(this);

    // printTree_textBrowser设置水平滚动条策略 + 关闭自动换行
    ui->printTree_textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->printTree_textBrowser->setWordWrapMode(QTextOption::NoWrap);

    // 点击returnButton的时候返回主窗口，同时关闭当前窗口
    connect(ui->returnButton, &QPushButton::clicked, [=]() {
        this->close();
        auto *mainWindow = new MainWindow();
        mainWindow->show();
    });

    // 点击readFileButton的时候，从文件读取文本，构建哈夫曼树
    connect(ui->buileTree_Button, &QPushButton::clicked, [=]() {
        // 当TEXT_FILE（txt文本文件）文件内容为空的时候，提示错误信息
        QFile file(TEXT_FILE);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file";
            return;
        }
        QTextStream in(&file);
        QString fileContent = in.readAll();
        file.close();
        if (fileContent.isEmpty()) {
            QMessageBox::warning(this, "警告", "文件内容为空!");
            return;
        } else {
            ui->Text_textBrowser->setText(fileContent);
        }

        // 从文件读取文本并统计频率
        calculate_frequency(this->TEXT_FILE, this->FREQ_FILE);
        showFile(this->FREQ_FILE, ui->Freq_textBrowser);

        // 从频率文件中读取频率并建立哈夫曼树
        this->tree = build_huffman_tree(this->FREQ_FILE);
        save_huffman_tree(this->tree, this->HUFF_TREE_FILE);
        showFile(HUFF_TREE_FILE, ui->HuffTree_textBrowser);

        // 显示哈夫曼树
        char printResult[1048576] = {0};
        display_huffman_tree(this->tree, printResult);
        ui->printTree_textBrowser->setText(printResult);

        // 生成哈夫曼编码并保存到文件
        generate_huffman_codes(tree, HUFF_CODE_FILE);
        showFile(HUFF_CODE_FILE, ui->HuffCode_textBrowser);

        // 输出哈夫曼树的WPL值
        int wpl = calculate_wpl(tree);
        ui->wpl_textBrowser->setText(QString::number(wpl));

        // 显示编码序列
        encode_text(HUFF_CODE_FILE, CODEDSEQUENCE_FILE, TEXT_FILE);
        showFile(CODEDSEQUENCE_FILE, ui->CodedSequence_textBrowser);

    });

    // 点击writeFile_Button的时候，从writeFile_textEdit读取文本，写入TEXT_FILE（.txt文件）
    connect(ui->writeFile_Button, &QPushButton::clicked, [=]() {
        // writeFile_textEdit为空或者全是空格字符的时候，提示错误信息
        if (ui->writeFile_textEdit->toPlainText().trimmed().isEmpty() ||
            ui->writeFile_textEdit->toPlainText().trimmed().isEmpty()) {
            QMessageBox::warning(this, "警告", "文本框为空，请先输入文本");
            ui->writeFile_textEdit->clear();
            return;
        }

        // 获取writeFile_textEdit中的文本，写入TEXT_FILE（.txt文件）
        QString text = ui->writeFile_textEdit->toPlainText();
        QFile file(TEXT_FILE);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file";
            return;
        }
        QTextStream out(&file);
        out << text;
        file.close();
        showFile(this->TEXT_FILE, ui->Text_textBrowser);

        // 清空
        ui->Freq_textBrowser->clear();
        ui->HuffTree_textBrowser->clear();
        ui->printTree_textBrowser->clear();
        ui->HuffCode_textBrowser->clear();
        ui->wpl_textBrowser->clear();
    });

    // 点击encodeButton的时候，从getNewText_lineEdit读取文本，写入INPUTTEXT_FILE
    connect(ui->encodeButton, &QPushButton::clicked, [=]() {
        if (ui->getNewText_lineEdit->text().trimmed().isEmpty()) {
            QMessageBox::warning(this, "警告", "文本框为空，请先输入文本");
            ui->getNewText_lineEdit->clear();
            return;
        }
        QString text = ui->getNewText_lineEdit->text();
        QFile file(this->INPUTTEXT_FILE);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file";
            return;
        }
        QTextStream out(&file);
        out << text;
        file.close();

        // 对新输入的文本进行哈夫曼编码
        encode_text(HUFF_CODE_FILE, HUFF_ENCODING_FILE, INPUTTEXT_FILE);

        showFile(HUFF_ENCODING_FILE, ui->HuffEncoding_textBrowser);

        // 对编码的文本进行解码并显示
        QFile file_decode(HUFF_ENCODING_FILE);
        if (!file_decode.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open file";
            return;
        }
        QTextStream in(&file_decode);
        auto fileContent = in.readAll();
        file_decode.close();
        char *decodeText = decode_text(fileContent.toStdString().c_str(), this->tree);
        ui->decode_textBrowser->setText(decodeText);
    });

    // 点击clearButton的时候，清空所有文本框和显示框
    connect(ui->clearButton, &QPushButton::clicked, [=]() {
        ui->Text_textBrowser->clear();
        ui->Freq_textBrowser->clear();
        ui->HuffTree_textBrowser->clear();
        ui->printTree_textBrowser->clear();
        ui->HuffCode_textBrowser->clear();
        ui->wpl_textBrowser->clear();
        ui->writeFile_textEdit->clear();
        ui->getNewText_lineEdit->clear();
        ui->HuffEncoding_textBrowser->clear();
        ui->decode_textBrowser->clear();

        free_huffman_tree(this->tree);

        this->tree = nullptr;
    });


}

void HuffmanWindow::showFile(const char *filepath, QTextBrowser *textBrowser) {
    // 读取.txt文件的内容，显示在textBrowser
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
        return;
    }
    QTextStream in(&file);
    QString fileContent = in.readAll();
    file.close();
    textBrowser->setPlainText(fileContent);
}

HuffmanWindow::~HuffmanWindow() {
    delete ui;
}
