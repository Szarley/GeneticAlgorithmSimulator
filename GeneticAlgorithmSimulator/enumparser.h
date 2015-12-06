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
    QString toString(T key) const;
    T toEnum(const QString value) const;
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
QString EnumParser<T>::toString(T key) const
{
    return enumMap[key];
}
template<typename T>
T EnumParser<T>::toEnum(const QString value) const
{
    return enumMap.key(value);
}
template<typename T>
QList<QString> EnumParser<T>::getValues() const
{
    return enumMap.values();
}

template<>
inline EnumParser<FinishCondition>::EnumParser()
{
    enumMap[FinishCondition::ChromosomeMajority] = "chromosome majority";
    enumMap[FinishCondition::IterationCount] = "iteration count";
}

template<>
inline EnumParser<MutationType>::EnumParser()
{
    enumMap[MutationType::None] = "none";
    enumMap[MutationType::ChosenBit] = "chosen bit";
    enumMap[MutationType::RandomBit] = "random bit";
}

template<>
inline EnumParser<SelectionType>::EnumParser()
{
    enumMap[SelectionType::RankSelection] = "rank selection";
}

#endif // ENUMSTRINGMAPPER_H
