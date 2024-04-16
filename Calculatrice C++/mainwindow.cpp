#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_aff = "";
    m_res = 0.0;
    m_op = false; //il n'y a pas d'operateur au debut
    bl=false;
    m_coeff = 0;
    m_affine = 0;
    m_v = ','; //caractere a changer par '.' si le calcul ne prend pas en compte les virgules
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b0_clicked()
{
    m_aff += "0";
    ui->ecran->setText(m_aff);
}


void MainWindow::on_b1_clicked()
{
    m_aff += "1";
    ui->ecran->setText(m_aff);
}


void MainWindow::on_b2_clicked()
{
    m_aff += "2";
    ui->ecran->setText(m_aff);
}


void MainWindow::on_b3_clicked()
{
    m_aff += "3";
    ui->ecran->setText(m_aff);
}


void MainWindow::on_b4_clicked()
{
    m_aff += "4";
    ui->ecran->setText(m_aff);
}


void MainWindow::on_b5_clicked()
{
    m_aff += "5";
    ui->ecran->setText(m_aff);
}


void MainWindow::on_b6_clicked()
{
    m_aff += "6";
    ui->ecran->setText(m_aff);
}


void MainWindow::on_b7_clicked()
{
    m_aff += "7";
    ui->ecran->setText(m_aff);
}


void MainWindow::on_b8_clicked()
{
    m_aff += "8";
    ui->ecran->setText(m_aff);
}


void MainWindow::on_b9_clicked()
{
    m_aff += "9";
    ui->ecran->setText(m_aff);
}


void MainWindow::on_bplus_clicked()
{
    //conversion de Qstring en string
    string aff = m_aff.toStdString();
    //on verifie que la chaine n'est pas vide et que le dernier caractere est un chiffre
    if (!m_op && aff.size()!=0 && isdigit(aff.at(aff.size()-1)))
    {
        m_aff += "+";
        ui->ecran->setText(m_aff);
        m_op = true; //on garde en memoire qu'il y a un operateur
    }
}


void MainWindow::on_bmoins_clicked()
{
    //conversion de Qstring en string
    string aff = m_aff.toStdString();
    //On accepte le moins en debut d'operation
    //Sinon, on verifie que le dernier caractere est un chiffre
    if (!m_op && (aff.size()==0 || isdigit(aff.at(aff.size()-1))))
    {
        m_aff += "-";
        ui->ecran->setText(m_aff);
        if (aff.size()!=0)
            m_op = true; //on garde en memoire qu'il y a un operateur (a part si le - est au debut)
    }
}


void MainWindow::on_bfois_clicked()
{
    //conversion de Qstring en string
    string aff = m_aff.toStdString();
    //on verifie que la chaine n'est pas vide et que le dernier caractere est un chiffre
    if (!m_op && aff.size()!=0 && isdigit(aff.at(aff.size()-1)))
    {
        m_aff += "*";
        ui->ecran->setText(m_aff);
        m_op = true; //on garde en memoire qu'il y a un operateur
    }
}


void MainWindow::on_bslash_clicked()
{
    //conversion de Qstring en string
    string aff = m_aff.toStdString();
    //on verifie que la chaine n'est pas vide et que le dernier caractere est un chiffre
    if (!m_op && aff.size()!=0 && isdigit(aff.at(aff.size()-1)))
    {
        m_aff += "/";
        ui->ecran->setText(m_aff);
        m_op = true; //on garde en memoire qu'il y a un operateur
    }
}


