#include <QtWidgets/QApplication>
#include <QtQuick/QQuickView>
#include <QtCore/QDir>
#include <QtQml/QQmlEngine>

int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    QQuickView viewer;

    QUrl source = QUrl("qrc:/qml/main.qml");

    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);

    viewer.setTitle(QStringLiteral("Noise FET"));
    viewer.setSource(source);
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.show();

    return app.exec();
}
