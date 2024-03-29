#include "FluNavigationSettingsItem.h"
#include "FluNavigationView.h"

FluNavigationSettingsItem::FluNavigationSettingsItem(QIcon icon, QString text, QWidget* parent /*= nullptr*/) : FluNavigationItem(parent)
{
    m_itemType = FluNavigationItemType::Setting;
    setFixedSize(320, 40);
    m_hMainLayout = new QHBoxLayout;
    setLayout(m_hMainLayout);

    m_hMainLayout->setContentsMargins(0, 4, 0, 4);

    m_indicator = new QWidget(this);
    m_icon = new FluRotationButton(this);
    m_label = new QLabel;
    m_label->setText(text);

    m_indicator->setFixedHeight(18);
    m_indicator->setFixedWidth(4);
    m_icon->setFixedSize(30, 30);
    m_label->setWordWrap(true);

    m_icon->setIconSize(QSize(24, 24));
    m_icon->setIcon(icon);

    m_indicator->setObjectName("indicator");
    m_icon->setObjectName("icon");
    m_label->setObjectName("label");

    m_hMainLayout->addSpacing(4);
    m_hMainLayout->addWidget(m_indicator);
    m_hMainLayout->addWidget(m_icon);
    m_hMainLayout->addSpacing(12);
    m_hMainLayout->addWidget(m_label, 1);
    m_hMainLayout->setSpacing(0);

    FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluNavigationSettingsItem.qss", this);
    connect(m_icon, &FluRotationButton::clicked, [=](bool b) { emit itemClicked(); });
    connect(this, &FluNavigationSettingsItem::itemClicked, this, &FluNavigationSettingsItem::onItemClicked);
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, [=](FluTheme theme) { onThemeChanged(); });
}

FluNavigationSettingsItem::FluNavigationSettingsItem(FluAwesomeType awesomeType, QString text, QWidget* parent) : FluNavigationSettingsItem(QIcon(), text, parent)
{
    m_icon->setIcon(FluIconUtils::getFluentIcon(awesomeType));
    m_icon->setAwesomeType(awesomeType);
}

void FluNavigationSettingsItem::onItemClicked()
{
    // click it and rotation it!
    m_icon->setReserveAngle(16);

    // get parent view and update select
    auto navView = getParentView();
    if (navView == nullptr)
        return;
    navView->clearAllItemsSelectState();
    updateSelected(true);
    navView->updateAllItemsStyleSheet();
}

void FluNavigationSettingsItem::onThemeChanged()
{
    if (FluThemeUtils::getUtils()->getTheme() == FluTheme::Light)
    {
        FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluNavigationSettingsItem.qss", this);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("../StyleSheet/dark/FluNavigationSettingsItem.qss", this);
    }
}