void MainWindow::on_begal_clicked()
{
    //conversion de Qstring en string
    string aff = m_aff.toStdString();

    //recherche de l'operateur
    int i=1; //on part de 1 pour le cas ou le premier caractere serait un -
    while (i<aff.size() && (isdigit(aff.at(i)) || aff.at(i)==m_v))
        i++;

    bool div0 = false;
    //on doit bien avoir trouve l'operateur et le dernier caractere doit etre un chiffre
    if (i!=aff.size() && isdigit(aff.at(aff.size()-1)))
    {
        m_res = stof(aff.substr(0,i)); //premier nombre converti en float
        switch (aff.at(i)) //operateur
        {
            case '+':
                m_res += stof(aff.substr(i+1,aff.size()-i)); //premier nombre + deuxieme nombre
            break;
            case '-':
                m_res -= stof(aff.substr(i+1,aff.size()-i)); //premier nombre - deuxieme nombre
                break;
            case '*':
                m_res *= stof(aff.substr(i+1,aff.size()-i)); //premier nombre * deuxieme nombre
                break;
            case '/':
                if (stof(aff.substr(i+1,aff.size()-i-1))!=0) //on verifie que le deuxieme nombre ne vaut pas 0
                    m_res /= stof(aff.substr(i+1,aff.size()-i)); //premier nombre / deuxieme nombre
                else
                    div0 = true;
                break;
        }
        if (!div0)
            m_aff = QString::number(m_res);
        else
            m_aff = "erreur : division par 0";
        ui->ecran->setText(m_aff);
        m_aff = "";
        m_op = false;
    }
}


void MainWindow::on_bpoint_clicked()
{
    //conversion de Qstring en string
    string aff = m_aff.toStdString();
    //On accepte le point en debut d'operation
    if (aff.size()==0)
    {
        m_aff += m_v;
        ui->ecran->setText(m_aff);
    }
    else
    {
        bool ok = false;
        int i = aff.size(); //on parcourt la chaine a partir de la fin
        while (!ok && i>0)
        {
            i--;
            if (aff.at(i)==m_v) //point avant le dernier operateur
                i = 0; //on sort de la boucle avec ok=false
            else
            {
                //si ce n'est ni un chiffre, ni un point, c'est un operateur
                if (!(isdigit(aff.at(i))) || i==0)
                    ok = true; //sort de la boucle avec ok=true
            }
        }
        if (ok)
        {
            m_aff += m_v;
            ui->ecran->setText(m_aff);
        }
    }
}


//Pour la partie graphique
void MainWindow::paintEvent(QPaintEvent* e){
    QPainter painter(this);
    painter.drawText(50,40,QString("Trace de Ax + B :"));
    painter.drawText(65,250,QString("A"));
    painter.drawText(155,250,QString("B"));
    QPainter myline(this);
    myline.drawRect(50,50,150,150);
    myline.fillRect(51,51,149,149,QBrush(Qt::white));
    myline.drawLine(125,50,125,200);
    myline.drawLine(50,125,200,125);
    if (bl) //s'exécute lorsqu'on appuie sur Tracer
    {
        float Ax = 50; //Point sur le bord gauche
        float Ay = 75*m_coeff-m_affine*5+125; //obtenu avec y = a*x + b, 1 unite = 5

        if (Ay<50 || Ay>200) //si on depasse du graphe
        {
            Ay = 50; //Point sur le bord du haut
            Ax = (75-m_affine*5)/m_coeff + 125; //obtenu avec y = a*x + b
            if (Ax<50 || Ax>200)
            {
                Ay = 200; //Point sur le bord du bas
                Ax = (-75-m_affine*5)/m_coeff + 125;
            }
        }

        float Bx = 200; //Point sur le bord droit
        float By = -75*m_coeff-m_affine*5+125;

        if (By<50 || By>200) //si on depasse du graphe
        {
            By = 200; //Point sur le bord du bas
            Bx = (-75-m_affine*5)/m_coeff + 125;
            if (Bx<50 || Bx>200) //si on depasse du graphe
            {
                By = 50; //Point sur le bord du haut
                Bx = (75-m_affine*5)/m_coeff + 125;
            }
        }
        myline.setPen( QPen(Qt::red, 1) );
        myline.drawLine(Ax,Ay,Bx,By); //on relie les points
        bl=false; //permet de retracer une autre courbe apres
    }
}

void MainWindow::on_coeff_textEdited(const QString &coeff)
{
    m_coeff = coeff.toFloat();
}


void MainWindow::on_affine_textEdited(const QString &affine)
{
    m_affine=affine.toFloat();
}


void MainWindow::on_Tracer_clicked()
{
        bl=true;
        repaint(); //rappel la fonction paintEvent
}

