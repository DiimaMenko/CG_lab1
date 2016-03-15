#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonCalculateValues, SIGNAL(clicked(bool)), this, SLOT(calculateValues()));
    this->firstSegment = new segment();
    this->secondSegment = new segment();
    ui->line1X1->setText("1");
    ui->line1Y1->setText("1");
    ui->line1X2->setText("100");
    ui->line1Y2->setText("100");

    ui->line2X1->setText("99");
    ui->line2Y1->setText("1");
    ui->line2X2->setText("1");
    ui->line2Y2->setText("99");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateValues(){
    this->firstSegment->setSegment(ui->line1X1->text().toFloat(), ui->line1Y1->text().toFloat(), ui->line1X2->text().toFloat(), ui->line1Y2->text().toFloat());
    this->secondSegment->setSegment(ui->line2X1->text().toFloat(), ui->line2Y1->text().toFloat(), ui->line2X2->text().toFloat(), ui->line2Y2->text().toFloat());

    ui->labelCrossPointX->setText(this->firstSegment->test(this->secondSegment));

}
