#ifndef HOOK_H
#define HOOK_H

#include <QObject>
#include "weapon.h"

class Hook : public Weapon
{
public:
    Hook();

signals:

public slots:
    void update();

};

#endif // HOOK_H
