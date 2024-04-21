// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.2
import dashboard


Window {
    visible: true
    title: "dashboard"
    width: Constants.width
    height: Constants.height
    color: "#101113"

    property real defaultWidth: Constants.width  // Design resolution width
    property real defaultHeight: Constants.height // Design resolution height

    Rectangle {
        width: parent.width
        height: parent.height
        color: "#101113"

        // Scaling the content based on window size
        scale: Math.min(parent.width / defaultWidth, parent.height / defaultHeight)
        anchors.centerIn: parent

        Cluster_Art {
            anchors.centerIn: parent
        }
    }
}
