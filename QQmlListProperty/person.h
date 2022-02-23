#ifndef PERSON_H
#define PERSON_H

#include <QtCore>
#include <QtQuick>

class JiePerson:public QQuickItem{
    Q_OBJECT;
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(quint32 age  READ getAge  WRITE setAge NOTIFY ageChanged)
public:
    using QQuickItem::QQuickItem;
    void setName(QString name)noexcept;
    QString getName() const noexcept;
    void setAge(quint32 age) noexcept;
    quint32 getAge()const noexcept;

signals:
     void nameChanged();
     void ageChanged();

private:
     QString _name;
     quint32 _age;
};

class JieJob:public QQuickItem
{
    Q_OBJECT;
    Q_PROPERTY(QQmlListProperty<JiePerson> students READ getStudents NOTIFY studentsChanged)
 public:
    using studentListType = QList<JiePerson*>;
    Q_INVOKABLE void  append(JiePerson* student) noexcept;

    QQmlListProperty<JiePerson> getStudents() noexcept;

    static void AppenFunction(QQmlListProperty<JiePerson>*,JiePerson*) noexcept;
    static int CountFunction(QQmlListProperty<JiePerson>*)noexcept;
    static JiePerson* AtFunction(QQmlListProperty<JiePerson>*,int)noexcept;
    static void ClearFunction(QQmlListProperty<JiePerson>*)noexcept;
    static void ReplaceFunction(QQmlListProperty<JiePerson>*,int,JiePerson*)noexcept;
    static void RemoveLasetFunction(QQmlListProperty<JiePerson>*)noexcept;
signals:
    void studentsChanged();
 private:
    studentListType _students;
};

#endif // PERSON_H
