#include "plotter.h"

#include <QApplication>
#include <QtWidgets>
#include "plotter.h"

#include <cmath>
#include <array>

void readFlightCurves(Plotter *plotter, const QString &fileName)
{
    const int COUNT = 6;

    //QVector<QPointF> data[6];
    double factX = 0.0013;
    //double factY[6] = { 0.0008, 0.1, 0.2, 0.2, 0.1, 0.8 };
    //double offsY[6] = { +500, -55, +309, +308, 0, 0 };
    //int pos[6] = { 3, 6, 7, 8, 9, 10 };
    QFile file(fileName);
    double offsX = 0.0;

    std::array<QVector<QPointF>, COUNT> data;
    std::array<double, COUNT> factY = { 0.0008, 0.1, 0.2, 0.2, 0.1, 0.8 };
    std::array<double, COUNT> offsY = { +500, -55, +309, +308, 0, 0 };
    std::array<int, COUNT> pos = { 3, 6, 7, 8, 9, 10 };

    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList coords = line.split(' ', Qt::SkipEmptyParts);
            if (coords.count() >= COUNT) {
                double x = factX * coords[0].toDouble();
                if (data[0].isEmpty())
                    offsX = x;
                for (int i = 0; i < COUNT; ++i) {
                    double y = coords[pos.at(i)].toDouble();
                    data.at(i).append(QPointF(x - offsX,
                            factY.at(i) * (y - offsY.at(i))));
                }
            }
        }
    }

    plotter->setCurveData(0, data[0]);
    plotter->setCurveData(1, data[1]);
    plotter->setCurveData(2, data[2]);
    plotter->setCurveData(3, data[3]);
    plotter->setCurveData(4, data[4]);
    plotter->setCurveData(5, data[5]);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Plotter plotter;
    plotter.setWindowTitle(QObject::tr("Jambi Plotter"));
    QRandomGenerator prng1(1234);
#if 0
    readFlightCurves(&plotter, ":/in1.txt");
#else
    int numPoints = 100;
    QVector<QPointF> points0;
    QVector<QPointF> points1;
    for (int x = 0; x < numPoints; ++x) {
        points0.append(QPointF(x, 45. * sin(x / 20.)));
        points1.append(QPointF(x, static_cast<int>(prng1.generate() % 100 - 50.)));
    }
    plotter.setCurveData(0, points0);
    plotter.setCurveData(1, points1);

    PlotSettings settings;
    settings.minX = 0.0;
    settings.maxX = 100.0;
    settings.minY = -50.0;
    settings.maxY = 50.0;
    plotter.setPlotSettings(settings);
#endif
    plotter.show();
    return QApplication::exec();
}
