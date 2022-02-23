#include "person.h"
#include <QQmlListProperty>


void JiePerson::setName(QString name) noexcept
{
    _name = name;
}

QString JiePerson::getName() const noexcept
{
    return _name;
}

void JiePerson::setAge(quint32 age)noexcept
{
    _age = age;
}

quint32 JiePerson::getAge() const noexcept
{
    return _age;
}


void JieJob::append(JiePerson *student) noexcept
{
    _students.append(student);
}

QQmlListProperty<JiePerson> JieJob::getStudents() noexcept
{
     return QQmlListProperty<JiePerson>(this,&_students,
                                        &JieJob::AppenFunction,
                                        &JieJob::CountFunction,
                                        &JieJob::AtFunction,
                                        &JieJob::ClearFunction
                                        );
}

void JieJob::AppenFunction(QQmlListProperty<JiePerson> *students, JiePerson *stu) noexcept
{
    static_cast<studentListType*>(students->data)->append(stu);
}

int JieJob::CountFunction(QQmlListProperty<JiePerson> *students) noexcept
{
    return static_cast<studentListType*>(students->data)->count();
}

JiePerson *JieJob::AtFunction(QQmlListProperty<JiePerson> *students, int index) noexcept
{
    return static_cast<studentListType*>(students->data)->at(index);
}

void JieJob::ClearFunction(QQmlListProperty<JiePerson> *students) noexcept
{
    static_cast<studentListType*>(students->data)->clear();
}

void JieJob::ReplaceFunction(QQmlListProperty<JiePerson> *students, int index, JiePerson *stu) noexcept
{
    static_cast<studentListType*>(students->data)->replace(index,stu);
}

void JieJob::RemoveLasetFunction(QQmlListProperty<JiePerson> *students) noexcept
{
    static_cast<studentListType*>(students->data)->pop_back();
}



