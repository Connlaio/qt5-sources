/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef PatternistSDK_ASTItem_H
#define PatternistSDK_ASTItem_H

#include <QList>
#include <QString>

#include "TreeItem.h"
#include "Global.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QPatternistSDK
{
    /**
     * @short Is a node in a ASTItem tree; each ASTItem contains
     * debug information about an QPatternist::Expression.
     *
     * ASTItem, by implementing TreeItem, leverages debug data about QPatternist::Expression
     * instances into Qt's model/view framework.
     *
     * @ingroup PatternistSDK
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class Q_PATTERNISTSDK_EXPORT ASTItem : public TreeItem
    {
    public:
        virtual ~ASTItem();
        ASTItem(ASTItem *parent,
                const QString &name,
                const QString &details = QString(),
                const QString &staticType = QString(),
                const QString &reqType = QString());

        virtual void appendChild(TreeItem *item);
        virtual TreeItem *child(const unsigned int row) const;
        virtual unsigned int childCount() const;
        virtual QVariant data(const Qt::ItemDataRole role, int column) const;
        virtual TreeItem::List children() const;
        virtual TreeItem *parent() const;
        int columnCount() const;

        /**
         * Returns a string representation of this AST node, recursively including
         * children. For example, the query <tt>1 eq number()</tt> would result in the string:
         *
@verbatim
ValueComparison(eq)
  xs:integer(0)
  FunctionCall(fn:number)
    ContextItem
@endverbatim
         */
        QString toString() const;

    private:
        QString toString(const QString &indent) const;

        const QString m_name;
        const QString m_details;
        const QString m_reqType;
        const QString m_staticType;
        TreeItem::List m_children;
        TreeItem *m_parent;
    };
}

QT_END_NAMESPACE

QT_END_HEADER

#endif
// vim: et:ts=4:sw=4:sts=4
