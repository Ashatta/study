import QtQuick 1.0

Rectangle {
	property alias text: label.text
	property alias textColor: label.color
	color: "lightgrey"

	property int margin: 3
	width: label.width + margin * 2
	height: label.height + margin * 2

	signal click()
	
	MouseArea {
		id: area
		anchors.fill: parent

		onClicked: { color = Qt.lighter(color, 1.5); click() }
		onEntered: color = Qt.darker(color, 1.5)
	}

	Text {
		id: label
		anchors.centerIn: parent
	}
}
