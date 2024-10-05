import QtQuick
import QtQuick.Window
Window{
    id:root

    width: 800
    height: 600
    visible: true
    color: "blue"

    Rectangle{
        id: rectangle

        property bool iAmProperty: true

        signal mySignal()

        anchors.centerIn: parent

        width: 50
        height: 50

        rotation: 50
        radius: 20

        color: mouseArea.containsPress ? "red" : "magenta"

        MouseArea{
            id: mouseArea

            anchors.fill: parent

            onClicked: {
                root.test()
            }
        }
    }
    
    function test()
    {
        
    }
}
