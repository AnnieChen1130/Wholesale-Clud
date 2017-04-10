#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
  memberList(0),
    itemList(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addMember()
{
    std::string inputString ="";
    Wholesale newMember;
    ui->output->setText("Name ID MembershipType ExpirationDate");
    newMember.addNewMember(ui->lineEdit->text().toStdString());





}


void MainWindow::deleteMember()
{
    Wholesale DeteledMember;
    DeteledMember = memberList->searchNode(ui->lineEdit->text().toStdString());
    memberList->remove(DeteledMember);

}
