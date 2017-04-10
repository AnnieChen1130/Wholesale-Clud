#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
//    memberList(0),
//    itemList(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addMember()
{
//    std::string out ="";
    Wholesale newMember;
    ui->output->setText("Name ID MembershipType ExpirationDate");
    newMember.addNewMember(ui->Name->text().toStdString(),
                           ui->ID->text().toStdString(),
                           ui->Type->text().toStdString(),
                           ui->Expiration->text().toStdString(),
                           memberList);

//    ui->output->setText(Qstring::fromStdString(out));




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
