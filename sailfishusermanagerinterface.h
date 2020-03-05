/*
 * Copyright (c) 2020 Jolla Ltd.
 * Copyright (c) 2020 Open Mobile Platform LLC.
 *
 * All rights reserved.
 *
 * BSD 3-Clause License, see LICENSE.
 */

#ifndef SAILFISHUSERMANAGERINTERFACE_H
#define SAILFISHUSERMANAGERINTERFACE_H

#include <QString>
#include <QDBusArgument>

#define SAILFISH_USERMANAGER_DBUS_INTERFACE "org.sailfishos.usermanager"
#define SAILFISH_USERMANAGER_DBUS_OBJECT_PATH "/"

struct SailfishUserManagerEntry {
    QString user;
    QString name;
    uint uid;
};

inline QDBusArgument &operator<<(QDBusArgument &argument, const SailfishUserManagerEntry &user)
{
    argument.beginStructure();
    argument << user.user << user.name << user.uid;
    argument.endStructure();
    return argument;
}

inline const QDBusArgument &operator>>(const QDBusArgument &argument, SailfishUserManagerEntry &user)
{
    argument.beginStructure();
    argument >> user.user >> user.name >> user.uid;
    argument.endStructure();
    return argument;
}

Q_DECLARE_METATYPE(SailfishUserManagerEntry)

#endif // SAILFISHUSERMANAGERINTERFACE_H