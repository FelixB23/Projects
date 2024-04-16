#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent> //pour les touches du clavier
#include <QPaintEvent> //pour l'affichage
#include <QTimer> //pour que les tetrominos tombent tout seuls
#include "partie.h"

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
    void update();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent * event);
    void paintEvent(QPaintEvent* e);
    QTimer *m_temps;
    int m_min;
    double m_sec;
    Partie *m_par;
};

#endif // MAINWINDOW_H
