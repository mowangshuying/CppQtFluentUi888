#pragma once

#include "FluNavigationItem.h"

class FluNavigationSearchItem : public FluNavigationItem
{
    Q_OBJECT
  public:
    FluNavigationSearchItem(QWidget* parent = nullptr) : FluNavigationItem(parent)
    {
    }
};