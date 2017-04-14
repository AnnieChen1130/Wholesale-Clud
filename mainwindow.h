#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "wholesale.h"
#include "linkedlist.h"
#include "item.h"
#include "club.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
//    void addMember();
    void readFromFile();




    void deleteMember();

    void displayMemberList();

    Wholesale searchMember();



    void on_addMember_clicked();


    void on_displayMemberList_clicked();

private:
    Ui::MainWindow *ui;
    LinkedList <Wholesale> memberList;
    LinkedList <Item> itemList;


};

#endif // MAINWINDOW_H
