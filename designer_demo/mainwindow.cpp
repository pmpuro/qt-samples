#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(
            this, SIGNAL(uusiIndeksi(double)),
            ui->lcdNumber, SLOT(display(double)));

    connect(ui->painoSlider, SIGNAL(valueChanged(int)), this, SLOT(laskeIndeksi()));
    connect(ui->pituusSlider, SIGNAL(valueChanged(int)), this, SLOT(laskeIndeksi()));

    connect(ui->painoSlider, SIGNAL(valueChanged(int)), ui->painoLabel, SLOT(setNum(int)));
    connect(ui->pituusSlider, SIGNAL(valueChanged(int)), ui->pituusLabel, SLOT(setNum(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::laskeIndeksi()
{
    const double paino = (double)ui->painoSlider->value();
    const double pituus = (double)ui->pituusSlider->value() /100;

    const double indeksi = paino / pituus / pituus;

    emit uusiIndeksi(indeksi);
}
