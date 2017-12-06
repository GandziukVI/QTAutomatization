#include <QtWidgets/QApplication>
#include <QtQuick/QQuickView>
#include <QtCore/QDir>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>

#include "qmlBackEnd/NoiseFETModel.h"

int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    QQuickView viewer;

    QUrl source = QUrl("qrc:/qml/main.qml");

    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);

    viewer.setTitle(QStringLiteral("Noise FET"));

    NoiseFETModel noiseModelView;
    viewer.rootContext()->setContextProperty("noiseFETSettingsModel", &noiseModelView);
    noiseModelView.setIsOutputCurveMode(true);

    viewer.setSource(source);
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.show();

    return app.exec();
}
