#ifndef DATASTRUCTURECOURSEDESIGN_BSTWINDOW_H
#define DATASTRUCTURECOURSEDESIGN_BSTWINDOW_H

#include <QWidget>

extern "C" {
#include "bst.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class BSTWindow; }
QT_END_NAMESPACE

class BSTWindow : public QWidget {
Q_OBJECT

public:
    explicit BSTWindow(QWidget *parent = nullptr);

    ~BSTWindow() override;

    void updateTreeViews();

private:
    Ui::BSTWindow *ui;

    BSTree root;  // 存储bst数据结构
};


#endif //DATASTRUCTURECOURSEDESIGN_BSTWINDOW_H
