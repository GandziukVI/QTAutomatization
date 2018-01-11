function getZoomInRect(viewRect) {
    var scaleFactor = 2.0;
    return Qt.rect(viewRect.x * scaleFactor, viewRect.y * scaleFactor, viewRect.width / scaleFactor, viewRect.height / scaleFactor);
}

function getTwoPointRect(point1, point2) {
    var retRect = Qt.rect(0, 0, 0, 0);

    retRect.x = Math.min(point1.x, point2.x);
    retRect.y = Math.min(point1.y, point2.y);

    retRect.width = Math.abs(point1.x - point2.x);
    retRect.height = Math.abs(point1.y - point2.y);

    return retRect;
}
