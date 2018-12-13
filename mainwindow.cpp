#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Tempo_dial->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Reaktionsweg berechnen */
double MainWindow::reaktionsweg(double tempo)
{

    double rweg = (tempo/10) * 3;
    return rweg;
}

/* Anhalteweg berechnen */
double MainWindow::anhalteweg(double bweg, double rweg)
{
    double aweg = bweg + rweg;
    return aweg;
}

/* Bremsweg berechnen */
double MainWindow::bremsweg(double tempo)
{
    double bweg = (tempo/10) * (tempo/10);
    return bweg;
}
void MainWindow::on_Tempo_spinBox_valueChanged()
{
    QString status = "";
    ui->lcd_g_mindest->display(ui->Tempo_spinBox->value() / 2);                                     // Mindestabstand bei guter Sicht
    ui->lcd_s_mindest->display(ui->Tempo_spinBox->value());                                         // Mindestabstan bei schlechter Sicht
    ui->lcd_rweg->display(reaktionsweg(ui->Tempo_spinBox->value()));                                // Reaktionsweg
    ui->lcd_n_bweg->display(bremsweg(ui->Tempo_spinBox->value()));                                  // Bremsweg (normal)
    ui->lcd_n_aweg->display(anhalteweg(ui->lcd_n_bweg->intValue(), ui->lcd_rweg->value()));         // Anhalteweg (normal)
    ui->lcd_g_bweg->display((bremsweg(ui->Tempo_spinBox->value()) / 2));                            // Bremsweg (Gefahrbremsung)
    ui->lcd_g_aweg->display(anhalteweg((ui->lcd_n_bweg->intValue() / 2), ui->lcd_rweg->value()));   // Anhalteweg (Gefahrbremsung)

    // Statusbar beschriften:
    if (ui->Tempo_spinBox->value() == 0)
    {
        status = "";
    }
    else
    {
        status = "Stillstand frühestens in " + QString::number(ui->lcd_g_aweg->intValue()) + " Metern!";
    }

    ui->statusBar->showMessage(status);
}
