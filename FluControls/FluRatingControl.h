#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include "FluStar.h"
#include "../FluUtils/FluUtils.h"
#include <QPainter>
#include <QStyleOption>
#include <QEvent>

class FluRatingControl : public QWidget
{
    Q_OBJECT
  public:
    FluRatingControl(QWidget* parent = nullptr) : QWidget(parent)
    {
        m_hMainLayout = new QHBoxLayout;
        setLayout(m_hMainLayout);

        addStar();
        setFixedSize(170, 45);
        FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluRatingControl.qss", this);
        if (FluThemeUtils::getUtils()->getTheme() == FluTheme::Dark)
        {
            FluStyleSheetUitls::setQssByFileName("../StyleSheet/dark/FluRatingControl.qss", this);
        }
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, [=](FluTheme theme) { onThemeChanged(); });
    }

    void addStar()
    {
        for (int i = 0; i < 5; i++)
        {
            auto star = new FluStar(this);
            star->installEventFilter(this);
            m_stars.push_back(star);
            m_hMainLayout->addWidget(star);
        }
    }

    int getNum()
    {
        return m_nNum;
    }

    bool eventFilter(QObject* watched, QEvent* event)
    {
        for (int i = 0; i < 5; i++)
        {
            if (m_stars[i] == watched && event->type() == QEvent::HoverEnter)
            {
                // LOG_DEBUG << i << "," <<event;
                for (int j = 0; j < 5; j++)
                {
                    if (j > i)
                    {
                        m_stars[j]->setEmptyStar();
                        continue;
                    }

                    m_stars[j]->setSolidStar();
                }
                m_nNum = i;
                break;
            }
        }

        return QWidget::eventFilter(watched, event);
    }

    void paintEvent(QPaintEvent* event)
    {
        QStyleOption opt;
        opt.initFrom(this);
        QPainter painter(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    }

    public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::getUtils()->getTheme() == FluTheme::Light)
        {
            FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluRatingControl.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("../StyleSheet/dark/FluRatingControl.qss", this);
        }
    }
  protected:
    int m_nNum;
    std::vector<FluStar*> m_stars;
    QHBoxLayout* m_hMainLayout;
};