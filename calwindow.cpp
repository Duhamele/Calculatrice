#include "calwindow.h"
#include "./ui_calwindow.h"

CalWindow::CalWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalWindow)
{
    ui->setupUi(this);
    auto grid_input =ui->gridLayout;

    ui->textBrowser->setText("0");
    coreCal=new Interface_core_cal(ui->textBrowser);
    connect(ui->pushButton_0,&QPushButton::clicked,coreCal,[this]() {
            coreCal->addchar('0');
        });
    connect(ui->pushButton_1,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('1');
    });
    connect(ui->pushButton_2,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('2');
    });
    connect(ui->pushButton_3,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('3');
    });
    connect(ui->pushButton_4,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('4');
    });
    connect(ui->pushButton_5,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('5');
    });
    connect(ui->pushButton_6,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('6');
    });
    connect(ui->pushButton_7,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('7');
    });
    connect(ui->pushButton_8,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('8');
    });
    connect(ui->pushButton_9,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('9');
    });
    connect(ui->pushButton_add,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('+');
    });
    connect(ui->pushButton_div,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('/');
    });
    connect(ui->pushButton_mul,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('*');
    });
    connect(ui->pushButton_sub,&QPushButton::clicked,coreCal,[this]() {
        coreCal->addchar('-');
    });
    connect(ui->pushButton_equal,&QPushButton::clicked,coreCal,&Interface_core_cal::equal);

    connect(ui->pushButton_Clear,&QPushButton::clicked,coreCal,&Interface_core_cal::clear);

}

CalWindow::~CalWindow()
{
    delete ui;
}
