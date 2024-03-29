/*
 * Strawberry Music Player
 * This file was part of Clementine.
 * Copyright 2013, David Sansome <me@davidsansome.com>
 *
 * Strawberry is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Strawberry is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Strawberry.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "config.h"

#include <stdbool.h>

#include <QWidget>
#include <QSize>
#include <QStyle>
#include <QStylePainter>
#include <QtEvents>

#include "favoritewidget.h"

const int FavoriteWidget::kStarSize = 15;

FavoriteWidget::FavoriteWidget(int tab_index, bool favorite, QWidget *parent)
    : QWidget(parent),
      tab_index_(tab_index),
      favorite_(favorite),
      on_(":/icons/64x64/star.png"),
      off_(":/icons/64x64/star-grey.png"),
      rect_(0, 0, kStarSize, kStarSize) {}

void FavoriteWidget::SetFavorite(bool favorite) {

  if (favorite_ != favorite) {
    favorite_ = favorite;
    update();
    emit FavoriteStateChanged(tab_index_, favorite_);
  }

}

QSize FavoriteWidget::sizeHint() const {
  const int frame_width = 1 + style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
  return QSize(kStarSize + frame_width * 2, kStarSize + frame_width * 2);
}

void FavoriteWidget::paintEvent(QPaintEvent *e) {

  Q_UNUSED(e);

  QStylePainter p(this);

  if (favorite_) {
    p.drawPixmap(rect_, on_);
  }
  else {
    p.drawPixmap(rect_, off_);
  }

}

void FavoriteWidget::mouseReleaseEvent(QMouseEvent *e) {

  Q_UNUSED(e);

  favorite_ = !favorite_;
  update();
  emit FavoriteStateChanged(tab_index_, favorite_);

}
