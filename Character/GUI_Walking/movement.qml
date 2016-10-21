
// parallelanimation.qml
import QtQuick 2.5

Rectangle {
    id: root
    width: 50
    height: 50
    //manual starting position
    x: 20
    y: 20
     property int duration: 3000
    property Item programmer: programmer


    Image {
        id: front
        anchors.fill: parent
        source: "qrc:///gfx/Programmer_Front.png"

    }

    Image {
        id: left
        anchors.fill: parent
        source: "qrc:///gfx/Programmer_LookingLeft.png"

    }

    SequentialAnimation {
        id: anim
        NumberAnimation {
            target: ufo
            properties: "y"
            to: 20
            // 60% of time to travel up
            duration: root.duration*0.6
        }
        NumberAnimation {
            target: programmer
            properties: "x"
            to: 400
            // 40% of time to travel sideways
            duration: root.duration*0.4
        }
    }

    focus: true
    Keys.onUpPressed: root.y -= 10
    Keys.onDownPressed: root.y += 10
    Keys.onLeftPressed: root.x += 10
    Keys.onRightPressed: root.x -= 10

}


