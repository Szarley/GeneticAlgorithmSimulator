#ifndef ENUMSTRINGMAPPER_H
#define ENUMSTRINGMAPPER_H
#include "enumtypes.h"
#include <QString>
#include <QMap>
#include <QList>

/**
 * @brief EnumParser template class singleton is used to map Enun type values to a string representation.
 */
template <typename T>
class EnumParser
{
public:
    static EnumParser<T> & instance();
    QString parse(T) const;
    QList<QString> getValues() const;
private:
    EnumParser();
    QMap<T,QString> enumMap;
};

template<typename T>
EnumParser<T> & EnumParser<T>::instance()
{
    static EnumParser<T> enumParser;
    return enumParser;
}

template<typename T>
QString EnumParser<T>::parse(T type) const
{
    return enumMap[type];
}
template<typename T>
QList<QString> EnumParser<T>::getValues() const
{
    return enumMap.values();
}

template<>
EnumParser<FinishCondition>::EnumParser()
{
    enumMap[FinishCondition::ChromosomeMajority] = "chromosome majority";
    enumMap[FinishCondition::IterationCount] = "iteration count";
}

template<>
EnumParser<MutationType>::EnumParser()
{
    enumMap[MutationType::None] = "none";
    enumMap[MutationType::ChosenBit] = "chosen bit";
    enumMap[MutationType::RandomBit] = "random bit";
}

#endif // ENUMSTRINGMAPPER_H
