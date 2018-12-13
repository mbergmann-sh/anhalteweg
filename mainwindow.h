#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStyle>
#include <QFile>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Tempo_spinBox_valueChanged();

private:
    Ui::MainWindow *ui;
    double reaktionsweg(double tempo);
    double anhalteweg(double bweg, double rweg);
    double bremsweg(double tempo);
};

#endif // MAINWINDOW_H
