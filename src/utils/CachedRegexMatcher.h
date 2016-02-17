//
// Created by Tobias Hieta on 20/08/15.
//

#ifndef KONVERGO_CACHEDREGEXMATCHER_H
#define KONVERGO_CACHEDREGEXMATCHER_H

#include <QRegExp>
#include <QVariant>
#include <QString>
#include <QHash>

typedef QPair<QRegExp, QVariant> MatcherValuePair;
typedef QList<MatcherValuePair> MatcherValueList;

class CachedRegexMatcher : public QObject
{
public:
  CachedRegexMatcher(QObject* parent = 0) : QObject(parent) {}

  bool addMatcher(const QString& pattern, const QVariant& result);
  QVariantList match(const QString& input);
  void clear();

private:
  MatcherValueList m_matcherList;
  QHash<QString, QVariantList> m_matcherCache;
};

#endif //KONVERGO_CACHEDREGEXMATCHER_H
