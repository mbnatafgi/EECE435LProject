#include "bomb.h"
#include <QPen>
#include "spongeBob.h"
#include <QGraphicsScene>
#include "bacteria.h"
#include "huItem.h"
#include "virus.h"
#include "fungus.h"
#include <QPointer>
#include "grabbable.h"


Bomb::Bomb()
{
    this->ready = false;
    this->step = 0;
    this->prepareTimer = new QTimer();
    this->grabbingItem = false;
    this->throwTimer = new QTimer();
    this->head = new QGraphicsPixmapItem();
    this->head->setPos(this->x()-15,this->y()+70);
    connect(this->prepareTimer,SIGNAL(timeout()),this,SLOT(update()));
    connect(this->throwTimer,SIGNAL(timeout()),this,SLOT(update()));
    this->addToGroup(this->head);

    this->prepareTimer->start(2000);
}
void Bomb::update(){

    if(!this->ready){
        this->prepareTimer->stop();
        this->head->setPixmap(QPixmap(":/Project435/images/bomb.png").scaledToHeight(60));
        this->ready = true;
    }else{

        this->step++;
        if(this->thrown){
            this->head->setPos(this->head->pos().x(), this->head->pos().y()+1);
        }
        QList<QGraphicsItem *> collidelist = this->scene()->collidingItems(this->head);
        foreach(QGraphicsItem * i , collidelist)
        {
            if (Grabbable* item = dynamic_cast<Grabbable *>(i) )
            {

                this->head->setPixmap(QPixmap(":/Project435/images/explosion.png").scaledToHeight(170));
                if(!this->grabbingItem){
                    this->head->setPos(this->head->pos().x()-50, this->head->pos().y()-30);
                }
                this->grabbingItem = true;
                item->wasShot();
                this->thrown = false;
            }
        }
        if(this->step > 350){
            delete this;
        }
    }


}