#ifndef STACKEDBAR_H
#define STACKEDBAR_H

#include <QApplication>
#include <QtCharts/QBarSet>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include <vector>
#include "character.h"

using namespace QtCharts;
using namespace std;

class stackedbar
{
public:
    stackedbar();
    QChartView* show_bar(std::vector<character>& list_character);
    QChartView* show_bar(character& c);

};

#endif // STACKEDBAR_H
