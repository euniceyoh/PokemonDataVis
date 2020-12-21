#include "stackedbar.h"

stackedbar::stackedbar()
{

}

QChartView* stackedbar::show_bar(std::vector<character>& list_character)
{
    QStackedBarSeries *series = new QStackedBarSeries;

    // for each character in vector
    // create a barset, append data
    // series append each barset

    for(int i = 0; i < list_character.size(); i++)
    {
        character c = list_character[i];
        QBarSet *set = new QBarSet(QString::fromStdString(c.getName()));
        *set << c.getHP() << c.getAttack() << c.getDefense();
        series->append(set);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Character Points");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Hit Points" << "Attack Points" << "Defense Points";
    QBarCategoryAxis *X = new QBarCategoryAxis();
    X->append(categories);
    chart->addAxis(X, Qt::AlignBottom);
    series->attachAxis(X);

    QValueAxis *Y = new QValueAxis();
    chart->addAxis(Y, Qt::AlignLeft);
    series->attachAxis(Y);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *view = new QChartView(chart);
    return view;
}

QChartView* stackedbar:: show_bar(character& c)
{
    QStackedBarSeries *series = new QStackedBarSeries;
    QBarSet *set = new QBarSet(QString::fromStdString(c.getName()));
    *set << c.getHP() << c.getAttack() << c.getDefense();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Character Points");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Hit Points" << "Attack Points" << "Defense Points";
    QBarCategoryAxis *X = new QBarCategoryAxis();
    X->append(categories);
    chart->addAxis(X, Qt::AlignBottom);
    series->attachAxis(X);

    QValueAxis *Y = new QValueAxis();
    chart->addAxis(Y, Qt::AlignLeft);
    series->attachAxis(Y);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *view = new QChartView(chart);
    return view;
}
