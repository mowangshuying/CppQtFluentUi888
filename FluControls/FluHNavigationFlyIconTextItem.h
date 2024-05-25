#pragma once

#include "FluWidget.h"

#include <QPainter>
#include <QStyleOption>
#include <QPaintEvent>

#include <QVBoxLayout>
#include <vector>
#include "FluVScrollView.h"

class FluHNavigationIconTextItem;
class FluHNavigationFlyIconTextItem : public FluWidget
{
    Q_OBJECT
  public:
    FluHNavigationFlyIconTextItem(QWidget* parent = nullptr);
    //~FluHNavigationFlyIconTextItem();

    void setIconTextItems(std::vector<FluHNavigationIconTextItem*> items);
    void adjustItemSize();

    // to enable qss
    void paintEvent(QPaintEvent* event)
    {
        QStyleOption opt;
        opt.initFrom(this);
        QPainter painter(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    }
  public slots:
    void onThemeChanged();

  protected:
    QVBoxLayout* m_vMainLayout;
    FluVScrollView* m_vScrollView;
    std::vector<FluHNavigationIconTextItem*> m_items;
};