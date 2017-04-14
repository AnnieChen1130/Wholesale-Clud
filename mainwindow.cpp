#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linkedlist.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
//    memberList(0);
//    itemList(0)
{
     ui->setupUi(this);
     readFromFile();
//    Wholesale m1("Annie", "101", "Prefered","11/30/2017",100.10);
//    Wholesale m2("Tony", "102", "Basic", "01/01/2018", 6089.1);
//    memberList.push_back(m1);
//    memberList.push_back(m2);


}

MainWindow::~MainWindow()
{
    delete ui;

}




void MainWindow::deleteMember()
{
    Wholesale DeteledMember;
    Wholesale tempMember("",ui->removeMember->text().toStdString(),"","",0);

    DeteledMember = memberList.searchNode(tempMember);
    memberList.remove(DeteledMember);

}


void MainWindow::displayMemberList()
{
    Node<Wholesale> *temp;  //OUT - a pointer used to display
    temp = memberList.getHead();
    std::string out = "";
    out = memberList.returnData(temp).coutString();

    while(temp !=0 )
    {
        ui->output->setText(QString::fromStdString(out));

        temp = temp->next;
    }
}

void MainWindow::readFromFile()
{
    fstream inFile;
    Wholesale member;
    string name;
    string ID;
    string type;
    string expiration;



    inFile.open("warehouse shoppers.txt");
    if (inFile.fail())
       {
           cout<<"Input file opening failed.\n";
           //exit(1);
       }

    while(!inFile.eof())
    {

        getline(inFile, name, '\n');
        getline(inFile, ID, '\n');
        getline(inFile, type, '\n');
        getline(inFile, expiration, '\n');

        member.setName(name);
        member.setId(ID);
        member.setType(type);
        member.setExpiration(expiration);
        member.setSpent(0);

        memberList.push_back(member);


    }
    inFile.close();

//    memberList.display();
}




Wholesale MainWindow::searchMember()
{
    Wholesale searchMember;
    Wholesale tempMember("",ui->removeMember->text().toStdString(),"","",0);

    searchMember = memberList.searchNode(tempMember);

    std::string out = "";
    out = searchMember.printStatusString();
    ui->output->setText(QString::fromStdString(out));

    return searchMember;

}


void MainWindow::on_addMember_clicked()
{

    string name;
    string id;
    string type;
    string date;

    name = ui->Name->text().toStdString();
    id = ui->ID->text().toStdString();
    type = ui->Type->text().toStdString();
    date = ui->Expiration->text().toStdString();


    Wholesale newMember(name,id,type,date,1000);
    memberList.push_back(newMember);
    newMember.printINTOfile("warehouse shoppers.txt");

    QString line = "New member added:\n";
    line += QString::fromStdString(newMember.coutString());
    ui->output->setText(line);

}



void MainWindow::on_displayMemberList_clicked()
{

    Node<Wholesale> *temp = memberList.getHead();
    QString line;

    while(temp != NULL)
    {
        line += QString::fromStdString(temp->data.coutString());
        line += "\n";
        temp = temp->next;
    }

     ui->output->setText(line);

}
