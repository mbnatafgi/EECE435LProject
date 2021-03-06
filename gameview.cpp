/**
* \file gameview.cpp
* \brief gameview class definition
*
* a gameview is where the game scene resides
*\author Bilal Natafgi
*\date 20-2-2018
*/

#include "gameview.h"
#include "ui_gameview.h"
#include <QMediaPlaylist>
#include <QMediaPlayer>

GameView::GameView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameView)
{
    ui->setupUi(this);
    this->gameScene = new QGraphicsScene();

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/Project435/resources/background.ogg"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

}

GameView::~GameView()
{
    delete ui;
    delete this->gameScene;
}
/// creating the scene ( game 1 or 2), and centering the game in the middle of the screen.
void GameView::setScene(QGraphicsScene* gameScene){
    this->gameScene = gameScene;
    ui->graphicsView->setScene(this->gameScene);
    ui->graphicsView->setFixedSize(1000,600);
    ui->graphicsView->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    ui->graphicsView->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    ui->graphicsView->show();
    ui->graphicsView->setFocus();

}


