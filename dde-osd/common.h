#ifndef COMMON_H
#define COMMON_H

#include <QPainter>
#include <QStyleOptionViewItem>
#include <QDebug>

#define Pair(x, y) QPair<QString, QString>(x, y)

static const int ImageTextItemWidth = 140;
static const int ImageTextItemHeight = 140;
static const int TextItemWidth = 200;
static const int TextItemHeight = 36;

static const QColor ItemHighlightColor = "#01bdff";

inline static void DrawImage(QPainter *painter, const QStyleOptionViewItem &option, const QPixmap &pix, bool withText = false, bool withProgress = false)
{
    const QRect rect( option.rect );
    const int yOffset = withProgress ? 30 : withText ? 20 : 40;
    painter->drawPixmap(rect.x() + (rect.width() - pix.width()) / 2, rect.y() + yOffset, pix);
}

inline static void DrawText(QPainter *painter, const QStyleOptionViewItem &option, const QString &text, QColor color = Qt::black, bool withImage = true)
{
    QRect rect( option.rect );
    if (withImage) {
        rect.setY(rect.y() + 70);
    }

    QTextOption opt;
    opt.setAlignment(Qt::AlignCenter);

    painter->setPen(color);
    painter->drawText(rect, text, opt);
}

inline static void DrawProgressBar(QPainter *painter, const QStyleOptionViewItem &option, double progress)
{
    const QRect rect( option.rect );
    const int progressBarWidth = 80;
    const int progressBarHeight = 4;
    const float radius = progressBarHeight / 2.f;

    painter->setPen(Qt::NoPen);

    QRect dest(rect.x() + (rect.width() - progressBarWidth) / 2, rect.y() + 110, progressBarWidth, progressBarHeight);
    painter->setBrush(QColor(0, 0, 0, 25));
    painter->drawRoundedRect(dest, radius, radius);

    dest.setWidth(dest.width() * progress);
    painter->setBrush(Qt::black);
    painter->drawRoundedRect(dest, radius, radius);
}

#endif // COMMON_H