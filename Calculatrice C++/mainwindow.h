#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QString>
#include <iostream>
#include <string>
#include <QPaintEvent>
#include <QPainter>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_b0_clicked();

    void on_b1_clicked();

    void on_b2_clicked();

    void on_b3_clicked();

    void on_b4_clicked();

    void on_b5_clicked();

    void on_b6_clicked();

    void on_b7_clicked();

    void on_b8_clicked();

    void on_b9_clicked();

    void on_bplus_clicked();

    void on_bmoins_clicked();

    void on_bfois_clicked();

    void on_bslash_clicked();

    void on_begal_clicked();

    void on_bpoint_clicked();

    void on_coeff_textEdited(const QString &arg1);

    void on_affine_textEdited(const QString &arg1);

    void on_Tracer_clicked();

private:
    Ui::MainWindow *ui;
    QString m_aff;
    void paintEvent(QPaintEvent* e);
    float m_res;
    bool m_op; //permet de verifier s'il y a deja un operateur

    bool bl; //pour afficher à l'appui du bouton Tracer
    float m_coeff; //A
    float m_affine; //B

    char m_v; //caractere pour la virgule
};
#endif // MAINWINDOW_H
