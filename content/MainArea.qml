import QtQuick 6.2

Rectangle {
    width: parent.width
    height: parent.height

    Text {
        text: "Hello, World!"
        anchors.centerIn: parent
    }

    Cluster_Art {
        width: parent.width * 0.5  // 50% of parent width
        height: parent.height * 0.5 // 30% of parent height
        anchors.centerIn: parent
    }
}
