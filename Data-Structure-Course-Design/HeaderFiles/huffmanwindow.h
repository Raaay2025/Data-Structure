//
// Created by 27574 on 2024/6/20.
//

#ifndef DATASTRUCTURECOURSEDESIGN_HUFFMANWINDOW_H
#define DATASTRUCTURECOURSEDESIGN_HUFFMANWINDOW_H

#include <QWidget>
#include <QTextBrowser>

extern "C" {
#include "huffman.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class HuffmanWindow; }
QT_END_NAMESPACE

class HuffmanWindow : public QWidget {
Q_OBJECT

public:
    explicit HuffmanWindow(QWidget *parent = nullptr);

    ~HuffmanWindow() override;

    void showFile(const char *filepath, QTextBrowser *textBrowser);

private:
    Ui::HuffmanWindow *ui;

    HuffmanTree *tree;

    // const char *TEXT_FILE = R"(E:\code\qt\DataStructureCourseDesign\data\Text.txt)";
    // const char *FREQ_FILE = R"(E:\code\qt\DataStructureCourseDesign\data\Freq.txt)";
    // const char *HUFF_TREE_FILE = R"(E:\code\qt\DataStructureCourseDesign\data\HuffTree.txt)";
    // const char *HUFF_CODE_FILE = R"(E:\code\qt\DataStructureCourseDesign\data\HuffCode.txt)";
    // const char *HUFF_ENCODING_FILE = R"(E:\code\qt\DataStructureCourseDesign\data\HuffEncoding.txt)";
    // const char *INPUTTEXT_FILE = R"(E:\code\qt\DataStructureCourseDesign\data\InputText.txt)";
    // const char *CODEDSEQUENCE_FILE = R"(E:\code\qt\DataStructureCourseDesign\data\CodedSequence.txt)";

    const char *TEXT_FILE = "../data/Text.txt";
    const char *FREQ_FILE = "../data/Freq.txt";
    const char *HUFF_TREE_FILE = "../data/HuffTree.txt";
    const char *HUFF_CODE_FILE = "../data/HuffCode.txt";
    const char *HUFF_ENCODING_FILE = "../data/HuffEncoding.txt";
    const char *INPUTTEXT_FILE = "../data/InputText.txt";
    const char *CODEDSEQUENCE_FILE = "../data/CodedSequence.txt";
};


#endif //DATASTRUCTURECOURSEDESIGN_HUFFMANWINDOW_H
