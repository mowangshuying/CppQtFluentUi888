#pragma once

#include "FluWidget.h"
#include "FluLoopView.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "../FluUtils/FluUtils.h"
#include <QPainter>
#include <QStyleOption>
#include "FluHSplitLine.h"
#include "FluVSplitLine.h"
#include "FluDatePickerViewMask.h"
#include <QFrame>
#include <QGraphicsDropShadowEffect>

class FluDatePickerView : public FluWidget
{
    Q_OBJECT
  public:
    FluDatePickerView(QWidget* parent = nullptr);

    int getMonth();

    int getDay();

    int getYear();

    void setMonth(int month);

    void setDay(int day);

    void setYear(int year);

    void updateTime();

    int getMonthDays(int year, int month);

    void setShadowEffect();

    void paintEvent(QPaintEvent* event);

    void showEvent(QShowEvent* event);

    void resizeEvent(QResizeEvent* event);
  signals:
    void clickedOk();
    void clickedCancel();
  public slots:
    void onThemeChanged();

  protected:
    QFrame* m_mainView;
    QHBoxLayout* m_hMainViewLayout;
    QGraphicsDropShadowEffect* m_shadowEffect;

    QVBoxLayout* m_vMainLayout;
    QHBoxLayout* m_hViewLayout;
    QHBoxLayout* m_hBtnLayout;

    FluDatePickerViewMask* m_mask;
    FluLoopView* m_monthView;
    FluLoopView* m_dayView;
    FluLoopView* m_yearView;

    QPushButton* m_okBtn;
    QPushButton* m_cancelBtn;

    int m_month;
    int m_day;
    int m_year;

    bool m_bFirstShow;
};
