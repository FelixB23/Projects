#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    m_par = new Partie();
    m_temps = new QTimer(this);
    connect(m_temps, SIGNAL(timeout()), this, SLOT(update()));
    m_sec = 0;
    m_min = 0;
    m_temps->start(10); //update est appelee toutes les centiemes de seconde
}

MainWindow::~MainWindow() {
    delete m_temps;
    delete ui;
    delete m_par;
}

void MainWindow::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);
    QPainter painter(this);
    painter.setPen( QPen(Qt::black, 1) );
    painter.setFont(QFont("Arial",20));
    if (m_par->getFinie()==false)
    {
        m_par->afficher(&painter);
        painter.drawText(CPX+13*T,CPY+T,QString("Temps : ") + QString(QString::number(m_min)) + QString("min ") +  QString(QString::number(m_sec)) + QString("sec"));
        painter.drawText(CPX+13*T,CPY+3*T,QString("Niveau : ") + QString(QString::number(m_par->getNiveau())));
        painter.drawText(CPX+13*T,CPY+5*T,QString("Score : ") + QString(QString::number(m_par->getScore())));
        painter.drawText(CPX+13*T,CPY+7*T,QString("Nombre de lignes completees : ") + QString(QString::number(m_par->getNbLignesCompletees())));
        painter.drawText(CPX+13*T,CPY+11*T,QString("Piece suivante : "));
        painter.drawText(CPX+13*T,CPY+17*T,QString("Reserve : "));
    }
    else
    {
        m_temps->stop();
        painter.drawRect(CPX+5*T, CPY, 22*T, 22*T);
        painter.fillRect(CPX+5*T+1, CPY+1, 22*T-1, 22*T-1, QBrush(Qt::white));
        painter.drawText(CPX+12*T,CPY+5*T,QString("GAME OVER"));
        painter.drawText(CPX+10*T,CPY+7*T,QString("Temps : ") + QString(QString::number(m_min)) + QString("min ") +  QString(QString::number(m_sec)) + QString("sec"));
        painter.drawText(CPX+14*T,CPY+9*T,QString("Niveau : ") + QString(QString::number(m_par->getNiveau())));
        painter.drawText(CPX+14*T,CPY+11*T,QString("Score : ") + QString(QString::number(m_par->getScore())));
        painter.drawText(CPX+6*T,CPY+13*T,QString("Nombre de lignes completees : ") + QString(QString::number(m_par->getNbLignesCompletees())));
    }
}

void MainWindow::keyPressEvent ( QKeyEvent * event) {
    if (!(m_par->getFinie()))
    {
        switch(event->key())
        {
            case Qt::Key_Left :
                if (m_par->possibTranslation(false))
                    m_par->translater(false);
                break;

            case Qt::Key_Right :
                if (m_par->possibTranslation(true))
                    m_par->translater(true);
                break;

            case Qt::Key_Down :
                if (m_par->descentePossible())
                    m_par->accelerer();
                else
                {
                    m_par->poser();
                    m_par->calculerScore();
                    m_par->pieceSuivante();
                }

                break;

            case Qt::Key_Up :
                if (m_par->possibRotation())
                    m_par->pivoter();
                break;

            case Qt::Key_Space :
                m_par->tomber();
                m_par->calculerScore();
                m_par->pieceSuivante();
                break;

            case Qt::Key_R :
                if (m_par->possibReservation())
                    m_par->reserver();
                break;
        }
        this->repaint();
    }
}

void MainWindow::update()
{
    m_sec+=0.01;
    if (int(m_sec) == 60)
    {
        m_min++;
        m_sec = 0;
    }
    if ((m_min*6000+int(m_sec*100)) % m_par->getTempsDescente() == 0)
    {
        if (m_par->descentePossible())
            m_par->accelerer();
        else
        {
            m_par->poser();
            m_par->calculerScore();
            m_par->pieceSuivante();
        }
    }
    this->repaint();
}
