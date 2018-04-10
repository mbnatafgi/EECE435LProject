#ifndef IMMUNITYMETER_H
#define IMMUNITYMETER_H

#include <QGraphicsProxyWidget>
#include <QPen>
#include "cleanlinessmeter.h"
#include "spongeBob.h"
#include <QGraphicsScene>
#include <QTimer>
#include <pause.h>


class Header: public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    Header(SpongeBob* player, int difficulty, QString username, QString game, bool paused, int time);

    CleanlinessMeter* cleanlinessMeter;
    Pause* pause;
    QGraphicsPixmapItem* hearts[3];
    QGraphicsTextItem* timeLabel;
    QGraphicsTextItem* levelLabel;
    QGraphicsTextItem* scoreLabel;
    QGraphicsLineItem* needle;

    SpongeBob* player;
    QString username;
    QString game;
    QTimer* timer;
    int time;
    int difficulty;
    int currentBacteriaCountInScene;
    bool paused;


    void SetCleanliness(int val);
    void SetImmunity(int val);
    void SetScore(int val);
    void RemoveLife();

    void AddCleanlMeter(int x, int y);
    void AddChart(int x, int y, int width, int height, int startAngle, int spanAngle, QColor color);
    void AddHearts(int x, int y);
    void AddTime(int x, int y);
    void AddPause(int x, int y);
    void AddLevel(int x, int y);
    void AddScore(int x, int y);
    void AddNeedle(int x, int y);

    void Render();

signals:

public slots:
    void CountDown();
};

#endif // IMMUNITYMETER_H
